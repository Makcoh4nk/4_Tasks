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
		res += (int)(n % 10 * pow(10, size_n-1));
		size_n--;
		n = n / 10;
	}
	return res;
}

// For task #2

void Add_char(CNode_char **Node, char data)
{
	if (*Node == NULL)
	{
		*Node = new CNode_char;
		(*Node)->data = data;
		(*Node)->next = NULL;
	}
	else
	{
		CNode_char *temp = new CNode_char;
		CNode_char *clone = *Node;

		while ((*Node)->next != NULL)
			*Node = (*Node)->next;
		(*Node)->next = temp;
		temp->data = data;
		temp->next = NULL;
		*Node = clone;
	}
}

CNode_char* Search_max_prefix(char** m_str, int s)
{
	CNode_char *str = NULL;
	int flag = 0;
	char temp = 0;

	if ((m_str != NULL) && (s>0))
	{
		for (int i = 0; m_str[0][i] != '\0'; ++i)
		{
			flag = 0;
			temp = m_str[0][i];
			for (int j = 1; (j < s) && (m_str[j][i] != '\0'); ++j)
			{
				if (m_str[j][i] == temp)
					flag++;
				else
					break;
			}
			if (flag == s - 1)
				Add_char(&str, m_str[0][i]);
		}
		return str;
	}
	else
		throw logic_error("Error description");
}

// For task #3

void Add_int(CNode_int **Node, int data)
{
	if (*Node == NULL)
	{
		*Node = new CNode_int;
		(*Node)->data = data;
		(*Node)->next = NULL;
	}
	else
	{
		CNode_int *temp = new CNode_int;
		CNode_int *clone = *Node;

		while ((*Node)->next != NULL)
			*Node = (*Node)->next;
		(*Node)->next = temp;
		temp->data = data;
		temp->next = NULL;
		*Node = clone;
	}
}

CNode_int* Reverse_list(CNode_int *Node)
{
	if (Node == NULL)
		throw logic_error("Error description");

	CNode_int *res = Node;
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

	return res;
}

// For task #4

CNode_int* Search_elems(int *Ar, int size, int sum)
{
	CNode_int *Res = NULL;

	if ((Ar != NULL) && (size > 0))
	{
		for (int i = 0; i < size - 1; ++i)
			for (int j = i + 1; j < size; ++j)
			{
				if ((Ar[i] + Ar[j]) == sum)
				{
					Add_int(&Res, Ar[i]);
					Add_int(&Res, Ar[j]);
				}
			}
		return Res;
	}
	else 
		throw logic_error("Error description");
}
