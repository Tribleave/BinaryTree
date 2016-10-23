#pragma once
#include "..\BinaryTree\BinaryTree.h"
#include <string>
#include <algorithm>
template <class T>
struct HfmCode {
	T ch;
	string code;
};
template <class T>
class HfmTree:public BinaryTree<T>
{
public:
	void Build();
	void SetNull() {root = NULL; }
	void SetWeight(const int& w) { root->weight = w; }
	T getWeight() { return root->weight; }
protected:
	T NonleafValue;
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