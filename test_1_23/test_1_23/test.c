#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#pragma warning(disable:4996)

int facuture(int numSize, int k)
{
	int count = 0;
	for (int i = 0; i < numSize; i++)
	{
		if (k & 1)
			count++;
		k >>= 1;
	}
	return count;
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
	int pos_num = pow(2, numsSize);
	int **arr = (int**)malloc(sizeof(int*)*pos_num);
	returnColumnSizes[0] = (int*)malloc(sizeof(int)*pos_num);

	for (int i = 0; i < pos_num; i++)
	{
		returnColumnSizes[0][i] = facuture(numsSize, i);
		arr[i] = (int*)malloc(sizeof(int)*returnColumnSizes[0][i]);
		int k = i;
		int size = 0;
		for (int j = 0; j < numsSize; j++)
		{
			if (k & 1)
				arr[i][size++] = nums[j];
			k >>= 1;
		}
	}
	*returnSize = pos_num;
	return arr;

}