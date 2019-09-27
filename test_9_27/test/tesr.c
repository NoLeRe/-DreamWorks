#include<stdio.h>
#include<windows.h>
#include<string.h>
#pragma warning (disable:4996)

//在整型有序数组中查找想要的数字，
//找到了返回下标，找不到返回 - 1.（折半查找）

//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int key = 16;
//	int left = 0;
//	int right = sizeof(arr) / sizeof(arr[0])-1;
//	int mid;
//	while (left <= right)
//	{  
//		mid = (left + right) / 2;
//		if (arr[mid] < key)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid]>key)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] == key)
//		{
//			break;
//		}
//	}
//	if (arr[mid] == key)
//	{
//		printf("下标为： %d\n", mid);
//	}
//	else
//	{
//		return -1;
//	}
//	system("pause");
//	return 0;
//}


//int main()
//{
//	int ch;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch > 'a'&&ch < 'z')
//		{
//			ch = ch - 32;
//			printf("%c", ch);
//		}
//		else if (ch>'A'&&ch < 'Z')
//		{
//			ch = ch + 32;
//			printf("%c", ch);
//		}
//	}
//	system("pause");
//	return 0;
//}


int main()
{
	int i;
	char arr_1[10];
	char *arr_2= "123456";
	printf("请输入密码： ");
	for (i = 0; i < 3; i++)
	{
		
		scanf("%s", arr_1);
	    if (strcmp(arr_1,arr_2)==0)
		{
			printf("密码正确！\n");
			break;
		}
		else
		{
			printf("密码错误，请重新输入！\n");
		}
	}
	if (i == 3)
	{
		printf("退出程序！\n");
	}

	/*int i;
	char arr_1[10] = "";
	char arr_2[] = "123456";
	printf("请输入密码： ");
	for (i = 0; i < 3; i++)
	{

		scanf("%s", arr_1);

		if (strcmp(arr_1, arr_2) == 0)
		{
			printf("登陆成功！\n");
			break;
		}
		else
		{
			printf("请重新输入： ");
		}
	}
	if (i == 3)
	{
		printf("退出程序！\n");
	}*/
	system("pause");
	return 0;
}