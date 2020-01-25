#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reserve_string(char* start, char* end)
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
void reserve_all(char* str)
{
	char *cur = str;
	int len = strlen(str);
	reserve_string(str, str + len - 1);
	while (*cur)
	{

		char *start = cur;
		while ((*cur) != ' ' && (*cur) != '\0')
		{
			cur++;
		}
		reserve_string(start, cur - 1);
		while ((*cur) == ' ')
		{
			cur++;
		}
	}

}
int main()
{
	char string[] = "l am a student.";
	reserve_all(string);
	printf("%s\n", string);
	system("pause");
	return 0;
}


