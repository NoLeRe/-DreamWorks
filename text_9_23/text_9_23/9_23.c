#include<stdio.h>

#pragma warning(disable :4996)

//1. 将数组A中的内容和数组B中的内容进行交换。（数组一样大）
int main()
{
	int arr_1[3] = { 1, 2, 3 };
	int arr_2[3] = { 4, 5, 6 };
	int arr[3] = { 0 };
	for (int i = 0; i < 3; i++)
	{
		arr[i] = arr_1[i];
		arr_1[i] = arr_2[i];
		arr_2[i] = arr[i];
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%d ", arr_1[i]);
	}
	printf("\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", arr_2[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}

//2.计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值。
int main()
{
	int i;
	double sum;
	double sum_1= 0;
	double sum_2 = 0;
	for ( i = 1; i < 101; i+=2)
	{
		sum_1 = sum_1 + 1.0/i;
	}
	for ( i = 2; i < 101; i+=2)
	{
		sum_2 = sum_2 + 1.0 / i;	//如果i是整型，1.0除以i会转换为浮点除
	}                               //结果是浮点，1除以i则会整型除法，结果为整型。
	sum = sum_1 - sum_2;            //比如i等于2，1.0 / i等于0.5，1 / i等于0
	printf("%f\n", sum);
	system("pause");
	return 0;
}

//3. 编写程序数一下 1到 100 的所有整数中出现多少次数字9。
int main()
{   
	int k = 0;
	int j = 20;
	for (int i = 1; i < 101; i++)
	{   
		if (i < 20)
		{
			if (i % 10 == 9)
			{
				k++;
			}
			
		}
		if (i>=20)
		{
			if (i%j == 9)
			{
				k++;
				j = j + 10;
			}
		}
	}
	printf("%d\n", k);
	system("pause");
	return 0;
}