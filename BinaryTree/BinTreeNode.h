#pragma once
template <class T>
struct BinTreeNode {
	T data;
	T weight;
	BinTreeNode<T> *leftChild, *rightChild;
	BinTreeNode() :leftChild(NULL), rightChild(NULL) {};
	BinTreeNode(T x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL) :data(x), leftChild(l), rightChild(r) {};
	BinTreeNode(T weight,T x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL) :weight(w), data(x), leftChild(l), rightChild(r) {};
};