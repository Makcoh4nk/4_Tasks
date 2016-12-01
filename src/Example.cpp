#include "Example.h"

// For task #1

int Reverse_number(int n)
{
	int temp = n, res = 0, size_n = 0;

	while (temp != 0)
	{
		temp = temp / 10;
		size_n++;
	}

	while (n != 0)
	{
		res += (int)(n % 10 * pow(10, size_n - 1));
		size_n--;
		n = n / 10;
	}
	return res;
}

// For task #2

// For task #3

void Add(CNode **Node, int data)
{
	if (*Node == NULL)
	{
		*Node = new CNode;
		(*Node)->data = data;
		(*Node)->next = NULL;
	}
	else
	{
		CNode *temp = new CNode;
		CNode *clone = *Node;

		while ((*Node)->next != NULL)
			*Node = (*Node)->next;
		(*Node)->next = temp;
		temp->data = data;
		temp->next = NULL;
		*Node = clone;
	}
}

CNode Reverse_list(CNode *&Node)
{
	if (Node == NULL)
		throw 1;

	CNode *res = Node;
	int temp = 0;

	while (Node != NULL)
	{
		if (Node->next != NULL)
		{
			temp = Node->data;
			Node->data = Node->next->data;
			Node->next->data = temp;
			Node = Node->next->next;
		}
		else
			Node = Node->next;
	}

	return *res;
}

// For task #4

int* Search_elems(int *Ar, int size, int sum)
{
	int *Res = new int[size];
	int k = 0;
	for (int i = 0; i < size; ++i)
		for (int j = i + 1; j < size; ++j)
		{
			if ((Ar[i] + Ar[j]) == sum)
			{
				Res[k] = Ar[i];
				Res[k + 1] = Ar[j];
				k += 2;
			}
		}
	return Res;
}