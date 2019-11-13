#include<stdio.h>
#include<string.h>

#pragma warning(disable:4996)

void reserve(char *str,int len)
{
	char temp ;
	while (len--)
	{
		temp = *str;
		char* cur = str;
		while (*(cur+1)!='\0')
		{
			*cur = *(cur + 1);
			cur++;
		}
		*cur = temp;
	}
}

int main()
{
	char str[] = "abcd";
	int len;
	scanf("%d", &len);
	reserve(str, len);
	printf("%s\n", str);
	system("pause");
	return 0;
}

int main()
{
	char *str1 = "AABCD";
	char *str2 = "ABCDA";
	char str3[20];
	strcpy(str3, str1);
	strcat(str3, str1);
	if (strstr(str3, str2) == NULL)
	{
		printf("不是旋转串！\n");
	}
	else
	{
		printf("是旋转串！\n");
	}

	printf("%s\n", str3);


	system("pause");
	return 0;
}