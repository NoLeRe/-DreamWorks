#include<stdio.h>
#include<windows.h>
#include<string.h>
#pragma warning (disable:4996)

//���������������в�����Ҫ�����֣�
//�ҵ��˷����±꣬�Ҳ������� - 1.���۰���ң�

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
//		printf("�±�Ϊ�� %d\n", mid);
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
	printf("���������룺 ");
	for (i = 0; i < 3; i++)
	{
		
		scanf("%s", arr_1);
	    if (strcmp(arr_1,arr_2)==0)
		{
			printf("������ȷ��\n");
			break;
		}
		else
		{
			printf("����������������룡\n");
		}
	}
	if (i == 3)
	{
		printf("�˳�����\n");
	}

	/*int i;
	char arr_1[10] = "";
	char arr_2[] = "123456";
	printf("���������룺 ");
	for (i = 0; i < 3; i++)
	{

		scanf("%s", arr_1);

		if (strcmp(arr_1, arr_2) == 0)
		{
			printf("��½�ɹ���\n");
			break;
		}
		else
		{
			printf("���������룺 ");
		}
	}
	if (i == 3)
	{
		printf("�˳�����\n");
	}*/
	system("pause");
	return 0;
}