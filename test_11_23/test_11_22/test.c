#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<assert.h>

#pragma warning (disable:4996)


//void GetMemory(char **p, int num)
//{ 
//	*p = (char *)malloc(num); 
//} 
//void Test(void) 
//{ 
//	char *str = (char *)malloc(100);  
//	strcpy(str, "hello");  
//	/*free(str);  
//	str = NULL;*/
//	
//		strcat(str, "world");   
//		printf(str); 
//	
//}
//int main()
//{
//	
//	Test();
//	
//	system("pause");
//	return 0;
//}

//void GetMemory(char **p) 
//{
//	*p = (char *)malloc(100); 
//} 
//void Test(void) 
//{
//	char *str = NULL;  
//	GetMemory(&str);  
//	strcpy(str, "hello world");  
//	printf(str);
//}

//void test(int *b)
//{
//	*b = 2;
//}
//int main()
//{
//	int a = 1;
//	test(&a);
//	printf("%d", a);
//	return 0;
//}

void *my_memcpy(void *dst, const void *src, size_t n)
{
	assert(dst&&src);
	char *dst_str = (char *)dst;
	char *src_str = (char *)src;
	while (n--)
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
	if (dst_str < src_str&&dst_str + n-1 >= src_str)
	{
		for (int i = n - 1; i >= 0; i--)
			dst_str[i] = src_str[i];
	}
	else
	{
		for (int i = 0; i < n; i++)
			dst_str[i] = src_str[i];
	}
	return dst;

}

int my_strcmp(const char *str1, const char *str2)
{
	assert(str1&&str2);
	while (*str1&&*str2)
	{
		/*if (*str1>*str2)
		{
			return 1;
		}
		else if (*str1 < *str2)
		{
			return -1;
		}
		else
		{
			str1++;
			str2++;
		}*/
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else if (*str1 > *str2)
			return 1;
		else if (*str1<*str2)
			return -1;
	}
	if (*str1 == '\0'&&*str2=='\0')
		return 0;
	else if (*str2 == '\0')
		return  1;
	else
		return -1;
}

int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int b[3] = { 4, 5, 6 };
	char *c = "ae";
	char *d = "ab";
	//my_memcpy(a, b, sizeof(int)* 3);
	/*my_memmove(a, a+2, sizeof(int)* 1);
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}*/
	printf("%d\n", my_strcmp(c, d));
	system("pause");
	return 0;
}