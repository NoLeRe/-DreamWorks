#include<stdio.h>
#include<time.h>
#include<string.h>
#pragma warning(disable:4996)

void menu()
{
	printf("******************\n");
	printf("****1.��ʼ��Ϸ****\n");
	printf("****0.�˳���Ϸ****\n");
	printf("******************\n");
}
void game()
{
	int random_num = rand() % 100 + 1;
	int x;

	while (1)
	{   
		printf("���������֣� ");
		scanf("%d", &x);
		if (x > random_num)
		{
			printf("�´��ˣ�����\n");
		}
		if (x < random_num)
		{
			printf("��С�ˣ�����\n");
		}
		if (x == random_num)
		{
			printf("�¶��ˣ�����\n");
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
			printf("����������������룡\n");
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
		printf("�±�Ϊ��%d \n", mid);
	}
	else
		printf("�Ҳ���\n");
	system("pause");
	return 0;
}


int main()
{   
	int i;
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
	}
	system("pause");
	return 0;

}

int main()
{
	int ch;
	while ((ch = getchar()) != EOF)
	{
		if (ch >= 'a'&&ch <= 'z')   // Сд���д��32
		{
			ch = ch - 32;
			printf("%c", ch);
		}
		else if (ch >= 'A'&&ch <= 'Z')         //��д��Сд��32
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

