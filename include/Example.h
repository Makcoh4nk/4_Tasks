#include <stdio.h>
#include <iostream>

using namespace std;

//----------------------- For task #1

int Reverse_number(int);	

//----------------------- For task #2

struct CNode_char
{
	char data;
	CNode_char *next;
};

CNode_char* Search_max_prefix(char**, int);		
void Add_char(CNode_char**, char);

//----------------------- For task #3

struct CNode_int
{
	int data;
	CNode_int *next;
};

CNode_int* Reverse_list(CNode_int*);			
void Add_int(CNode_int**, int);

//----------------------- For task #4

CNode_int* Search_elems(int*, int, int);			

