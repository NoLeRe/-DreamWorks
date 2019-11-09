#include<stdio.h>
#include<string.h>
#include<math.h>

#pragma warning(disable:4996)


unsigned int reverse_bit(unsigned int value)
{
	int sum = 0;
	for (int i = 0; i <32; i++)
	{
		int ret = ((value >> i) & 1) * pow(2, 31-i);
		sum += ret;
	}
	return sum;
}

int main()
{
	int n;
	scanf("%d", &n);
	int num=reverse_bit(n);
	printf("%u\n", num);
	system("pause");
	return 0;

}

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int num = (a&b) + ((a^b) >> 1);
	//a&b 是将相同位相同数除二取出来，a^b是将相同位不同数取出来  >>1 相当于除二
	printf("%d\n", num);
	system("pause");
	return 0;

}

int main()
{
	int arr[] = { 1, 1, 2, 2, 3, 4, 4, 5, 5 };
	int num = sizeof(arr) / sizeof(int);
	int ret = arr[0];
	for (int i = 1; i < num; i++)
	{
		ret ^= arr[i];
	}
	printf("%d\n", ret);
	system("pause");
	return 0;
}

void reserve_string(char* start, char* end)
{
	while (start<end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

void reserve_all(char* str)
{
	char *cur = str;
	int len = strlen(str);
	reserve_string(str, str + len - 1);
	while (*cur)
	{
		char *start = cur;
		while ((*cur) != ' ' && (*cur) != '\0')
			cur++;
		reserve_string(start, cur - 1);
		while ((*cur) == ' ')
			cur++;
	}
}

int main()
{
	char str[] = "l am a student.";
	printf("%s\n",str);
	reserve_all(str);
	printf("%s\n", str);
	system("pause");
	return 0;

}