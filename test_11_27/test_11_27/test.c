#include<stdio.h>
#include<string.h>
#include<assert.h>

#pragma warning(disable:4996)

void *my_memcpy(void *dst, const void *src, size_t n)
{
	assert(dst&&src);
	char *dst_str = (char *)dst;
	char *src_str = (char *)src;
	for (size_t i = 0; i < n;i++)
	{
		*dst_str = *src_str;
		dst_str++;
		src_str++;
	}

	return dst;
}

void *my_memmove(void *dst, void *src, size_t n)
{
	assert(dst&&src);
	char *dst_str = (char *)dst;
	char *src_str = (char *)src;
	if (dst_str > src_str && (dst_str + n) <= src_str)
	{
		for (size_t i = n; i >= 0; i--)
		{
			dst_str[i] = src_str[i];
		}
	}
	else
	{
		for (size_t i = 0; i < n; i++)
		{
			dst_str[i] = src_str[i];
		}
	}
	return dst;



}

int main()
{
	int a[] = { 1, 2, 3, 4 };
	int b[] = { 5, 6, 7, 8 };
	//my_memcpy(a, b, sizeof(int)* 3);
	my_memmove(a, a + 1, sizeof(int)*2);
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}