#include<stdio.h>
#include<string.h>
#include<assert.h>

#pragma warning(disable:4996)

int my_strlen(const char *str)
{
	assert(str);
	int len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return len;
}

char *my_strcpy(char *dst, const char *src)
{
	assert(dst&&src);
	char *ret = dst;
	while (*dst++ = *src++);
	return ret;
}
char *my_strncpy(char *dst, const char *src, size_t n)
{
	assert(dst&&src);
	char *ret = dst;
	while (n--)
	{
		*dst = *src;
		dst++;
		src++;
	}
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
char *my_strncat(char *dst, char *src, size_t n)
{
	assert(dst&&src);
	char *ret = dst;
	while (*dst)
	{
		dst++;
	}
	while (n--)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return ret;
}
int my_strcmp(const char *str1, const char *str2)
{
	assert(str1&&str2);
	while (*str1&&*str2)
	{
		if (*str1 > *str2)
		{
			return 1;
		}
		else if (*str2 > *str1)
		{
			return -1;
		}
		else
		{
			str1++;
			str2++;
		}
	}
	if (*str1 == '\0'&&*str2)
		return -1;
	else if (*str2 == '\0'&&*str1)
		return  1;
	else
		return  0;
}

char *my_strstr(const char *str1, const char *str2)
{
	assert(str1&&str2);
	char *ret = str1;
	char *cur = str2;
	while (*str1)
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
int main()
{
	char str1[20] = "abcd";
	char str2[] = "fbcd";
	/*printf("%d\n", my_strlen(str1));
	printf("%d\n", strlen(str1));
	printf("%s\n", my_strcpy(str1,str2));
	printf("%s\n", strcpy(str1,str2));*/
	//printf("%s\n", my_strcat(str1,str2));
	//printf("%s\n", strcat(str1,str2));
	//printf("%s\n", my_strncpy(str1, str2,3));
	printf("%s\n", my_strstr(str1, str2));
	system("pause");
	return 0;



}








