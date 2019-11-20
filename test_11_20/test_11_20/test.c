#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#pragma warning(disable:4996)

void GetMemory(char *p) 
{ 
	p = (char *)malloc(100); 
} 
int main()
{	char *str = NULL; 
	GetMemory(str);  
	strcpy(str, "hello world");  
	printf("%s",str); 
	free(str);
	system("pause");
	return 0;
}

void qsort(int *arr,int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void all_qsort(void *arr, int n, int size)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (*((char *)arr + j*size)>*((char *)arr + (j+1)*size))
			{
				char temp = *((char *)arr + j*size);
				*((char *)arr + j*size) = *((char *)arr + (j+1)*size);
				*((char *)arr + (j+1)*size) = temp;
			}
		}
	}

}
int main()
{
	int arr[5] = { 5, 3, 4, 2, 1 };
	char c[10] = "adicfjgheb";
	all_qsort(arr, 5,sizeof(int));
	all_qsort(c, 10, sizeof(char));
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%c ", c[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}

int exchange(int bot)
{
	int ret = bot / 2;   //交换的饮料
	int empty = bot / 2 + bot % 2;  //总空瓶数
	if (empty > 1)
		return  ret + exchange(empty);
	else
		return ret;
}
int main()
{
	int money = 20;
	int n = 20 + exchange(money);;
	printf("%d\n", n);
	system("pause");
	return 0;
}