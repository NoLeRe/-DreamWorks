#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * toLowerCase(char * str){

	char *cur = str;
	while (*cur)
	{
		if (*cur >= 'A'&&*cur <= 'Z')
			*cur = *cur + 32;
		cur++;
	}
	return str;

}

void rotate(int* nums, int numsSize, int k){

	k %= numsSize;
	for (int i = 0, j = numsSize - k - 1; i<j; i++, j--)
	{
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}

	for (int i = numsSize - k, j = numsSize - 1; i<j; i++, j--)
	{
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}
	for (int i = 0, j = numsSize - 1; i<j; i++, j--)
	{
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}

}
int removeElement(int* nums, int numsSize, int val){

	int count = 0;
	int start = 0;
	int end = numsSize - 1;
	int cur = start;
	while (start <= end)
	{
		if (nums[start] == val)
			start++;
		else
		{
			nums[cur] = nums[start];
			cur++;
			start++;
			count++;
		}
	}
	return count;
}
void moveZeroes(int* nums, int numsSize){
	int k = 0;
	for (int i = 0; i<numsSize; i++)
	{
		if (nums[i] == 0)
			k++;
	}
	for (int i = 0; i<k; i++)
	{
		for (int j = 0; j<numsSize - 1; j++)
		{
			if (nums[j] == 0)
			{
				int temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
	}
}
int searchInsert(int* nums, int numsSize, int target){
	int i = 0;
	for (i = 0; i<numsSize; i++)
	{
		if (target <= nums[i])
			return i;

	}
	return i;
}
bool canConstruct(char * ransomNote, char * magazine){

	int arr[26] = { 0 };
	while (*magazine)
	{
		arr[*magazine - 'a']++;
		magazine++;
	}
	while (*ransomNote)
	{
		if (--arr[*ransomNote - 'a']<0)
			return false;
		ransomNote++;
	}
	return true;
}
bool isPalindrome(int x){
	if (x<0)
		return false;
	char arr[10];
	int top = -1;
	while (x)
	{
		arr[++top] = x % 10;
		x /= 10;
	}
	for (int i = 0, j = top; i<j; i++, j--)
	{
		if (arr[i] != arr[j])
			return false;
	}
	return true;

}
int lengthOfLastWord(char * s){
	int len = strlen(s);
	int count = 0;
	int i, j;
	for (i = len - 1; i >= 0 && s[i] == ' '; i--);
	for (j = i; j >= 0 && s[j] != ' '; j--);
	return i - j;
}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	int end = m + n - 1;
	int end_1 = m - 1;
	int end_2 = n - 1;
	while (end_1 >= 0 && end_2 >= 0)
	{
		if (nums1[end_1]>nums2[end_2])
		{
			nums1[end] = nums1[end_1];
			end_1--;
			end--;
		}
		else
		{
			nums1[end] = nums2[end_2];
			end_2--;
			end--;
		}
	}
	while (end_1 >= 0)
	{
		nums1[end] = nums1[end_1];
		end--;
		end_1--;
	}
	while (end_2 >= 0)
	{
		nums1[end] = nums2[end_2];
		end--;
		end_2--;
	}

}
int main()
{
	int a[] = { 2, 4, 6, 8, 10 }, *p, *k;
	p = a;
	k = p;
	printf(" % d", *(p++));
	printf(" % d\n", *k);

	system("pause");
	return 0;
}