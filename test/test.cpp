#include "Example.h"
#include <gtest/gtest.h>

TEST(Reverse_number, can_reverse_zero)
{
	int x = 0, res;

	res = Reverse_number(x);
	EXPECT_EQ(0, res);
}

TEST(Reverse_number, currect_reverse_with_positive_number)
{
	int x = 4356, res;

	res = Reverse_number(x);
	EXPECT_EQ(6534, res);
}

TEST(Reverse_number, currect_reverse_with_negative_number)
{
	int x = -2134, res;

	res = Reverse_number(x);
	EXPECT_EQ(-4312, res);
}

TEST(Reverse_list, currect_reverse_with_list)
{
	CNode *Node = NULL;
	CNode *Res = NULL;
	CNode *Reverse = NULL;

	int flag = 1;

	for (int i = 1; i < 6; ++i)
		Add(&Node, i);

	Add(&Res, 2);
	Add(&Res, 1);
	Add(&Res, 4);
	Add(&Res, 3);
	Add(&Res, 5);

	Reverse = &Reverse_list(Node);

	for (int i = 1; i < 6; ++i)
	{
		if (Res->data != Reverse->data)
			flag = 0;
		Res = Res->next;
		Reverse = Reverse->next;
	}

	EXPECT_EQ(1, flag);
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

	int *act = new int[size];

	act[1] = 3;
	act[4] = 6;

	int exp[4] = { 1,2,0,3 };

	act = Search_elems(ar, size, 3);

	EXPECT_EQ(act, exp);
}

int main(int ac, char* av[])
{
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}