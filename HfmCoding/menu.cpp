#include "menu.h"
#include <fstream>
#include <cstdlib>
int menu(HfmTree<char>& HfmT)
{
	while (true) {
		cout << "****************************************************************" << endl;
		cout << "*                                                              *"<<endl;
		cout << "*		      ����������������ϵͳ		       *" << endl;
		cout << "*                                                              *" << endl;
		cout << "****************************************************************" << endl;
		cout << "  B-�����������ַ��������ַ����͸��ַ�Ƶ�ȣ�������������	 " << endl<<endl;
		cout << "  T-������������������������							 " << endl << endl;
		cout << "  E-���ɱ��룺�����ѽ��ɵĹ����������������ַ��Ĺ���������	" << endl << endl;
		cout << "  C-���룺�������ַ�����ɵ������ַ�������������������,������" << endl;
		cout << "	  ��������������ֱ𱣴���textfile.txt��codefile.txt" << endl << endl;
		cout << "  D-����:����codefile.txt,���ù����������벢����result.txt " << endl << endl;
		cout << "  P-��ӡ:��Ļ��ʾ�ļ�textfile.txt��codefile.txt��result.txt" << endl << endl;
		cout << "  N-�˳��˴β���											  " << endl;
		cout << "*****************************************************************" << endl;
		char choice;
		int choose = 0;
		while (!choose) {
			cout << "��������Ҫ���еĲ�����";
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
					printf("�Ƿ����¿�ʼ���������룿(Y/N/B)");
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
		cout << "���������Ѿ�������������Ŀ¼" << endl;
		system("PAUSE");
		return false;
	}
	int n;
	int *num;
	char* ch;
	cout << "�������ַ�������:";
	cin >> n;
	num = new int[n];
	ch = new char[n];
	cout << "�������ַ�����	  ";
	for (int index = 0; index < n; index++)
		cin >> ch[index];
	cout << "��������ַ�Ƶ�ȣ�";
	for (int index = 0; index < n; index++)
		cin >> num[index];
	HfmT.Create(ch, num, n);
	cout <<  "�������������ɹ�" << endl << endl ;
	system("PAUSE");
	return true;
}

bool TraverseHfmTree(HfmTree<char>& HfmT)
{
	if (HfmT.getRoot() == NULL) {
		cout << "��������Ϊ�գ�������Ŀ¼" << endl;
		system("PAUSE");
		return false;
	}
	cout << "��������ǰ�����Ϊ:";
	HfmT.preOrder(visitHfm);
	cout << endl << "���������������Ϊ:";
	HfmT.inOrder(visitHfm);
	cout << endl << endl;
	system("PAUSE");
	return true;
}

bool Encode(HfmTree<char>& HfmT)
{
	if (HfmT.getRoot() == NULL) {
		cout << "��������δ������������Ŀ¼" << endl;
		system("PAUSE");
		return false;
	}
	if (HfmT.IsCoded()) {
		cout << "���������ѱ���..." << endl;
		char ch;
		while (true) {
			cout << "�Ƿ������������(Y/N)";
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
				cout << "������Ŀ¼" << endl << endl;
				system("PAUSE");
				return false;
			}
		}
	}
	char ch=0;
	while (true) {
		cout << "�Ƿ������������(Y/N)";
		cin >> ch;
		switch (ch)
		{
		case'Y':
		case'y':
			cout << "���ɱ�����..." << endl;
			HfmT.EnCode(cout);
			cout <<  "������ɣ�" << endl << endl;
			system("PAUSE");
			return true;
		case'N':
		case'n':
			cout << "���ɱ�����..." << endl;
			HfmT.EnCode();
			cout  << "������ɣ�" << endl << endl;
			system("PAUSE");
			return true;
		}
	}
	return false;
}

bool Code(HfmTree<char>& HfmT)
{
	if (!HfmT.IsCoded()) {
		cout << "��������δ��ɱ��룬������Ŀ¼" << endl;
		system("PAUSE");
		return false;
	}
	fstream _file;
	_file.open("textfile.txt", ios::in);
	if (_file) {
		bool ex = 1;
		char ch;
		while (ex) {
			cout << "�����ļ����ڣ��Ƿ������(Y/N)";
			cin >> ch;
			switch (ch)
			{
			case'Y':
			case'y':
				ex = 0;
				break;
			case'N':
			case'n':
				cout <<  "�����ز˵�" << endl;
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
		cout << "�޷�����textfile.txt,�����ز˵�" << endl;
		system("PAUSE");
		return false;
	}
	ofstream codeFile;
	codeFile.open("codeFile.txt", ios::out | ios::trunc);
	if (!textFile.is_open()) {
		cout << "�޷�����codeFile.txt,�����ز˵�" << endl;
		system("PAUSE");
		return false;
	}

	cout << "���������ַ������ַ���ɵ������ַ���:";
	cin >> text;
	textFile << text;
	textFile.seekg(0, ios::beg);
	cout << "������..." << endl;
	HfmT.Code(textFile, codeFile);
	textFile.close();
	codeFile.close();
	cout << "����ɹ���" << endl << endl;
	system("PAUSE");
	return true;
}

bool Decode(HfmTree<char>& HfmT)
{
	if (!HfmT.IsCoded()) {
		cout << "��������δ��ɱ��룬������Ŀ¼" << endl;
		system("PAUSE");
		return false;
	}

	ifstream codeFile;
	codeFile.open("codefile.txt", ios::in);
	if (!codeFile) {
		cout << "codefile.txt�����ڣ������ز˵�" << endl;
		system("PAUSE");
		return false;
	}

	fstream _file;
	_file.open("result.txt", ios::in);
	if (_file) {
		bool ex = 1;
		char ch;
		while (ex) {
			cout << "�����ļ����ڣ��Ƿ������(Y/N)";
			cin >> ch;
			switch (ch)
			{
			case'Y':
			case'y':
				ex = 0;
				break;
			case'N':
			case'n':
				cout << "�����ز˵�" << endl;
				system("PAUSE");
				return false;
			}
		}
	}
	_file.close();

	ofstream resultFile;
	resultFile.open("resultFile.txt", ios::out | ios::trunc);
	if (!resultFile.is_open()) {
		cout << "�޷�����codeFile.txt,�����ز˵�" << endl;
		system("PAUSE");
		return false;
	}
	cout << "������..." << endl;
	HfmT.DeCode(codeFile, resultFile);
	codeFile.close();
	resultFile.close();
	cout << "����ɹ���" << endl << endl;
	system("PAUSE");
	return true;
}

bool Print(HfmTree<char>& HfmT)
{
	ifstream textFile("textFile.txt", ios::in);
	ifstream codeFile("codeFile.txt", ios::in);
	ifstream resultFile("resultFile.txt", ios::in);
	if (!textFile || !codeFile || !resultFile) {
		cout << "�ļ�ȱʧ�������ز˵�" << endl;
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
	cout << "��ӡ���" << endl << endl;
	system("PAUSE");
	return true;

}
