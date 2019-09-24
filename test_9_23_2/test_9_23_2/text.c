#include<stdio.h>
#pragma warning (disable:4996)




int main()
{
	int i,j;
	for ( i = 0; i < 100; i++)
	{
		int  a, b;
		a = i / 10;
		b = i - (a * 10);
		if (i == (a*a*a) + (b*b*b))
		{
			printf("%d ", i);
		}
	}
	for ( j = 100; j < 1000; j++)
	{
		int a, b, c;
		a = j / 100;
		b = (j/10) - (a * 10);
		c = j % 10;
		if (j == (a*a*a) + (b*b*b) + (c*c*c))
		{
				printf("%d ", j);
			}
		}
	
	printf("\n");
	system("pause");
	return 0;
}

int main()
{
	int x;
	int sum=0;
	int a=0;
	scanf("%d", &x);
	for (int i = 0; i < 5; i++)
	{
		sum = sum + x;
		x = x * 10;
		a = a + sum;
	}
	printf("%d\n", a);
	system("pause");
	return 0;
}