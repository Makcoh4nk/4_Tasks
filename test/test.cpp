#include "Example.h"
#include <gtest/gtest.h>

//--------------------------------------------------------
TEST(Reverse_number, can_reverse_zero)
{
	int x = 0, res;

	res = Reverse_number(x);
	EXPECT_EQ(0, res);
}

TEST(Reverse_number, correct_reverse_number_with_zero_at_the_end)
{
	int x = 910, res;

	res = Reverse_number(x);
	EXPECT_EQ(19, res);
}

TEST(Reverse_number, correct_reverse_with_positive_number)
{
	int x = 4356, res;

	res = Reverse_number(x);
	EXPECT_EQ(6534, res);
}

TEST(Reverse_number, correct_reverse_with_negative_number)
{
	int x = -2134, res;

	res = Reverse_number(x);
	EXPECT_EQ(-4312, res);
}

//--------------------------------------------------------

TEST(Search_max_prefix, throw_if_matrix_is_empty)
{
	char** str_m = NULL;

	EXPECT_ANY_THROW(CNode_char *act = Search_max_prefix(str_m, 3));
}

TEST(Search_max_prefix, throw_if_parameter_size_is_negative)
{
	char** str_m = new char*[1];
	str_m[0] = "abc";

	EXPECT_ANY_THROW(CNode_char *act = Search_max_prefix(str_m, -1));
}

TEST(Search_max_prefix, if_one_string_output_it)
{
	const int size_t = 1;

	char** str_m = new char*[size_t];
	str_m[0] = "abc";

	CNode_char *act = Search_max_prefix(str_m, size_t);

	CNode_char *exp = NULL;
	Add_char(&exp, 'a');
	Add_char(&exp, 'b');
	Add_char(&exp, 'c');

	while (exp != NULL)
	{
		EXPECT_EQ(exp->data, act->data);
		exp = exp->next;
		act = act->next;
	}

	delete[] str_m;
	str_m = NULL;
}

TEST(Search_max_prefix, correct_search_max_prefix)
{
	const int size_t = 3;

	char** str_m = new char*[size_t];
	str_m[0] = "abcd";
	str_m[1] = "abh";
	str_m[2] = "abchf";

	CNode_char *exp = NULL;
	Add_char(&exp, 'a');
	Add_char(&exp, 'b');

	CNode_char *act = Search_max_prefix(str_m, size_t);

	while (exp != NULL)
	{
		EXPECT_EQ(exp->data, act->data);
		exp = exp->next;
		act = act->next;
	}

	delete[] str_m;
	str_m = NULL;
}

//--------------------------------------------------------

TEST(Reverse_list, throw_if_list_is_empty)
{
	CNode_int *Node = NULL;

	EXPECT_ANY_THROW(Reverse_list(Node));
}

TEST(Reverse_list, can_reverse_list_with_one_element)
{
	CNode_int *Node = NULL;
	CNode_int *Res = NULL;
	CNode_int *Reverse = NULL;

	Add_int(&Node, 1);
	Add_int(&Res, 1);
	Reverse = Reverse_list(Node);

	EXPECT_EQ(Res->data, Reverse->data);
}

TEST(Reverse_list, correct_reverse_list_)
{
	CNode_int *Node = NULL;
	CNode_int *Res = NULL;
	CNode_int *Reverse = NULL;

	for (int i = 1; i < 6; ++i)
		Add_int(&Node, i);

	Add_int(&Res, 2);
	Add_int(&Res, 1);
	Add_int(&Res, 4);
	Add_int(&Res, 3);
	Add_int(&Res, 5);

	Reverse = Reverse_list(Node);

	for (int i = 1; i < 6; ++i)
	{
		EXPECT_EQ(Res->data, Reverse->data);
		Res = Res->next;
		Reverse = Reverse->next;
	}
}

//--------------------------------------------------------

TEST(Reverse_list, throw_if_array_is_empty)
{
	const int size = 3;
	int *ar = NULL;

	EXPECT_ANY_THROW(Search_elems(ar, size, 3));
}

TEST(Reverse_list, throw_if_parameter_size_is_negative)
{
	const int size = 3;
	int *ar = new int[3];
	ar[0] = 0;
	ar[1] = 1;
	ar[2] = 2;

	EXPECT_ANY_THROW(Search_elems(ar, -1, 3));
}

TEST(Search_elems, correct_search_elems)
{
	const int size = 6;
	int *ar = new int[size];

	ar[0] = 1;
	ar[1] = 6;
	ar[2] = 0;
	ar[3] = 3;
	ar[4] = -5;
	ar[5] = 2;

	CNode_int *exp = NULL;

	Add_int(&exp, 1);
	Add_int(&exp, 2);
	Add_int(&exp, 0);
	Add_int(&exp, 3);

	CNode_int *act = Search_elems(ar, size, 3);

	for (int i = 0; i < 4; ++i)
	{
		EXPECT_EQ(act->data, exp->data);
		act = act->next;
		exp = exp->next;
	}

	delete[] ar;
	ar = NULL;
}

int main(int ac, char* av[])
{
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}
