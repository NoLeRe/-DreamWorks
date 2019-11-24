#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#pragma warning(disable:4996)

//int main()
//{ 
//	FILE * pFile; 
//	pFile = fopen("example.txt", "wb"); 
//	fputs("This is an apple.", pFile); 
//	fseek(pFile, 9, SEEK_SET);
//	fputs(" sam", pFile);
//	fclose(pFile); 
//	return 0; 
//}

//int main()
//{
//	int arr[] = { 1, 2, 3, 1, 2 ,4};
//	for (int i = 0; i < 6; i++)
//	{
//		int ret = 0;
//		for (int j = 0; j < 6; j++)
//		{
//			if (arr[i] == arr[j])
//				ret++;
//		}
//		if (ret == 1)
//		{
//			printf("%d\n", arr[i]);
//		}
//	}
//
//	system("pause");
//	return 0;
//}

//int change(int n)
//{
//	int drink = n/2;  //可以换的饮料
//	int bot = n / 2 + n % 2;  //喝完的瓶子数
//	while (bot > 1)
//	{
//		return  drink + change(bot);
//	}
//	return  bot;
//
//}
//
//int main()
//{
//	int ret = change(20);
//	printf("%d\n", ret+20);
//
//	system("pause");
//	return 0;
//
//}

//void  move(char *str, int n)
//{
//	char temp;
//	while (n--)
//	{
//		temp = *str;
//		char *cur = str;
//		while (*(cur + 1) != '\0')
//		{
//			*cur = *(cur + 1);
//			cur++;
//		}
//		*cur = temp;
//	}
//
//}
//
//int main()
//{
//	char p[] = "ABCD";
//	int n;
//	scanf("%d", &n);
//	move(p, n);
//	printf("%s\n", p);
//	system("pause");
//	return 0;
//
//}

//int cmp( char *str1,  char *str2)
//{
//	char str[30];
//	strcpy(str, str2);
//	strcat(str, str2);
//	if (strstr(str, str1) == NULL)
//		return 0;
//	else
//		return 1;
//}
//int main()
//{
//	char str1[] = "AABCD";
//	char str2[] = "BCDAA";
//	//printf("%d\n", cmp(p1, p2));
//	char str[30];
//	strcpy(str, str2);
//	strcat(str, str2);
//	printf("%s", strstr(str,str1));
//	system("pause");
//	return 0;
//}

char *my_strstr(const char *str1, const char *str2)
{
	assert(str1&&str2);
	
	char *ret = str1;
	char *cur = str2;
	while (*str1 != '\0')
	{
		while (*str1 == *str2&&*str2)
		{
			str1++;
			str2++;
		}
		if (*str2 == '\0')
		{
			return ret;
		}
		else
		{
			str2 = cur;
			str1++;
			ret = str1;
		}

	}	 
	return NULL;
}
int my_strcmp(char *str1, char *str2)
{
	assert(str1&&str2);
	while (*str1&&*str2)
	{
		
		while(*str1 == *str2&&*str1&&*str2)   //用while的话会访问越界
		{
			str1++;
			str2++;
		}

		if (*str1 > *str2)
		{
			return 1;
		}
		if  (*str1 < *str2)
		{
			return -1;
		}
		
	}
	if (*str1 == '\0'&&*str2)
		return -1;
	else if (*str2 == '\0'&&*str1)
		return 1;
	else
		return 0;
}
int main()
{
	char *p1 = "BCE";
	char *p2 = "BCE";
	//printf("%s\n", strstr(p1, p2));
	//printf("%s\n", my_strstr(p1, p2));
	printf("%d\n", strcmp(p1, p2));
	printf("%d\n", my_strcmp(p1, p2));
	system("pause");
	return 0;
}



















