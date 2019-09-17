#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)
//1.给定两个整形变量的值，将两个值的内容进行交换。
int main()
{
	int a = 1;
	int b = 2;
	int temp;
	temp = a;
	a = b;
	b = temp;
	printf("a=%d  b=%d", a, b);
	system("pause");
	return 0;
}


//2.不允许创建临时变量，交换两个数的内容

int main()
{
	int a = 1;
	int b = 2;
	a = a^b;
	b = b^a;
	a = a^b;
	printf("a=%d  b=%d", a, b);
	system("pause");
	return 0;
}
//3.求10 个整数中最大值。
int main()
{
	int i;
	int arr[10];
	int max;
	printf("请输入10个数：\n");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	max = arr[0];
	for (i = 1; i < 11; i++)
	{

		if (max < arr[i])
		{	
			max = arr[i];
			
		}
	}
	printf("%d\n", max);
	system("pause");
	return 0;
}
//4.将三个数按从大到小输出。
int main()
{
	int i;
	int arr[3];
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &arr[i]);
	}
	if (arr[0] < arr[1])
	{
		int temp;
		temp = arr[0];
		arr[0] = arr[1];
		arr[1] = temp;
	}
	if (arr[0] < arr[2])
	{
		int temp;
		temp = arr[0];
		arr[0] = arr[2];
		arr[2] = temp;
	}
	if (arr[1] < arr[2])
	{
		int temp;
		temp = arr[1];
		arr[1] = arr[2];
		arr[2] = temp;
	}
	for (i = 0; i < 3; i++)
	{

		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}
//5.求两个数的最大公约数。
int main()
{
	int a, b,c;
	scanf("%d %d", &a, &b);
	if (a > b)
	{
		if (a%b == 0)
			printf("%d\n", b);
		if (a%b != 0)
		{
			c = a - b;
			while (b%c != 0)
			{
				a = b;
				b = c;
				c = a - b;
			}
			printf("%d\n", c);
		}
	}
	
	if (a < b)
	{

		if (b%a == 0)
			printf("%d\n", a);

		if (b%a != 0)
		{
			c = b - a;
			while (a%c != 0)
			{
				b = a;
				a = c;
				c = b - a;
			}
			printf("%d\n", c);
		}
	}
	system("pause");
	return 0;
}
