#include<stdio.h>

#pragma warning(disable:4996)

void fla(int *num,int len)
{
	int *start = num;
	int *end = num + len - 1;
	int temp = 0;
	while (start < end)
	{
		while ((start<end)&&(*start) % 2 != 0)
			start++;
		while ((start<end)&&(*end) % 2 == 0)
			end--;
		if (start < end)
		{
			temp = *start;
			*start = *end;
			*end = temp;
		}

	}
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	int len = sizeof(arr) / sizeof(int);
	fla(arr,len);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}

int main()
{
	int arr[3][3] = { { 1, 2, 3 }, 
	                  { 2, 3, 4 },
					  { 3, 4, 5 } };
	int *start = arr[0];
	int n;
	int i = 0;
	scanf("%d", &n);
	for (i = 0; i < 9; i++)
	{
		if (*start != n)
		{
			start++;
		}
		if (*start == n)
		{
			printf("´æÔÚ£¡");
			break;
		}
	}
	if (i == 10)
	{
		printf("²»´æÔÚ£¡");
	}
	system("pause");
	return 0;
}