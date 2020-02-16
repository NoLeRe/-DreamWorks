#include<stdio.h>
#include<assert.h>
#include<string.h>

#pragma warning(disable:4996)

char *my_strcpy(char *dst, const char *src)
{
	assert(dst&&src);
	char *ret = dst;
	while (*ret++ = *src++);
	return dst;

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

char *my_strstr(const char* dst, const char* src)
{
	assert(dst&&src);
	const char* dsti = dst;
	const char* srci = src;
	while (*dsti != '\0')
	{
		while (*dsti == *srci&&*srci != '\0')
		{
			dsti++;
			srci++;
		}
		if (*srci == '\0')
		{
			return dst;
		}
		else
		{
			srci = src;
			dst++;
			dsti = dst;
		}
	}
	return NULL;

}

char *my_strchr(char *str, char c)
{
	assert(str&&c);
	while (*str != '\0'&&*str != c)
	{
		str++;
	}
	return str;
}

int my_strcmp(const char *str1, const char *str2)
{
	assert(str1&&str2);
	int ret = 0;
	const char* s1 = str1;
	const char* s2 = str2;
	while (*s1&&*s2)
	{
		if (*s1>*s2)
		{
			return 1;
		}
		else if (*s1 < *s2)
		{
			return -1;
		}
		else
		{
			s1++;
			s2++;
		}
	}
	if (*s1 == '\0'&&*s2)
	{
		return -1;
	}
	else if (*s2 == '\0'&&*s2)
	{
		return 1;
	}
	else
		return 0;

	return ret;
}

void *my_memcpy(void *dst, const void *src, size_t n)
{
	assert(dst&&src);
	char *dsti = (char*)dst;
	char *srci = (char*)src;
	for (size_t i = 0; i < n; i++)
	{
		dsti[i] = srci[i];
	}
	return dst;
}
void *my_memmove(void *dst, const void *src, size_t n)
{
	assert(dst&&src);
	char *str_dst = (char *)dst;
	char *str_src = (char *)src;
	if (str_dst > str_src&&str_dst < str_src + n)
	{
		for (int i = n - 1; i >= 0; i--)
			str_dst[i] = str_src[i];
	}
	else
	{
		for (size_t j = 0; j < n; j--)
			str_dst[j] = str_src[j];
	}
	return dst;
}

int main()
{
	char *p1 = "aaabc";
	char *p2 = "ab";
	char *str1 = "hello";
	char str2[20] = "kamenrider";
	int arr1[10] = { 1, 2, 3, 4, 5 };
	//printf("%s\n", my_strcpy(str2, str1));
	//printf("%s\n", my_strcat(str2, str1));
	//printf("%s\n", my_strstr(p1, p2));
	//printf("%s\n", my_strchr(p1, 'b'));
	//printf("%d\n", my_strcmp(p2, p1));
	//printf("%d\n", strcmp(p2, p1));
	//printf("%s\n", memcpy(str2, str1, 6* sizeof(char)));
	//printf("%s\n", my_memcpy(str2, str1, 5 * sizeof(char)));
	my_memmove(arr1 + 3, arr1, 5 * sizeof(int));
	for (size_t i = 0; i < 10; ++i)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}