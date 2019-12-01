#include<stdio.h>

#pragma warning(disable:4996)
//struct S1 
//{ 
//	char c1;
//	int i;
//	char c2;
//}; 
//struct S2 
//{ 
//	char c1; 
//	char c2; 
//	int i;
//};
//struct S3 
//{ double d;  
//  char c; 
//  int i; 
//};
//struct S4
//{ char c1;
//  struct S3 s3;
//  double d;
//}; 
//int main()
//{
//
//	printf("%d\n", sizeof(struct S1));
//	printf("%d\n", sizeof(struct S2));
//	printf("%d\n", sizeof(struct S3));
//	printf("%d\n", sizeof(struct S4));
//
//	system("pause");
//	return 0;
//
//}
//int removeDuplicates(int* nums, int numsSize){
//
//	if (numsSize == 0 || numsSize == 1)
//		return numsSize;
//	int *src = nums + 1;
//	int *dst = nums;
//	int *end = nums + numsSize - 1;
//	int count = 1;
//	while (src <= end)
//	{
//		if (*src == *(src - 1))
//		{
//			src++;
//		}
//		else
//		{
//			dst++;
//			*dst = *src;
//			count++;
//			src++;
//		}
//	}
//	return count;
//
//}
//
//int main()
//{
//	int nums[] = { 1, 1, 2 };
//	int ret=removeDuplicates(nums, 3);
//	printf("%d", ret);
//	system("pause");
//	return 0;
//}

//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
//	int *end = nums1 + nums1Size - 1;
//	while (n&&nums1 <= end)
//	{
//		if (*nums1 <= *nums2)
//		{
//		    if (m == 0)
//			{
//				*nums1 = *nums2;
//				nums1++;
//				nums2++;
//				n--;
//			}
//			else
//			{
//				nums1++;
//				m--;
//			}
//		}
//		
//		else
//		{
//			
//			for (int i = nums1Size - 1; i>0; i--)
//			{
//				nums1[i] = nums1[i - 1];
//			}
//			*nums1 = *nums2;
//			nums1++;
//			nums2++;
//			n--;
//		}
//	}
//}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	
	int p;
	int temp;
	for (int k = m, p = 0; p<n; k++, p++)
	{
		nums1[k] = nums2[p];
	}
	for (int i = 0; i<m + n-1; i++)
	{
		for (int j = 0; j<m+n-1-i; j++)
		{
			if (nums1[j]>nums1[j + 1])
			{
				temp = nums1[j];
				nums1[j] = nums1[j + 1];
				nums1[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int nums1[] = { 1,2,3,0,0,0};
	int nums2[] = { 2,5,6};
	merge(nums1, 6, 3, nums2, 3, 3);
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", nums1[i]);
	}
	printf("\n");
	system("pause");
	return 0;

}