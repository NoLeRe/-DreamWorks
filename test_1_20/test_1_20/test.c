#include<stdio.h>
#include<stdlib.h>

int comparator(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

bool containsDuplicate(int* nums, int numsSize){

	qsort(nums, numsSize, sizeof(int), comparator);
	for (int i = 0; i<numsSize - 1; i++)
	{
		if (nums[i] == nums[i + 1])
			return true;
	}
	return false;
}

int comparator(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

bool containsDuplicate(int* nums, int numsSize){

	qsort(nums, numsSize, sizeof(int), comparator);
	for (int i = 0; i<numsSize - 1; i++)
	{
		if (nums[i] == nums[i + 1])
			return true;
	}
	return false;
}

int comparator(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
int* sortedSquares(int* A, int ASize, int* returnSize){

	for (int i = 0; i<ASize; i++)
	{
		A[i] = A[i] * A[i];
	}
	qsort(A, ASize, sizeof(int), comparator);
	*returnSize = ASize;
	return A;
}


char * reverseOnlyLetters(char * S){
	char arr[100];
	int top = -1;
	char *cur = S;
	while (*cur)
	{
		if ((*cur >= 'A'&&*cur <= 'Z') || (*cur >= 'a'&&*cur <= 'z'))
			arr[++top] = *cur;
		cur++;
	}
	cur = S;
	while (*cur)
	{
		if ((*cur >= 'A'&&*cur <= 'Z') || (*cur >= 'a'&&*cur <= 'z'))
			*cur = arr[top--];
		cur++;
	}
	return S;

}
int* sortArrayByParity(int* A, int ASize, int* returnSize){
	int *arr = (int*)malloc(sizeof(int)*ASize);
	*returnSize = ASize;
	int left = 0;
	int right = ASize - 1;
	for (int i = 0; i<ASize; i++)
	{
		if (A[i] % 2 == 0)
		{
			arr[left] = A[i];
			left++;
		}
		else
		{
			arr[right] = A[i];
			right--;
		}
	}
	return arr;
}


int pivotIndex(int* nums, int numsSize){
	int sum = 0;
	int count = 0;
	for (int i = 0; i<numsSize; i++)
	{
		sum += nums[i];
	}
	for (int i = 0; i<numsSize; i++)
	{

		if (count * 2 == sum - nums[i])
			return i;
		count += nums[i];
	}
	return -1;
}
int* plusOne(int* digits, int digitsSize, int* returnSize){

	for (int i = digitsSize - 1; i >= 0; i--)
	{
		if (digits[i] != 9)
		{
			digits[i]++;
			*returnSize = digitsSize;
			return digits;
		}
		digits[i] = 0;
	}
	int *arr = (int*)malloc(sizeof(int)*(digitsSize + 1));
	arr[0] = 1;
	for (int i = 1, j = 0; j<digitsSize; i++, j++)
	{
		arr[i] = digits[j];
	}
	*returnSize = digitsSize + 1;
	return arr;
}
int thirdMax(int* nums, int numsSize){

	long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
	for (int i = 0; i<numsSize; i++)
	{
		if (first<nums[i])
			first = nums[i];
	}
	for (int i = 0; i<numsSize; i++)
	{
		if (second<nums[i] && nums[i]<first)
			second = nums[i];
	}
	for (int i = 0; i<numsSize; i++)
	{
		if (third<nums[i] && nums[i]<first&&nums[i]<second)
			third = nums[i];
	}
	if (third != LONG_MIN)
		return third;
	return first;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize){

	int *arr = (int*)malloc(sizeof(int)* 2);
	for (int i = 0; i<numsSize - 1; i++)
	{
		for (int j = i + 1; j<numsSize; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				arr[0] = i;
				arr[1] = j;
			}
		}
	}
	*returnSize = 2;
	return arr;

}
char * addBinary(char * a, char * b){
	int len_a = strlen(a), len_b = strlen(b);
	char temp;
	int len;
	int sum = len_a>len_b ? len_a : len_b;
	char a_[sum];
	char b_[sum];
	char *c = (char*)malloc(sizeof(char)*(sum + 2));
	for (int i = 0; i<sum + 2; i++)
	{
		c[i] = '0';
	}
	if (len_a>len_b)
	{
		len = len_b - 1;
		for (int i = sum - 1; i >= 0; i--)
		{
			if (len >= 0)
			{
				b_[i] = b[len];
				len--;
			}
			else
				b_[i] = '0';
		}
		for (int i = sum - 1; i >= 0; i--)
		{
			a_[i] = a[i];
		}
	}
	if (len_a<len_b)
	{
		len = len_a - 1;
		for (int i = sum - 1; i >= 0; i--)
		{
			if (len >= 0)
			{
				a_[i] = a[len];
				len--;
			}
			else
			{
				a_[i] = '0';
			}
		}
		for (int i = sum - 1; i >= 0; i--)
		{
			b_[i] = b[i];
		}
	}
	if (len_a == len_b)
	{
		for (int i = sum - 1; i >= 0; i--)
		{
			a_[i] = a[i];
			b_[i] = b[i];
		}
	}
	len = sum - 1;
	for (int i = sum; i >= 0; i--)
	{
		if (len >= 0)
		{
			temp = a_[len] + b_[len] + c[i] - '0' * 2;
			if (temp>'2')
			{
				c[i] = '1';
				c[i - 1] = '1';
			}
			if (temp == '2')
			{
				c[i] = '0';
				c[i - 1] = '1';
			}
			if (temp == '1')
			{
				c[i] = '1';
			}
			len--;
		}
	}
	c[sum + 1] = '\0';
	if (c[0] == '0')
		return c + 1;
	return c;
}

int main()
{
	int A[4] = { 3, 1, 2, 4 };

	system("pause");
	return 0;
}