#include<stdio.h>
#include<stdlib.h>

void bubblesort(int *nums, int numsize)
{
	for (int i = 0; i < numsize -1; i++)
	{
		for (int j = 0; j < numsize - i - 1; j++)
		{
			if (nums[j]>nums[j + 1])
			{
				int temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
	}
}
int main()
{
	int nums[] = { 3, 2, 1, 56, 7, 34 };
	bubblesort(nums, 6);
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}