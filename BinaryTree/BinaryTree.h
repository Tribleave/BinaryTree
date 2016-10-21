#pragma once
#include <iostream>
using namespace std;
template <class T>
struct BinTreeNode {
	T data;
	BinTreeNode<T> *leftChild, *rightChild;
	BinTreeNode() leftChild(NULL), rightChild(NULL) {};
	BinTreeNode(T x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL) :data(x), leftChild(l), rightChild(r) {};
};
template <class T>
class BinaryTree
{
private:
	enum Side {left = 0,right = 1};
protected:
	BinTreeNode<T> *root;
	T RefValue;
public:
	BinaryTree() :root(NULL) {};						//���캯��
	BinaryTree(T value) :RefValue(value),root(NULL) {};	//���캯��
	BinaryTree(BinaryTree<T> &s);						//���ƹ��캯��
	BinaryTree& operator=(BinaryTree& BT);				//���ظ�ֵ�����
	void CreateBinTree(istream& in) {					//���������Ĺ������������
		CreateBinTree(in, root);
	}
	~BinaryTree(destroy(root));							//��������
	bool IsEmpty() { return(root == NULL) ? true : false; }	//�ж������Ƿ�Ϊ��
	BinTreeNode<T> *getRoot()const { return root; }		//ȡ�����
	BinTreeNode<T> *LeftChild(BinTreeNode<T>*current){	//��������Ů
		return (current != NULL) ? current->leftChild : NULL;
	}
	BinTreeNode<T> *RightChild(BinTreeNode<T>*current){	//��������Ů
		return (current != NULL) ? current->rightChild : NULL;
	}
	int Height() { return Height(root); }				//�������߶�
	int Size() { return Size(root); }					//���ؽ����
	BinTreeNode<T> *Parent(BinTreeNode<T> *current)const { return (root==NULL||root==current)?NULL:Parent(root,current); }		//���ظ����
	void preOrder(void(*visit)(BinTreeNode<T> *p)) {	//ǰ�����
		preOrder(root, visit);
	}
	void inOrder(void(*visit)(BinTreeNode<T> *p)) {		//�������
		inOrder(root, visit);
	}
	void postOrder(void(*visit)(BinTreeNode<T> *p)) {	//�������
		postOrder(root, visit);
	}
	void levelOrder(void(*visit)(BinTreeNode<T> *p)) {	//�������
		levelOrder(root, visit);
	}
	BinTreeNode<T> *Find(T& item)const {				//����
		return (Find(root, item));
	}
	bool Insert(const T& parent, const T& item, char& s);			//������Ԫ��
	bool Swap() {										//������������
		if (IsEmpty())
			return false;
		else {
			Swap(root);
			return true;
		}
	}
	friend istream& operator >> (istream& in, BinaryTree<T>& Tree);	//��������
	friend ostream& operator << (ostream& out, BinaryTree<T>& Tree);//�������
	friend bool operator ==(const BinaryTree<T>& s, const BinaryTree<T>& t);//�������
	friend bool equal(BinTreeNode<T> *a, BinTreeNode<T>*b);			//�����
protected:
	BinTreeNode<T> *Parent(BinTreeNode<T> *subTree, BinTreeNode<T> *current)const;	//���ظ����
	int Height(BinTreeNode<T> *subTree);				//�������߶�
	int Size(BinTreeNode<T> *subTree);					//���ؽ����
	void preOrder(BinTreeNode<T>& subTree, void(*visit)(BinTreeNode<T> *p));	//ǰ�����
	void inOrder(BinTreeNode<T>& subTree, void(*visit)(BinTreeNode<T> *p));		//�������
	void postOrder(BinTreeNode<T>& subTree, void(*visit)(BinTreeNode<T> *p));	//�������
	void levelOrder(BinTreeNode<T>& subTree, void(*visit)(BinTreeNode<T> *p));	//�������
	BinTreeNode<T>*Find(BinTreeNode<T>& subTree, T& x)const;					//����
	bool Insert(const T& parent, const T& item, Side side);						//����
	BinTreeNode<T>* Copy(BinTreeNode<T>* orignode);								//����
	void CreateBinTree(istream& in, BinTreeNode<T> *&BT);						//���������Ĺ������������
	void destroy(BinTreeNode<T> *& subTree);									//ɾ��
	void Swap(BinTreeNode<T>& subTree);											//������������


};
template <class T>
void visit(BinTreeNode<T> *p) {
	cout << p.data << ' ';
}

//bool Insert(const T& parent, const T& item, char& s) {			//������Ԫ��
//	if (Find(root, parent)) {
//		if (s == 'l') {
//			Side side = left;
//			return(Insert(parent, item, side));
//		}
//		else if (s == 'r') {
//			Side side = right;
//			return(Insert(parent, item, side));
//		}
//		else
//			return false;
//	}
//	return false;
//}