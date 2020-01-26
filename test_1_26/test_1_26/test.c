#include<stdio.h>
#pragma warning (disable:4996)

int flb(int n)
{
	if (n <= 2)
		return 1;
	else
		return flb(n - 1) + flb(n - 2);
}
int fib(int n)
{
	int a = 1;
	int b = 1;
	int c;
	if (n <= 2)
		return 1;
	else
	{
		for (int i = 0; i < n - 2; i++)
		{
			c = a + b;
			a = b;
			b = c;

		}
		return c;
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", flb(n));
	printf("%d\n", fib(n));
	system("pause");
	return 0;
}

int fla(int n, int k)
{
	if (k == 0)
	{
		return 1;
	}
	else if (k == 1)
	{
		return n;
	}
	else if (k > 1)
	{
		return n*fla(n, k - 1);
	}

}
int fia(int n, int k)
{
	int s = 1;
	if (k == 0)
	{
		return 1;
	}
	else if (k == 1)
	{
		return n;
	}
	else if (k > 1)
	{
		for (int i = 0; i < k; i++)
		{
			s = s*n;
		}
		return s;
	}
}
int main()
{
	printf("%d\n", fla(3, 3));
	printf("%d\n", fia(3, 3));
	system("pause");
	return 0;
}

int DigitSum(int n)
{
	if (n < 10)
	{
		return n;
	}
	else
		return n % 10 + DigitSum(n / 10);
}
int main()
{
	printf("%d\n", DigitSum(1729));
	system("pause");
	return 0;
}

char reverse_string(char * string)
{

}