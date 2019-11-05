#include<stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int *a = (int*)malloc(sizeof(int)* 2);
	int left = 0;
	int right = numsSize - 1;
	
	while (nums[left] + nums[right] != target)
	{
		if (nums[left] > target)
			left++;
		if (nums[numsSize - 1] > target)
			right--;
	}
	a[0] = left ;
	a[1] = right;
	return a;
}
int main()//2  5  7  8  11
{
	int nums[] = { 2, 11, 7, 15 };
	int target = 9;
	int returnSize[2] = { 0 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int *a=twoSum(nums, numsSize, target, returnSize);
	printf("%d  %d\n", a[0], a[1]);
	system("pause");
	return 0;
}