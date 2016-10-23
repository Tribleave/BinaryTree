#pragma once
#include "BinTreeNode.h"
#include <iostream>
#include <queue>	//STL queue
#include <stack>	//STL stack
using namespace std;
template <class T>
class BinaryTree
{
private:
	enum Side { left = 0, right = 1 };
protected:
	BinTreeNode<T> *root;
	T RefValue;
public:
	BinaryTree() :root(NULL) {};						//构造函数
	BinaryTree(T value) :RefValue(value), root(NULL) {};//构造函数
	BinaryTree(BinaryTree<T> &s);						//复制构造函数
	BinaryTree& operator= (const BinaryTree& BT);			//重载赋值运算符
	void MakeTree(const T& x, BinaryTree<T>& leftTree, BinaryTree<T>& rightTree);	//合并两棵二叉树
	void BreakTree(T& x, BinaryTree<T>& leftTree, BinaryTree<T>& rightTree);			//拆分二叉树

	void CreateBinTree(istream& in,int s=0) {				//建立二叉树
		if(s == 0)
			CreateBinTreeByPreorder(in, root);
		if (s == 1)
			CreateBinTreeByList(in, root);
	}
	void CreateBinTree(T * VLR, T *LVR, int n) {
		root = CreateBinTreeByPreIn(VLR, LVR, n);
	}
	~BinaryTree() { destroy(root); }						//析构函数
	bool IsEmpty() { return(root == NULL) ? true : false; }	//判二叉树是否为空
	BinTreeNode<T> *getRoot()const { return root; }		//取根结点
	BinTreeNode<T> *LeftChild(BinTreeNode<T>*current) {	//返回左子女
		return (current != NULL) ? current->leftChild : NULL;
	}
	BinTreeNode<T> *RightChild(BinTreeNode<T>*current) {	//返回右子女
		return (current != NULL) ? current->rightChild : NULL;
	}
	int Height() { return Height(root); }				//返回树高度
	int Size() { return Size(root); }					//返回结点数
	BinTreeNode<T> *Parent(BinTreeNode<T> *current)const { return (root == NULL || root == current) ? NULL : Parent(root, current); }		//返回父结点
	void preOrder(void(*visit)(BinTreeNode<T> *p)) {	//前序遍历
		preOrder(root, visit);
	}
	void inOrder(void(*visit)(BinTreeNode<T> *p)) {		//中序遍历
		inOrder(root, visit);
	}
	void postOrder(void(*visit)(BinTreeNode<T> *p)) {	//后序遍历
		postOrder(root, visit);
	}
	void levelOrder(void(*visit)(BinTreeNode<T> *p)) {	//层序遍历
		levelOrder(root, visit);
	}
	BinTreeNode<T> *Find(T& item)const {				//搜索
		return (Find(root, item));
	}
	bool Insert(const T& parent, const T& item, char& s);			//插入新元素
	bool Swap() {										//交换左右子树
		if (IsEmpty())
			return false;
		else {
			Swap(root);
			return true;
		}
	}
	void Clear() { destroy(root); }						//删除二叉树
	template <class TypeName> friend istream& operator >> (istream& in, BinaryTree<TypeName>& Tree);	//重载输入
	template <class TypeName> friend ostream& operator << (ostream& out, BinaryTree<TypeName>& Tree);//重载输出
	friend bool operator ==(const BinaryTree<T>& s, const BinaryTree<T>& t);//重载相等
	friend bool equal(BinTreeNode<T> *a, BinTreeNode<T>*b);			//判相等
protected:
	typedef void(*visit)(BinTreeNode<T> *p);
	BinTreeNode<T> *Parent(BinTreeNode<T> *subTree, BinTreeNode<T> *current)const;	//返回父结点
	int Height(BinTreeNode<T> *subTree);				//返回树高度
	int Size(BinTreeNode<T> *subTree);					//返回结点数
	void Traverse(BinTreeNode<T>* subTree, ostream& out);						//前序遍历输出
	void preOrder(BinTreeNode<T>* subTree, void(*visit)(BinTreeNode<T> *p));	//前序遍历
	void inOrder(BinTreeNode<T>* subTree, void(*visit)(BinTreeNode<T> *p));		//中序遍历
	void postOrder(BinTreeNode<T>* subTree, void(*visit)(BinTreeNode<T> *p));	//后序遍历
	void levelOrder(BinTreeNode<T>* subTree, void(*visit)(BinTreeNode<T> *p));	//层序遍历
	BinTreeNode<T>*Find(BinTreeNode<T>* subTree, T& x)const;					//搜索
	bool Insert(const BinTreeNode<T>* subTree, const T& item, Side side);		//插入
	BinTreeNode<T>* Copy(BinTreeNode<T>* orignode);								//复制
	void CreateBinTreeByList(istream& in, BinTreeNode<T> *&BT);						//从输入流的广义表建立二叉树
	void CreateBinTreeByPreorder(istream& in, BinTreeNode<T> *&BT);						//利用先序遍历序列建立二叉树
	BinTreeNode<T>* CreateBinTreeByPreIn(T * VLR, T *LVR, int n);						//利用前序序列和中序序列建立二叉树
	void destroy(BinTreeNode<T> *& subTree);										//删除
	void Swap(BinTreeNode<T>* subTree);											//交换左右子树

};
template <class T>
void visit(BinTreeNode<T> *p) {
	cout << p->data << ' ';
}


