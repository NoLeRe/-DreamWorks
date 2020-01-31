#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable:4996)
void reserve(int *A, int ASize)
{
	int *start = A;
	int *end = A + ASize - 1;
	while (start<end)
	{
		int temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}

}
int* addToArrayForm(int* A, int ASize, int K, int* returnSize){

	int *arr = (int*)malloc(sizeof(int)* 10001);
	int i = ASize - 1;
	int next = 0;
	int n = 0;
	while (i >= 0 || K>0)
	{
		int x1 = 0;

		if (i >= 0)
		{
			x1 = A[i];
			i--;
		}
		int x2 = 0;
		if (K>0)
		{
			x2 = K % 10;
			K /= 10;
		}
		int ret = x1 + x2 + next;
		if (ret>9)
		{
			ret %= 10;
			next = 1;
		}
		else
		{
			next = 0;
		}
		arr[n++] = ret;


	}
	if (next == 1)
	{
		arr[n++] = next;
	}
	reserve(arr, n);
	*returnSize = n;

	return arr;

}
int main()
{
	int A[] = { 1, 2, 0, 0 };
	int K = 34;
	addToArrayForm(A, 4, K, 4);
	return 0;

}