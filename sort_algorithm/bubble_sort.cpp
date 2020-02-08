/*************************************************************************
	> File Name: bubble_sort.c
	> Author: EternalBlue
	> Mail: webbguan@163.com
	> Created Time: Sat 08 Feb 2020 02:52:19 PM CST
 ************************************************************************/

#include<stdio.h>
#include <gtest/gtest.h>

#define NUM_SWAP(a,b)	\
{						\
	typeof(a) temp;		\
	temp = a;			\
	a = b;				\
	b = temp;			\
}

/**
 * 冒泡排序算法，升序排列
 * 参数：
 * 		num：传入为原始数据，传出位排序后数据
 * 		len：数据长度
*/
void sort(int *num, int len)
{
	int i,j;

	if (NULL == num || len <= 0)
	{
		printf("error params.\n");
		return ;
	}

	for (i = 0; i < len - 1; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (num[i] > num[j])
			{
				NUM_SWAP(num[i], num[j]);
			}
		}
	}
}

TEST(bubble_sort, test)
{
	/*测试数据定义*/
	int test1[] = {19, 22, 93, 1, 46, 33, 78, 24};
	int test2[] = {19, 22, 93, 1, 46, 33, 78, 24};
	int test3[] = {19};
	int test4[] = {20, 11};
	sort(test1, sizeof(test1)/4);
	EXPECT_EQ(test1[0], 1);
	EXPECT_EQ(test1[1], 19);
	EXPECT_EQ(test1[2], 22);
	EXPECT_EQ(test1[3], 24);
	EXPECT_EQ(test1[4], 33);
	EXPECT_EQ(test1[5], 46);
	EXPECT_EQ(test1[6], 78);
	EXPECT_EQ(test1[7], 93);

	sort(test2, 0);
	EXPECT_EQ(test2[0], 19);

	sort(test3, 1);
	EXPECT_EQ(test3[0], 19);

	sort(test4, 2);
	EXPECT_EQ(test4[0], 11);
	EXPECT_EQ(test4[1], 20);
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

