#include<stdio.h>
#include<string.h>
#include<assert.h>

#pragma warning(disable:4996)

void change(int *arr,int len)
{
	int *left = arr;
	int *right = arr + len - 1;
	while (left < right)
	{
		if (((*left) % 2 != 0))
			left++;
		else if ((*right) % 2 == 0)
			right--;
		else
		{
			int temp = *left;
			*left = *right;
			*right = temp;
		}
	}
}



int main()
{
	int arr[6] = { 1, 2, 3, 4, 5, 6 };
	change(arr, 6);
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}


void reserve_all(char *start, char *end)
{
	while (start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}

}

void reserve(char *str)
{
	int len = strlen(str);
	reserve_all(str, str + len - 1);
	char *cur = str;
	while (*cur)
	{
		char *start = cur;
		while (*cur != ' '&&*cur!='\0')
		{
			cur++;
		}
		reserve_all(start, cur - 1);
		while (*cur == ' ')
		{
			cur++;
		}
	}
}
int main()
{
	char str[] = "i am a student.";
	reserve(str);
	printf("%s", str);
	system("pause");
	return 0;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int left = 0;
	int right = sizeof(arr) / sizeof(int)-1;
	int key;
	scanf("%d", &key);
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (arr[mid]>key)
		{
			right--;
		}
		else if (arr[mid] < key)
		{
			left++;
		}
		else if (arr[mid] == key)
		{
			printf("下标为：%d \n", mid);
			break;
		}
	}
	if (left >= right)
	{
		printf("未找到该数！\n");
	}
	system("pause");
	return 0;
}

int my_strcmp(const char *str1, const char *str2)
{
	assert(str1&&str2);
	while (*str1&&*str2)
	{
		if (*str1 > *str2)
			return 1;
		else if (*str2 > *str1)
			return -1;
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

char *my_strstr(char *str1, char *str2)
{
	assert(str1&&str2);
	char *start = str2;
	while (*str1)
	{
		char *cur = str1;
		while (*str1 == *str2&&*str2)
		{
			str1++;
			str2++;
		}
		if (*str1 != *str2)
		{
			str1++;
			cur = str1;
			str2 = start;
		}
		else if (*str2 == '\0')
		{
			return cur;
		}
	}
	return NULL;
}

int main()
{
	char str1[] = "abcd";
	char str2[] = "ebcd";
	//printf("%d\n", strcmp(str1, str2));
	//printf("%d\n", my_strcmp(str1, str2));
	printf("%s\n", strstr(str1, str2));
	printf("%s\n", my_strstr(str1, str2));
	system("pause");
	return 0;
}

void seek(int *arr,int len)
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
	int arr[6] = { 1, 1, 2, 2, 3, 4 };
	seek(arr, 6);
	printf("\n");
	system("pause");
	return 0;
}