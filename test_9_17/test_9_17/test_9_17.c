#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)
//1.�����������α�����ֵ��������ֵ�����ݽ��н�����
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


//2.����������ʱ����������������������

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
//3.��10 �����������ֵ��
int main()
{
	int i;
	int arr[10];
	int max;
	printf("������10������\n");
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
//4.�����������Ӵ�С�����
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
//5.�������������Լ����
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
