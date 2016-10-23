#include "menu.h"

int menu(HfmTree<char>& HfmT)
{
	while (true) {
		cout << "****************************************************************" << endl;
		cout << endl;
		cout << "		      哈夫曼编码与译码系统				    " << endl;
		cout << endl;
		cout << "****************************************************************" << endl;
		cout << "  B-建树：输入字符数量、字符集和各字符频度，建立哈夫曼树	 " << endl<<endl;
		cout << "  T-遍历：先序和中序遍历二叉树							 " << endl << endl;
		cout << "  E-生成编码：根据已建成的哈夫曼树，产生各字符的哈夫曼编码	" << endl << endl;
		cout << "  C-编码：输入由字符集组成的任意字符集，编码后输出并保存,输入字" << endl;
		cout << "	  符串及其编码结果分别保存在textfile.txt和codefile.txt" << endl << endl;
		cout << "  D-译码:读入codefile.txt,利用哈夫曼树译码并存入result.txt " << endl << endl;
		cout << "  P-打印:屏幕显示文件textfile.txt、codefile.txt和result.txt" << endl << endl;
		cout << "  N-退出此次操作											  " << endl;
		cout << "*****************************************************************" << endl;
		char choice;
		int choose = 0;
		while (!choose) {
			cout << "请输入想要进行的操作：";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> choice;
			switch (choice) {
			case 'B':
			case 'b':
				system("cls");
				BuildHfmTree(HfmT);
				choose = 1;
				break;
			case'T':
			case't':
				system("cls");
				TraverseHfmTree(HfmT);
				choose = 1;
				break;
			case'E':
			case'e':
				system("cls");
				Encode(HfmT);
				choose = 1;
				break;
			case'C':
			case'c':
				system("cls");
				Code(HfmT);
				choose = 1;
				break;
			case'D':
			case'd':
				system("cls");
				Decode(HfmT);
				choose = 1;
				break;
			case'P':
			case'p':
				system("cls");
				Print(HfmT);
				choose = 1;
				break;
			case'N':
			case'n':
				int choice = 0;
				while (!choice)
				{
					printf("是否重新开始进行哈夫曼编码？(Y/N/B)");
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					char exit;
					cin >> exit;
					switch (exit)
					{
					case'Y':
					case'y':
						return 1;
					case'N':
					case'n':
						return 0;
					case'B':
					case'b':
						choice = 1;
						break;
					}
				}
				break;
			}
		}
	}
}

bool BuildHfmTree(HfmTree<char>& HfmT)
{
	return false;
}

bool TraverseHfmTree(HfmTree<char>& HfmT)
{
	return false;
}

bool Encode(HfmTree<char>& HfmT)
{
	return false;
}

bool Code(HfmTree<char>& HfmT)
{
	return false;
}

bool Decode(HfmTree<char>& HfmT)
{
	return false;
}

bool Print(HfmTree<char>& HfmT)
{
	return false;
}
