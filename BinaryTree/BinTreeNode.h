#pragma once
#include<iostream>
using namespace std;
template <class T>
struct BinTreeNode {
	T data;
	int weight;
	BinTreeNode<T> *leftChild, *rightChild;
	BinTreeNode() :leftChild(NULL), rightChild(NULL) {};
	BinTreeNode(T x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL) :data(x), leftChild(l), rightChild(r) {};
	BinTreeNode(int w,T x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL) :weight(w), data(x), leftChild(l), rightChild(r) {};
	bool IsLeaf()const {
		return (leftChild == NULL && rightChild == NULL);
	}
};