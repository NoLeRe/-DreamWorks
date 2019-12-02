#include<stdio.h>

//int main()
//{ 
//	/*unsigned char i = 7;
//	int j = 0;
//	for (; i>0; i -= 3)
//	{
//		++j; 
//	}    */ 
//	char *p[] = { "Shanghai", "Beijing", "Honkong" };
//	printf("%s\n", *(p+1)+1);
//	system("pause");
//	return 0; 
//}

//void rotate(int* nums, int numsSize, int k){
//
//	while (k--)
//	{
//		int ret = nums[numsSize-1];
//		for (int i = numsSize - 1; i>0; i--)
//		{
//			nums[i] = nums[i - 1];
//		}
//		nums[0] = ret;
//	}
//
//}

//void rotate(int* nums, int numsSize, int k){
//
//	k %= numsSize;  //确保当旋转次数大于数组容量
//	for (int i = 0, j = numsSize - 1 - k; i<j; i++, j--)
//	{
//		int temp = nums[i];
//		nums[i] = nums[j];
//		nums[j] = temp;
//	}
//	for (int i = numsSize - k, j = numsSize - 1; i<j; i++, j--)
//	{
//		int temp = nums[i];
//		nums[i] = nums[j];
//		nums[j] = temp;
//	}
//	for (int i = 0, j = numsSize - 1; i<j; i++, j--)
//	{
//		int temp = nums[i];
//		nums[i] = nums[j];
//		nums[j] = temp;
//	}
//
//
//}
//int main()
//{
//	int nums[] = { 1, 2, 3, 4, 5, 6, 7 };
//	rotate(nums, 7, 3);
//	for (int i = 0; i < 7; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//	system("pause");
//	return 0;
//
//}

int addToArrayForm(int* A, int ASize, int K){

	int ret = 0;//取数组的数
	int count = 0; //位数
	int j = 1;//乘数
	int num = 0; //数组数的大小
	int sum = 0;  //和
	for (int i = ASize - 1; i >= 0; i--)
	{
		ret = A[ASize];
		num = ret*j + num;
		j *= 10;
	}
	sum = num + K;
	int lin = sum;
	while (lin / 10)
	{
		count++;
	}
	int *arr = (int*)malloc(sizeof(int)* count);
	for (int i = count; i >= 0; i--)
	{
		arr[count] = sum % 10;
		sum / 10;
	}
	
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}

}

int main()
{
	int A[] = { 1, 2, 0, 0 };
	addToArrayForm(A, 4, 34);
	system("pause");
	return 0;
}
