#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

struct CNode
{
	int data;
	CNode *next;
};

int Reverse_number(int);
void Add(CNode**, int);
CNode Reverse_list(CNode*&);
int* Search_elems(int*, int, int);