#include "BinaryTree.h"
template<class T>
BinTreeNode<T>* BinaryTree<T>::Parent(BinTreeNode<T>* subTree, BinTreeNode<T>* current) const
{
	if (subTree == NULL)
		return NULL;
	if (subTree->leftChild == current || subTree->rightChild == current)
		return subTree;
	BinTreeNode<T> *p;
	if ((p = Parent(subTree->leftChild, current)) != NULL)	return p;
	else return Parent(subTree->rightChild, current);
}
template <class T>
void BinaryTree<T>::destroy(BinTreeNode<T>*& subTree)
{
	if (subTree != NULL) {
		destroy(subTree->leftChild);
		destroy(subTree->rightChild);
		delete  subTree;
		subTree = NULL;
	}
}
template<class T>
void BinaryTree<T>::MakeTree(const T & x, BinaryTree<T>& leftTree, BinaryTree<T>& rightTree)
{
	if (root != NULL || &leftTree == &rightTree)	return;
	root = new BinTreeNode<T>(x, leftTree.root, rightTree.root);
	leftTree.root = rightTree.root = NULL;
}
template<class T>
void BinaryTree<T>::BreakTree(T & x, BinaryTree<T>& leftTree, BinaryTree<T>& rightTree)
{
	if (root == NULL || &leftTree == &rightTree || leftTree.root != NULL || rightTree.root != NULL)	return;
	x = root->data;
	leftTree.root = root->leftChild;
	rightTree.root = root->rightChild;
	delete root;
	root = NULL;
}
template<class T>
istream &operator >> (istream& in, BinaryTree<T>& Tree) {
	Tree.CreateBinTreeByPreorder(in, Tree.root);
	return in;
}
template<class T>
ostream & operator << (ostream& out, BinaryTree<T>& Tree) {
	Tree.Traverse(Tree.root, out);
	out << endl;
	return out;
}
template<class T>
void BinaryTree<T>::Traverse(BinTreeNode<T>* subTree, ostream & out)
{
	if (subTree != NULL) {
		out << subTree->data << ' ';
		Traverse(subTree->leftChild, out);
		Traverse(subTree->rightChild, out);
	}
}
template <class T>
void BinaryTree<T>::preOrder(BinTreeNode<T>* subTree, void(*visit)(BinTreeNode<T> *p))
{
	if (subTree != NULL) {
		visit(subTree);
		preOrder(subTree->leftChild, visit);
		preOrder(subTree->rightChild, visit);
	}
}
template<class T>
void BinaryTree<T>::inOrder(BinTreeNode<T>* subTree, void(*visit)(BinTreeNode<T>*p))
{
	if (subTree != NULL) {
		inOrder(subTree->leftChild, visit);
		visit(subTree);
		inOrder(subTree->rightChild, visit);
	}
}
template<class T>
void BinaryTree<T>::postOrder(BinTreeNode<T>* subTree, void(*visit)(BinTreeNode<T>*p))
{
	if (subTree != NULL) {
		postOrder(subTree->leftChild, visit);
		postOrder(subTree->rightChild, visit);
		visit(subTree);
	}
}
template<class T>
void BinaryTree<T>::levelOrder(BinTreeNode<T>* subTree, void(*visit)(BinTreeNode<T>*p))
{
	queue<BinTreeNode<T>*> Q;
	BinTreeNode<T> *p = root;
	Q.push(p);
	while (!Q.empty()) {
		p = Q.front();
		visit(p);
		Q.pop();
		if (p->leftChild != NULL) Q.push(p->leftChild);
		if (p->rightChild != NULL)	Q.push(p->rightChild);
	}
}
template <class T>
bool operator == (const BinaryTree<T>& s, const BinaryTree<T>& t) {
	return equal(s.root, t.root);
}
template <class T>
bool equal(BinTreeNode<T>* a, BinTreeNode<T>* b) {
	if (a == NULL && b == NULL)
		return true;
	if (a != NULL && b != NULL && a->data == b->data && equal(a->leftChild, b->leftChild) && equal(a->rightChild, b->rightChild))
		return true;
	else
		return false;
}
template<class T>
void BinaryTree<T>::Swap(BinTreeNode<T>* subTree)
{
	if (subTree != NULL) {
		BinTreeNode<T>* temp = subTree->leftChild;
		subTree->leftChild = subTree->rightChild;
		subTree->rightChild = temp;
	}
}
template<class T>
int BinaryTree<T>::Height(BinTreeNode<T>* subTree)
{
	if (subTree == NULL)	return 0;
	else {
		int Hl = Height(subTree->leftChild);
		int Hr = Height(subTree->rightChild);
		return ((Hl > Hr) ? Hl : Hr) + 1;
	}
}
template<class T>
int BinaryTree<T>::Size(BinTreeNode<T>* subTree)
{
	if (subTree == NULL)	return 0;
	return Size(subTree->leftChild) + Size(subTree->rightChild) + 1;
}
template<class T>
BinTreeNode<T>* BinaryTree<T>::Find(BinTreeNode<T>* subTree, T & x) const
{
	if (subTree == NULL)	return NULL;
	BinTreeNode<T>* p = Find(subTree->leftChild, x);
	BinTreeNode<T>* q = Find(subTree->rightChild, x);
	if (p != NULL)	return p;
	else if (q != NULL)	return q;
	else return NULL;
}
template <class T>
bool BinaryTree<T>::Insert(const T& parent, const T& item, char& s)
{
	BinTreeNode<T>* parentNode = Find(root, parent);
	if (parentNode != NULL) {
		if (s == 'l') {
			Side side = left;
			return(Insert(parentNode, item, side));
		}
		else if (s == 'r') {
			Side side = right;
			return(Insert(parentNode, item, side));
		}
		else
			return false;
	}
	return false;
}
template<class T>
bool BinaryTree<T>::Insert(const BinTreeNode<T>* subTree, const T & item, Side side)
{
	BinTreeNode<T>* Child;
	Child = new BinTreeNode<T>(item);
	if (side == left && subTree->leftChild == NULL) {
		subTree->leftChild = Child;
		return true;
	}
	if (side == right && subTree->rightChild == NULL) {
		subTree->rightChild = Child;
		return true;
	}
	return false;
}
template<class T>
BinTreeNode<T>* BinaryTree<T>::Copy(BinTreeNode<T>* orignode)
{
	if (orignode == NULL) return NULL;
	BinTreeNode<T>* subTree = new BinTreeNode<T>(orignode->weight,orignode->data);
	subTree->leftChild = Copy(orignode->leftChild);
	subTree->rightChild = Copy(orignode->rightChild);
	return subTree;
}
template<class T>
BinaryTree<T>::BinaryTree(BinaryTree<T>& s)
{
	root = Copy(s.root);
	RefValue = s.RefValue;
}
template<class T>
BinaryTree<T>& BinaryTree<T>::operator = (const BinaryTree & BT)
{
	if (this != &BT) {
		this->root = Copy(BT.root);
		this->RefValue = BT.RefValue;
	}
	return *this;
}
template<class T>
void BinaryTree<T>::CreateBinTreeByList(istream & in, BinTreeNode<T>*& BT)
{
	destroy(BT);
	stack<BinTreeNode<char> *>s;
	BT = NULL;
	BinTreeNode<char> *p, *t;
	int k;
	char x;
	in >> x;
	while (x != RefValue) {
		switch (x) {
		case '(':
			s.push(p);
			k = 1;
			break;
		case ')':
			t = s.top();
			s.pop();
			break;
		case',':
			k = 2;
			break;
		default:
			p = new BinTreeNode<char>(x);
			if (BT == NULL)
				BT = p;
			else if (k == 1) {
				t = s.top();
				t->leftChild = p;
			}
			else {
				t = s.top();
				t->rightChild = p;
			}
		}
		in >> x;
	}
}
template<class T>
void BinaryTree<T>::CreateBinTreeByPreorder(istream & in, BinTreeNode<T>*& BT)
{
	destroy(BT);
	T item;
	if (!in.eof()) {
		in >> item;
		if (item != RefValue) {
			BT = new BinTreeNode<T>(item);
			if (BT == NULL) {
				cerr << "内存分配错!" << endl;
				exit(1);
			}
			CreateBinTreeByPreorder(in, BT->leftChild);
			CreateBinTreeByPreorder(in, BT->rightChild);
		}
		else BT = NULL;
	}
}
template<class T>
BinTreeNode<T>* BinaryTree<T>::CreateBinTreeByPreIn(T * VLR, T * LVR, int n)//前序序列VLR,中序序列LVR
{
	if (n == 0)	return NULL;
	int k = 0;
	while (VLR[0] != LVR[k])	k++;
	BinTreeNode<T>* t = new BinTreeNode<T>(VLR[0]);
	t->leftChild = CreateBinTreeByPreIn(VLR + 1, LVR, k);
	t->rightChild = CreateBinTreeByPreIn(VLR + k + 1; LVR + k + 1, n - k - 1);
	return t;
}