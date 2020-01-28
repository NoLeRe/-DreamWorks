#include<stdio.h>
#include<assert.h>
#include<string.h>

#pragma warning(disable:4996)

void serach(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		int ret = 0;
		for (int j = 0; j < len; j++)
		{
			if (arr[i] == arr[j])
			{
				ret++;
			}
		}
		if (ret == 1)
		{
			printf("%d ", arr[i]);
		}
	}
}

int main()
{
	int arr[] = { 1, 1, 2, 2, 3, 3, 4, 5 };
	int len = sizeof(arr) / sizeof(int);
	serach(arr, len);
	system("pause");
	return 0;
}

int main()
{
	int bot = 20;  //Æ¿×Ó
	int hbot = 0;    //¿ÕÆ¿×Ó
	int temp = 0;      //Ê£Óà¿ÕÆ¿×Ó
	hbot = 20;
	while (hbot >= 1)
	{
		hbot = hbot + temp;
		bot = bot + hbot / 2;
		temp = hbot % 2;
		hbot = hbot / 2;
	}
	printf("%d", bot);
	system("pause");
	return 0;
}

char *my_strcpy(char *dst, const char *src)
{
	assert(dst&&src);
	char *ret = dst;
	while (*dst++ = *src++);

	return ret;
}
char *my_strcat(char *dst, const char *src)
{
	assert(dst&&src);
	char *ret = dst;
	while (*dst)
	{
		dst++;
	}
	while (*dst++ = *src++);

	return ret;
}

int main()
{
	char *p1 = "hello";
	char p2[20] = "man";
	//printf("%s\n", my_strcpy(p2, p1));
	printf("%s\n", my_strcat(p2, p1));
	system("pause");
	return 0;
}