#include<iostream>
#include<cstdlib>
#include"BinaryTree.h"
using namespace std;

int main()
{
	BinaryTree<char> BT_1('#');
	cin >> BT_1;
	cout << "��������ǰ�����:";
	BT_1.preOrder(visit);
	cout << endl;

	cout << "���������������:";
	BT_1.inOrder(visit);
	cout << endl;

	cout << "�������ĺ������:";
	BT_1.postOrder(visit);
	cout << endl;

	cout << "�������Ĳ������:";
	BT_1.levelOrder(visit);
	cout << endl;

	cout << "�������߶�Ϊ" << BT_1.Height() << " �������ڵ���Ϊ" << BT_1.Size() << endl;

	BinaryTree<char> BT_2('#');
	BT_2 = BT_1;
	cout << endl << "��������BinaryTree1���Ƹ�BinaryTree2��"<<endl<<"BinaryTree2��ǰ�����Ϊ";
	BT_2.preOrder(visit);
	cout << endl;

	cout << "BinaryTree2���������:";
	BT_1.inOrder(visit);
	cout << endl;

	BT_1.Swap();
	cout << endl << "��BinaryTree1����������������:" << endl;
	cout << "��������ǰ�����:";
	BT_1.preOrder(visit);
	cout << endl;

	cout << "���������������:";
	BT_1.inOrder(visit);
	cout << endl;

	cout << "�������ĺ������:";
	BT_1.postOrder(visit);
	cout << endl;

	cout << "�������Ĳ������:";
	BT_1.levelOrder(visit);
	cout << endl;

	BT_1.Clear();
	cout <<endl << "ɾ���������󣬶�������ǰ�����Ϊ:";
	BT_1.inOrder(visit);
	cout << endl;

	system("PAUSE");
	return 0;
}