#include<stdio.h>
#include<stdlib.h>


int removeElement(int* nums, int numsSize, int val){

	int count = 0;
	int start = 0;
	for (int i = 0; i<numsSize; i++)
	{
		if (nums[i] != val)
		{
			nums[start++] = nums[i];
			count++;
		}
	}
	return count;
}
int removeDuplicates(int* nums, int numsSize){
	if (numsSize == 0 || numsSize == 1)
		return numsSize;
	int pre = 0;
	int count = 1;
	for (int i = 1; i<numsSize; i++)
	{
		if (nums[pre] != nums[i])
		{
			nums[++pre] = nums[i];
			count++;
		}
	}
	return count;
}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){

	int pos_1 = m - 1;
	int pos_2 = n - 1;
	int pos = m + n - 1;
	while (m&&n)
	{
		if (nums1[pos_1]<nums2[pos_2])
		{
			nums1[pos--] = nums2[pos_2--];
			n--;
		}
		else
		{
			nums1[pos--] = nums1[pos_1--];
			m--;
		}
	}
	while (n>0)
	{
		nums1[pos--] = nums2[pos_2--];
		n--;
	}
}
void rotate(int* nums, int numsSize, int k){

	k %= numsSize;
	int left = 0, right = numsSize - k - 1;
	while (left<right)
	{
		int temp = nums[left];
		nums[left] = nums[right];
		nums[right] = temp;
		left++;
		right--;
	}
	left = numsSize - k;
	right = numsSize - 1;
	while (left<right)
	{
		int temp = nums[left];
		nums[left] = nums[right];
		nums[right] = temp;
		left++;
		right--;
	}
	left = 0;
	right = numsSize - 1;
	while (left<right)
	{
		int temp = nums[left];
		nums[left] = nums[right];
		nums[right] = temp;
		left++;
		right--;
	}
}
void reserve(int *nums, int numssize)
{
	int left = 0, right = numssize - 1;
	while (left<right)
	{
		int temp = nums[left];
		nums[left] = nums[right];
		nums[right] = temp;
		left++;
		right--;
	}
}
int* addToArrayForm(int* A, int ASize, int K, int* returnSize){

	int *arr = (int*)malloc(sizeof(int)* 10001);
	for (int i = 0; i<10001; i++)
	{
		arr[i] = 0;
	}
	int count = 0;
	int i = ASize - 1;
	while (i >= 0 || K)
	{
		int x1 = 0;
		int x2 = 0;
		if (i >= 0)
		{
			x1 = A[i--];
		}
		if (K>0)
		{
			x2 = K % 10;
			K /= 10;
		}
		arr[count] = arr[count] + x1 + x2;
		if (arr[count]>9)
		{
			arr[count] %= 10;
			arr[count + 1] = 1;
		}
		count++;
	}
	if (arr[count] != 0)
		count++;
	reserve(arr, count);
	*returnSize = count;
	return arr;
}

