#include "menu.h"

int menu(HfmTree<char>& HfmT)
{
	while (true) {
		cout << "****************************************************************" << endl;
		cout << endl;
		cout << "		      ����������������ϵͳ				    " << endl;
		cout << endl;
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
					printf("�Ƿ����¿�ʼ���й��������룿(Y/N/B)");
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
