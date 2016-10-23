#include "menu.h"
#include <fstream>
#include <cstdlib>
int menu(HfmTree<char>& HfmT)
{
	while (true) {
		cout << "****************************************************************" << endl;
		cout << "*                                                              *"<<endl;
		cout << "*		      哈夫曼编码与译码系统		       *" << endl;
		cout << "*                                                              *" << endl;
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
			cin >> choice;
			switch (choice) {
			case 'B':
			case 'b':
				system("cls");
				BuildHfmTree(HfmT);
				choose = 1;
				system("cls");
				break;
			case'T':
			case't':
				system("cls");
				TraverseHfmTree(HfmT);
				choose = 1;
				system("cls");
				break;
			case'E':
			case'e':
				system("cls");
				Encode(HfmT);
				choose = 1;
				system("cls");
				break;
			case'C':
			case'c':
				system("cls");
				Code(HfmT);
				choose = 1;
				system("cls");
				break;
			case'D':
			case'd':
				system("cls");
				Decode(HfmT);
				choose = 1;
				system("cls");
				break;
			case'P':
			case'p':
				system("cls");
				Print(HfmT);
				choose = 1;
				system("cls");
				break;
			case'N':
			case'n':
				int choice = 0;
				while (!choice)
				{
					printf("是否重新开始哈夫曼编码？(Y/N/B)");
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
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}

bool BuildHfmTree(HfmTree<char>& HfmT)
{
	if (HfmT.getRoot() != NULL) {
		cout << "哈夫曼树已经创建，将返回目录" << endl;
		system("PAUSE");
		return false;
	}
	int n;
	int *num;
	char* ch;
	cout << "请输入字符集数量:";
	cin >> n;
	num = new int[n];
	ch = new char[n];
	cout << "请输入字符集：	  ";
	for (int index = 0; index < n; index++)
		cin >> ch[index];
	cout << "请输入各字符频度：";
	for (int index = 0; index < n; index++)
		cin >> num[index];
	HfmT.Create(ch, num, n);
	cout <<  "哈夫曼树创建成功" << endl << endl ;
	system("PAUSE");
	return true;
}

bool TraverseHfmTree(HfmTree<char>& HfmT)
{
	if (HfmT.getRoot() == NULL) {
		cout << "哈夫曼树为空，将返回目录" << endl;
		system("PAUSE");
		return false;
	}
	cout << "哈夫曼树前序遍历为:";
	HfmT.preOrder(visitHfm);
	cout << endl << "哈夫曼树中序遍历为:";
	HfmT.inOrder(visitHfm);
	cout << endl << endl;
	system("PAUSE");
	return true;
}

bool Encode(HfmTree<char>& HfmT)
{
	if (HfmT.getRoot() == NULL) {
		cout << "哈夫曼树未创建，将返回目录" << endl;
		system("PAUSE");
		return false;
	}
	if (HfmT.IsCoded()) {
		cout << "哈夫曼树已编码..." << endl;
		char ch;
		while (true) {
			cout << "是否输出编码结果？(Y/N)";
			cin >> ch;
			switch (ch)
			{
			case'Y':
			case'y':
				HfmT.PrintCode(cout);
				cout << endl;
				system("PAUSE");
				return false;
			case'N':
			case'n':
				cout << "将返回目录" << endl << endl;
				system("PAUSE");
				return false;
			}
		}
	}
	char ch=0;
	while (true) {
		cout << "是否输出编码结果？(Y/N)";
		cin >> ch;
		switch (ch)
		{
		case'Y':
		case'y':
			cout << "生成编码中..." << endl;
			HfmT.EnCode(cout);
			cout <<  "编码完成！" << endl << endl;
			system("PAUSE");
			return true;
		case'N':
		case'n':
			cout << "生成编码中..." << endl;
			HfmT.EnCode();
			cout  << "编码完成！" << endl << endl;
			system("PAUSE");
			return true;
		}
	}
	return false;
}

bool Code(HfmTree<char>& HfmT)
{
	if (!HfmT.IsCoded()) {
		cout << "哈夫曼树未完成编码，将返回目录" << endl;
		system("PAUSE");
		return false;
	}
	fstream _file;
	_file.open("textfile.txt", ios::in);
	if (_file) {
		bool ex = 1;
		char ch;
		while (ex) {
			cout << "已有文件存在，是否继续？(Y/N)";
			cin >> ch;
			switch (ch)
			{
			case'Y':
			case'y':
				ex = 0;
				break;
			case'N':
			case'n':
				cout <<  "将返回菜单" << endl;
				system("PAUSE");
				return false;
			}
		}
	}
	_file.close();

	string text;
	fstream textFile;
	textFile.open("textfile.txt",ios::in|ios::out|ios::trunc);
	if (!textFile.is_open()) {
		cout << "无法创建textfile.txt,将返回菜单" << endl;
		system("PAUSE");
		return false;
	}
	ofstream codeFile;
	codeFile.open("codeFile.txt", ios::out | ios::trunc);
	if (!textFile.is_open()) {
		cout << "无法创建codeFile.txt,将返回菜单" << endl;
		system("PAUSE");
		return false;
	}

	cout << "请输入由字符集中字符组成的任意字符串:";
	cin >> text;
	textFile << text;
	textFile.seekg(0, ios::beg);
	cout << "编码中..." << endl;
	HfmT.Code(textFile, codeFile);
	textFile.close();
	codeFile.close();
	cout << "编码成功！" << endl << endl;
	system("PAUSE");
	return true;
}

bool Decode(HfmTree<char>& HfmT)
{
	if (!HfmT.IsCoded()) {
		cout << "哈夫曼树未完成编码，将返回目录" << endl;
		system("PAUSE");
		return false;
	}

	ifstream codeFile;
	codeFile.open("codefile.txt", ios::in);
	if (!codeFile) {
		cout << "codefile.txt不存在，将返回菜单" << endl;
		system("PAUSE");
		return false;
	}

	fstream _file;
	_file.open("result.txt", ios::in);
	if (_file) {
		bool ex = 1;
		char ch;
		while (ex) {
			cout << "已有文件存在，是否继续？(Y/N)";
			cin >> ch;
			switch (ch)
			{
			case'Y':
			case'y':
				ex = 0;
				break;
			case'N':
			case'n':
				cout << "将返回菜单" << endl;
				system("PAUSE");
				return false;
			}
		}
	}
	_file.close();

	ofstream resultFile;
	resultFile.open("resultFile.txt", ios::out | ios::trunc);
	if (!resultFile.is_open()) {
		cout << "无法创建codeFile.txt,将返回菜单" << endl;
		system("PAUSE");
		return false;
	}
	cout << "译码中..." << endl;
	HfmT.DeCode(codeFile, resultFile);
	codeFile.close();
	resultFile.close();
	cout << "译码成功！" << endl << endl;
	system("PAUSE");
	return true;
}

bool Print(HfmTree<char>& HfmT)
{
	ifstream textFile("textFile.txt", ios::in);
	ifstream codeFile("codeFile.txt", ios::in);
	ifstream resultFile("resultFile.txt", ios::in);
	if (!textFile || !codeFile || !resultFile) {
		cout << "文件缺失，将返回菜单" << endl;
		system("PAUSE");
		return false;
	}
	string buffer;
	textFile >> buffer;
	cout << "textFile:" << endl << buffer << endl << endl;
	codeFile >> buffer;
	cout << "codeFile:" << endl << buffer << endl << endl;
	resultFile >> buffer;
	cout << "resultFile:" << endl << buffer << endl << endl;
	cout << "打印完毕" << endl << endl;
	system("PAUSE");
	return true;

}
