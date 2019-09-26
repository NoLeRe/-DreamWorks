#include<stdio.h>
#include<time.h>
#include<string.h>
#pragma warning(disable:4996)

void menu()
{
	printf("******************\n");
	printf("****1.开始游戏****\n");
	printf("****0.退出游戏****\n");
	printf("******************\n");
}
void game()
{
	int random_num = rand() % 100 + 1;
	int x;

	while (1)
	{   
		printf("请输入数字： ");
		scanf("%d", &x);
		if (x > random_num)
		{
			printf("猜大了！！！\n");
		}
		if (x < random_num)
		{
			printf("猜小了！！！\n");
		}
		if (x == random_num)
		{
			printf("猜对了！！！\n");
			break;
		}
	}
}
int main()
{
	int n;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (n);
	system("pause");
	return 0;
}


int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int k = 6;
	int i = 0;
	int j = sizeof(arr)/sizeof(arr[0])-1;
	int mid;
	//printf("%d\n", j);
	while (i <= j)
	{
		
		mid = (i + j) / 2;
		if (arr[mid] < k)
		{
			i = mid + 1;
		}
		if (arr[mid]>k)
		{
			j = mid - 1;
		}
		if (arr[mid] == k)
		{
			break;
		}
	}
	if (i <= j)
	{
		printf("下标为：%d \n", mid);
	}
	else
		printf("找不到\n");
	system("pause");
	return 0;
}


int main()
{   
	int i;
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
	}
	system("pause");
	return 0;

}

int main()
{
	int ch;
	while ((ch = getchar()) != EOF)
	{
		if (ch >= 'a'&&ch <= 'z')   // 小写变大写减32
		{
			ch = ch - 32;
			printf("%c", ch);
		}
		else if (ch >= 'A'&&ch <= 'Z')         //大写变小写加32
		{                                     
			ch = ch + 32;
			printf("%c", ch);
		}
		if (ch >= '0'&&ch <= '9')
		{
		}
	}
	system("pause");
	return 0;
}

