#include<stdio.h>

#pragma warning(disable:4996)

void merge(int* nums1, int m, int* nums2,  int n)
{
	int end1 = m - 1;
	int end2 = n - 1;
	int end = m + n - 1;
	while (end1 >= 0 && end2 >= 0)
	{
		if (nums2[end2] > nums1[end1])
		{
			nums1[end--] = nums2[end2--];
		}
		else
		{
			nums1[end--] = nums1[end1--];
		}
	}
	while (end1 >= 0)
	{
		nums1[end--] = nums1[end1--];
	}
	while (end2 >= 0)
	{
		nums1[end--] = nums2[end2--];
	}

}

void merge_1(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int *src = nums1;
	int *dst = nums2;
	int temp;
	for (int i = 0; i < m;i++)
	{
		src++;
	}
	for (int i = 0; i < n;i++)
	{
		*src = *dst;
		src++;
		dst++;
	}
	for (int i = 0; i < m + n - 1; i++)
	{
		for (int j = 0; j < m + n - 1 - i; j++)
		{
			if (nums1[j]>nums1[j + 1])
			{
				temp = nums1[j];
				nums1[j] = nums1[j + 1];
				nums1[j + 1] = temp;
			}
		}
	}
	/*int p;
	int temp;
	for (int k = m, p = 0; p<n; k++, p++)
	{
		nums1[k] = nums2[p];
	}
	for (int i = 0; i<m + n - 1; i++)
	{
		for (int j = 0; j<m + n - 1 - i; j++)
		{
			if (nums1[j]>nums1[j + 1])
			{
				temp = nums1[j];
				nums1[j] = nums1[j + 1];
				nums1[j + 1] = temp;
			}
		}
	}*/
}

int main()
{
	//nums1 = [1, 2, 3, 0, 0, 0], m = 3
	//nums2 = [2,5,6],       n = 3
	int nums1[6] = { 1, 2, 3 };
	int nums2[3] = { 2, 5, 6 };
	int m = 3;
	int n = 3;
	//merge(nums1, m, nums2, n);
	merge_1(nums1, 6, m, nums2, 3, n);
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", nums1[i]);
	}
	system("pause");
	return 0;
}