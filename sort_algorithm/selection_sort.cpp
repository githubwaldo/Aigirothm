/*************************************************************************
	> File Name: selection_sort.cpp
	> Author: EternalBlue
	> Mail: webbguan@163.com
	> Created Time: Sat 08 Feb 2020 10:41:53 PM CST
 ************************************************************************/

#include<iostream>
#include <gtest/gtest.h>

using namespace std;

#define NUM_SWAP(a,b)	\
{						\
	typeof(a) temp;		\
	temp = a;			\
	a = b;				\
	b = temp;			\
}

void sort(int *num, int len)
{
	int i,j;
	int min_index;

	if (NULL == num || len <= 0)
	{
		printf("error params.\n");
		return ;
	}

	for (i = 0; i < len - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < len; j++)
		{
			if (num[j] < num[min_index])
			{
				min_index = j;
			}
		}
		NUM_SWAP(num[i], num[min_index]);
	}
}

TEST(TestCase, test0)
{
	int num[] = {101, 88, 1, 49, 35, 99, 21, 23, 81, 11, 19};
	int num1[] = {10};
	int num2[] = {32, 11, 8};

	sort(num, sizeof(num)/4);
	EXPECT_EQ(num[0], 1);
	EXPECT_EQ(num[1], 11);
	EXPECT_EQ(num[2], 19);
	EXPECT_EQ(num[3], 21);
	EXPECT_EQ(num[4], 23);
	EXPECT_EQ(num[5], 35);
	EXPECT_EQ(num[6], 49);
	EXPECT_EQ(num[7], 81);
	EXPECT_EQ(num[8], 88);
	EXPECT_EQ(num[9], 99);
	EXPECT_EQ(num[10], 101);

	sort(num1, sizeof(num1)/4);
	EXPECT_EQ(num1[0], 10);

	sort(num1, 0);
	EXPECT_EQ(num2[0], 32);
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

