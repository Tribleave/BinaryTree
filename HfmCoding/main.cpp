#include "HfmTree.h"
#include "menu.h"
#include <iostream>
using namespace std;
int main()
{
	int process=1;
	while (process) {
		HfmTree<char> HfmT;
		process=menu(HfmT);
		system("cls");
	}
	return 0;
}

