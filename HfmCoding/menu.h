#pragma once
#include <iostream>
#include "HfmTree.h"
using namespace std;

int menu(HfmTree<char>&);
bool BuildHfmTree(HfmTree<char>&);
bool TraverseHfmTree(HfmTree<char>&);
bool Encode(HfmTree<char>&);
bool Code(HfmTree<char>&);
bool Decode(HfmTree<char>&);
bool Print(HfmTree<char>&);
