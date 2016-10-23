#pragma once
#include "..\BinaryTree\BinaryTree.h"
#include "PrioQueue.h"
#include <string>
#include <algorithm>
#include <sstream>
template <class T>
struct HfmCode {
	T ch;
	string code;
};
template <class T>
class HfmTree:public BinaryTree<T>
{
public:
	bool operator <(HfmTree<T>& t) { return root->weight < t.root->weight; }
	bool operator <=(HfmTree<T>& t) { return root->weight <= t.root->weight; }
	bool operator >(HfmTree<T>& t) { return root->weight > t.root->weight; }
	bool operator >=(HfmTree<T>& t) { return root->weight >= t.root->weight; }
	bool operator ==(HfmTree<T>& t) { return root->weight == t.root->weight; }
	bool operator !=(HfmTree<T>& t) { return root->weight != t.root->weight; }
	HfmTree() :BinaryTree<T>(), codeArray(NULL) {};
	~HfmTree() { destroy(root); }
	HfmTree(T value) :BinaryTree<T>(),NonleafValue(value), codeArray(NULL) {};
	HfmTree(HfmTree<T>& s);
	HfmTree<T>& operator= (const HfmTree& BT);
	void MakeTree(const T & x, HfmTree<T>& leftTree, HfmTree<T>& rightTree);
	bool IsCoded()const { return codeArray != NULL; }
	void Create(T* ch, int* w,int n);
	void EnCode();
	void EnCode(ostream& out);
	void PrintCode(ostream& out);
	void Code (istream& in, ostream& out);
	void DeCode (istream& in, ostream& out);
	int getWeight() { return root->weight; }
protected:
	int binarySearch(const T& x);
	static bool comp(const HfmCode<T>& a, const HfmCode<T>& b) {
		return a.ch < b.ch;
	}
	void EnCode(BinTreeNode<T>*& subTree, string s);
	void SetNull() { root = NULL; }
	void SetWeight(const int w) { root->weight = w; }
	void SetRoot(const T item, const int w = 0) { 
		if (root != NULL)	destroy(root);
		root = new BinTreeNode<T>(w, item);
	}
	T NonleafValue;
	int codeNum;
	int leaf;
	HfmCode<T>* codeArray;
};
template <class T>
void visitHfm(BinTreeNode<T> *p) {
	if (p->leftChild == NULL && p->rightChild == NULL)
		cout << p->data << ":" << p->weight << ' ';
	else
		cout << p->weight << ' ';
}

template<class T>
HfmTree<T>::HfmTree(HfmTree<T>& s)
{
	root = Copy(s.root);
	RefValue = s.RefValue;
	NonleafValue = s.NonleafValue;
	leaf = s.leaf;
	if (s.IsCoded()) {
		codeArray = new HfmCode<T>[leaf];
		for (int index = 0; index < leaf; index++)
			codeArray[index] = s.codeArray[index];
	}
	else codeArray = NULL;
}
template<class T>
HfmTree<T>& HfmTree<T>::operator=(const HfmTree & BT)
{
	if (this != &BT) {
		root = Copy(BT.root);
		RefValue = BT.RefValue;
		NonleafValue = BT.NonleafValue;
		leaf = BT.leaf;
		if (BT.IsCoded()) {
			codeArray = new HfmCode<T>[leaf];
			for (int index = 0; index < leaf; index++)
				codeArray[index] = BT.codeArray[index];
		}
		else
			codeArray = NULL;
	}
	return *this;
}
template<class T>
void HfmTree<T>::MakeTree(const T & x, HfmTree<T>& leftTree, HfmTree<T>& rightTree)
{
	if (root != NULL || &leftTree == &rightTree)	return;
	root = new BinTreeNode<T>(leftTree.getWeight() + rightTree.getWeight(), x, leftTree.root, rightTree.root);
	leftTree.root = rightTree.root = NULL;
}
template<class T>
void HfmTree<T>::Create(T * ch, int * w,int n)
{
	if (codeArray != NULL) {
		delete[]codeArray;
		codeArray = NULL;
	}
	leaf = n;
	HfmTree<T> temp,x,y,z;
	PriorityQueue<HfmTree<T>> pq(n);
	for (int index = 0; index < n; index++) {
		temp.SetRoot(ch[index], w[index]);
		pq.Append(temp);
		temp.SetNull();
	}
	for (int index = 1; index < n; index++) {
		pq.Serve(x);
		pq.Serve(y);
		z.MakeTree(NonleafValue,x, y);
		pq.Append(z);
		z.SetNull();
	}
	pq.Serve(temp);
	root = temp.root;
	temp = NULL;
}
template<class T>
void HfmTree<T>::EnCode()
{
	stringstream emptySS;
	EnCode(emptySS);
}
template<class T>
void HfmTree<T>::EnCode(ostream & out)
{
	if (IsCoded())	return;
	codeArray = new HfmCode<T>[leaf];
	codeNum = 0;
	string s = "";
	EnCode(root, s);
	sort(codeArray, codeArray + leaf, comp);
	for (int index = 0; index < leaf; index++)
		out << codeArray[index].ch << ' ' << codeArray[index].code << endl;
}
template<class T>
void HfmTree<T>::PrintCode(ostream& out)
{
	if (!IsCoded())	return;
	for (int index = 0; index < leaf; index++)
		out << codeArray[index].ch << ' ' << codeArray[index].code << endl;
}
template<class T>
void HfmTree<T>::EnCode(BinTreeNode<T>*& subTree, string s)
{
	if (subTree->IsLeaf()) {
		codeArray[codeNum].ch = subTree->data;
		codeArray[codeNum].code = s;
		codeNum++;
		return;
	}
	string sl = s + "0";
	EnCode(subTree->leftChild, sl);
	string sr = s + "1";
	EnCode(subTree->rightChild, sr);
}
template<class T>
int HfmTree<T>::binarySearch(const T& x)
{
	int head = 0, tail = leaf - 1, mid;
	while (head <= tail) {
		mid = head + (tail - head) / 2;
		if (codeArray[mid].ch == x)
			return mid;
		else if (codeArray[mid].ch < x)
			head = mid + 1;
		else
			tail = mid - 1;
	}
	return -1;
}
template<class T>
void HfmTree<T>::Code(istream& in, ostream & out)
{
	if (!IsCoded())	return;
	T ch;
	int position;
	while (in.peek()!=EOF) {
		in >> ch;
		position = binarySearch(ch);
		if (position == -1)
			return;
		out << codeArray[position].code;
	}
}
template<class T>
void HfmTree<T>::DeCode(istream & in, ostream & out)
{
	if (!IsCoded())	return;
	BinTreeNode<T>* pt = root;
	char ch;
	while (in.peek()!=EOF) {
		while (!pt->IsLeaf() && in.peek()!=EOF) {
			if (pt == NULL)	return;
			in >> ch;
			if (ch == '0')	pt = pt->leftChild;
			else if (ch == '1')	pt = pt->rightChild;
			else return;
		}
		if (pt->IsLeaf())	out << (pt->data);
		pt = root;
	}
	pt = NULL;
}
