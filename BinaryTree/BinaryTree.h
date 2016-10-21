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
	BinaryTree() :root(NULL) {};						//构造函数
	BinaryTree(T value) :RefValue(value),root(NULL) {};	//构造函数
	BinaryTree(BinaryTree<T> &s);						//复制构造函数
	BinaryTree& operator=(BinaryTree& BT);				//重载赋值运算符
	void CreateBinTree(istream& in) {					//从输入流的广义表建立二叉树
		CreateBinTree(in, root);
	}
	~BinaryTree(destroy(root));							//析构函数
	bool IsEmpty() { return(root == NULL) ? true : false; }	//判二叉树是否为空
	BinTreeNode<T> *getRoot()const { return root; }		//取根结点
	BinTreeNode<T> *LeftChild(BinTreeNode<T>*current){	//返回左子女
		return (current != NULL) ? current->leftChild : NULL;
	}
	BinTreeNode<T> *RightChild(BinTreeNode<T>*current){	//返回右子女
		return (current != NULL) ? current->rightChild : NULL;
	}
	int Height() { return Height(root); }				//返回树高度
	int Size() { return Size(root); }					//返回结点数
	BinTreeNode<T> *Parent(BinTreeNode<T> *current)const { return (root==NULL||root==current)?NULL:Parent(root,current); }		//返回父结点
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
	friend istream& operator >> (istream& in, BinaryTree<T>& Tree);	//重载输入
	friend ostream& operator << (ostream& out, BinaryTree<T>& Tree);//重载输出
	friend bool operator ==(const BinaryTree<T>& s, const BinaryTree<T>& t);//重载相等
	friend bool equal(BinTreeNode<T> *a, BinTreeNode<T>*b);			//判相等
protected:
	BinTreeNode<T> *Parent(BinTreeNode<T> *subTree, BinTreeNode<T> *current)const;	//返回父结点
	int Height(BinTreeNode<T> *subTree);				//返回树高度
	int Size(BinTreeNode<T> *subTree);					//返回结点数
	void preOrder(BinTreeNode<T>& subTree, void(*visit)(BinTreeNode<T> *p));	//前序遍历
	void inOrder(BinTreeNode<T>& subTree, void(*visit)(BinTreeNode<T> *p));		//中序遍历
	void postOrder(BinTreeNode<T>& subTree, void(*visit)(BinTreeNode<T> *p));	//后序遍历
	void levelOrder(BinTreeNode<T>& subTree, void(*visit)(BinTreeNode<T> *p));	//层序遍历
	BinTreeNode<T>*Find(BinTreeNode<T>& subTree, T& x)const;					//搜索
	bool Insert(const T& parent, const T& item, Side side);						//插入
	BinTreeNode<T>* Copy(BinTreeNode<T>* orignode);								//复制
	void CreateBinTree(istream& in, BinTreeNode<T> *&BT);						//从输入流的广义表建立二叉树
	void destroy(BinTreeNode<T> *& subTree);									//删除
	void Swap(BinTreeNode<T>& subTree);											//交换左右子树


};
template <class T>
void visit(BinTreeNode<T> *p) {
	cout << p.data << ' ';
}

//bool Insert(const T& parent, const T& item, char& s) {			//插入新元素
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