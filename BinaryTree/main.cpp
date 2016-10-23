#include<iostream>
#include<cstdlib>
#include"BinaryTree.h"
using namespace std;

int main()
{
	BinaryTree<char> BT_1('#');
	cin >> BT_1;
	cout << "二叉树的前序遍历:";
	BT_1.preOrder(visit);
	cout << endl;

	cout << "二叉树的中序遍历:";
	BT_1.inOrder(visit);
	cout << endl;

	cout << "二叉树的后序遍历:";
	BT_1.postOrder(visit);
	cout << endl;

	cout << "二叉树的层序遍历:";
	BT_1.levelOrder(visit);
	cout << endl;

	cout << "二叉树高度为" << BT_1.Height() << " 二叉树节点数为" << BT_1.Size() << endl;

	BinaryTree<char> BT_2('#');
	BT_2 = BT_1;
	cout << endl << "将二叉树BinaryTree1复制给BinaryTree2后"<<endl<<"BinaryTree2的前序遍历为";
	BT_2.preOrder(visit);
	cout << endl;

	cout << "BinaryTree2的中序遍历:";
	BT_1.inOrder(visit);
	cout << endl;

	BT_1.Swap();
	cout << endl << "将BinaryTree1的左右子树交换后:" << endl;
	cout << "二叉树的前序遍历:";
	BT_1.preOrder(visit);
	cout << endl;

	cout << "二叉树的中序遍历:";
	BT_1.inOrder(visit);
	cout << endl;

	cout << "二叉树的后序遍历:";
	BT_1.postOrder(visit);
	cout << endl;

	cout << "二叉树的层序遍历:";
	BT_1.levelOrder(visit);
	cout << endl;

	BT_1.Clear();
	cout <<endl << "删除二叉树后，二叉树的前序遍历为:";
	BT_1.inOrder(visit);
	cout << endl;

	system("PAUSE");
	return 0;
}