#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

void reserve_string(char* start, char* end)
{
	while (start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}

}

void reserve_all(char* string)
{
	char *cur = string;
	int a = strlen(string);
	reserve_string(string, string + a - 1);
	while (*cur)
	{
		char *start = cur;
		while ((*cur) != ' ' && (*cur) != '\0')
		{
			cur++;
		}
		reserve_string(start, cur - 1);
		while ((*cur) == ' ')
		{
			cur++;
		}
		
	}
}

int main()
{
	char string[] = "l am a student.";
	reserve_all(string);
	printf("%s\n", string);
	system("pause");
	return 0;

}
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int i = 0;
	int j = 0;
	int *a = (int*)malloc(sizeof(int)* 2);
	
	for (i = 0; i < numsSize ; i++)
	{
		for (j = i+1; j < numsSize ; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				a[0] = i;
				a[1] = j;
				return a;
			}
		}
	}

	return a;


}
int main()
{
	int nums[] = {3,2,4};
	int target = 6;
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int *returnSize = 2;
	int *a=twoSum(nums, numsSize, target, returnSize);
	printf("%d %d\n", a[0],a[1]);
	system("pause");
	return 0;
}