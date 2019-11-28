#include<stdio.h>

#pragma warning(disable:4996)

int fun(int n)
{
	int a = 0, b = 1;
	int c=a+b;
	int count = 0;
	while (n>c)
	{
		c = a + b;
		a = b;
		b = c;
	}
	int d = a + b;
	int left = c - n;
	int right = d - n;
	if (left<right)
	{
		count = 0;
		while (n != a)
		{
			n--;
			count++;
			if (n == a)
			{
				return count;
			}
		}
		
	}
	else
	{
		count = 0;
		while (n != c)
		{
			n++;
			count++;
			if (n == c)
			{
				return count;
			}
		}
	}
}
int main()
{
	int ret=fun(25);
	printf("%d", ret);
	system("pause");
	return 0;

}