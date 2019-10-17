#include<stdio.h>

#pragma warning (disable:4996)


int count_one_bits(unsigned int n)
{

	int count = 0;
	while (n>0)
	{
		if (n % 2 == 1)
		{
			count++;
		}
		n = n / 2;
		
	}
	return count;
	// 返回 1的位数
}
int count_one_bits(unsigned int n)
{
	int arr[16] = { 0 };
	int count = 0;
	int i = 0;
	for (i = 0; i < 16; i++)
	{
		arr[i] = ((n >> i) & 1);
	}
	while (i >= 0)
	{
		if ((arr[i] & 1) == 1)
		{
			count++;
		}
		i--;
	}
	return count;
	// 返回 1的位数
}
int main()
{
	printf("%d\n", count_one_bits(15));
	system("pause");
	return 0;
}

int main()
{
	int n;
	int i=0;
	int j=0;
	int arr1[16] = { 0 };
	int arr2[16] = { 0 };
	scanf("%d", &n);
	for (i = 0; i < 32; i+=2)
	{
		arr1[j] = ((n >> i) & 1);
		j++;
	}
	for (i = 1, j = 0; i < 17; i += 2)
	{
		arr2[j] = ((n >> i) & 1);
		j++;
	}
	for (int k = 15; k >= 0; k--)
	{
		printf("%d", arr1[k]);
	}
	printf("\n");
	for (int k = 15; k >= 0; k--)
	{
		printf("%d", arr2[k]);
	}
	printf("\n");
	system("pause");
	return 0;
}

int main()
{
	int m, n;
	int i = 0;
	int count=0;
	scanf("%d%d", &m, &n);
	int arr1[16] = { 0 };
	int arr2[16] = { 0 };
	for (i = 0; i < 16; i++)
	{
		arr1[i] = ((n >> i) & 1);
		arr2[i] = ((m >> i) & 1);
	}
	while (i >= 0)
	{
		if (arr1[i] != arr2[i])
		{
			count++;
		}
		i--;
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}


