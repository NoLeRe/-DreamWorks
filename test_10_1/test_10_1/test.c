#include<stdio.h>

#pragma warning (disable:4996)

//�˷��ھ���
int table()
{
	int n;
	int sum;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			sum = i*j;
			printf("%d*%d=%d  ", i, j, sum);
		}
		printf("\n");
	}
}

int main()
{
	
	printf("��ѡ�񼸳˼��˷���");
	table();

	system("pause");
	return 0;
}

//��������
void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
int main()
{
	int x, y;
	printf("��������Ҫ��������������");
	scanf("%d%d", &x, &y);
	swap(&x, &y);
	printf("%d %d\n", x, y);
	system("pause");
	return 0;
}

//�ж�����
void leapyear(int year)
{
	if (((year % 4 == 0) && (year % 100 != 0) )|| (year % 400 == 0))
		printf("%d������\n", year);
	else
		printf("%d��������\n", year);
}
int main()
{
	int year;
	printf("��������ݣ�");
	scanf("%d", &year);
	leapyear(year);
	system("pause");
	return 0;
}

//����
void init(int arr[],int i)
{
	for (int n=0; n < i; n++)
	{
		scanf("%d", &arr[n]);
	}
	for (int j = 0; j < 5; j++)
	{
		printf("%d ", arr[j]);
	}
	printf("\n");
}
void empty(int arr[], int i)
{
	for (int n = 0; n < i; n++)
	{
		arr[n] = 0;
	}
	for (int j = 0; j < 5; j++)
	{
		printf("%d ", arr[j]);
	}
	printf("\n");
}
void reserve(int arr[], int i)
{
	for (int n = i - 1; n >= 0; n--)
	{
		printf("%d ", arr[n]);
	}
	printf("\n");
}
int main()
{ 
	int a[5];
	init(a, 5);
	reserve(a, 5);
	empty(a, 5);
	
	system("pause");
	return 0;
}

//�ж�����
int  panduan(int year)
{
	int i;
	for ( i = 2; i <= year; i++)
	{
		if (year%i == 0)
		{
			break;
		}
	}
	if (i == year||year==1)
		return 1;
	else
		return -1;
}
int main()
{
	int year;
	printf("���������֣� ");
	scanf("%d", &year);
	if (panduan(year) == 1)
		printf("������\n");
	else
		printf("��������\n");
	system("pause");
	return 0;
}
