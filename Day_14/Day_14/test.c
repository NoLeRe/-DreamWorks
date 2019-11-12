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
		while ((*(cur+1))!='\0')
		{
			*cur = *(cur + 1);
			cur++;
		}
		*cur = temp;
	}
}

int main()
{
	char str[] = "ABCD";
	int len =0;
	scanf("&d", &len);
	reserve(str, len);
	printf("%s\n", str);
	system("pause");
	return 0;
}