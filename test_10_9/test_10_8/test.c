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
		for (int i = 0; i < n-2; i++)
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
	if (k ==0)
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

void reverse_string(char * string)
{
	if (*string == '\0')
		printf("%c", *string);
	else
	{
		reverse_string(++string);
		printf("%c", *(--string));
	}
}
int main()
{
	char *a = "abcdef";
	reverse_string(a);
	system("pause");
	return 0;
}

int my_strlen(char *string)
{
	int num = 0;
	while(*string != '\0')
	{
		num++;
		string++;
	}
	return num;
}
int mystrlen(char *string)
{
	
	if (*string != '\0')
		return 1 + mystrlen(string++);
	else
		return 0;

}
int main()
{
	char *a = "abcd";
	printf("%d\n",my_strlen(a));
	printf("%d\n", mystrlen(a));
	system("pause");
	return 0;
}

int fla(int n)
{
	if (n <= 2)
		return n;
	else
		return n*fla(n - 1);
}
int fia(int n)
{
	int sum=1;
	if (n <= 2)
		return n;
	else
	{
		for (int i = 1; i < n +1; i++)
		{
			sum = sum*i;
		}
		return sum;
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d\n", fla(n));
	printf("%d\n", fia(n));
	system("pause");
	return 0;
}

void print(int n)
{
	if (n < 10)
		printf("%d ", n);
	else
	{
		print(n / 10);
		printf("%d ", n % 10);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	print(n);
	system("pause");
	return 0;
}