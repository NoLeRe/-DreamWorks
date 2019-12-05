#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)


char * defangIPaddr(char * address){

	int len = strlen(address);
	char *capcity = (char *)malloc(len + 6 + 1);
	char *src = capcity;
	while (*src)
	{
		if (*address != '.')
		{
			*src++ = *address++;
		}
		if (*address == '.')
		{
			*src++ = '[';
			*src++ = '.';
			*src++ = ']';
			address++;
		}
	}
	*src = '\0';
	return capcity;
}
char * defangIPaddr_2(char * address){

	int len = strlen(address);
	char *capcity = (char *)malloc(len + 6 + 1);
	int j = 0;
	for (int i = 0; i<len; i++)
	{

		if (address[i] == '.')
		{
			capcity[j++] = '[';
			capcity[j++] = '.';
			capcity[j++] = ']';
			continue;
		}
		capcity[j++] = address[i];
	}
	capcity[j] = '\0';
	return capcity;
}
int game(int* guess, int guessSize, int* answer, int answerSize){
	int i = guessSize - 1;
	int j = answerSize - 1;
	int count = 0;
	while (guessSize--)
	{
		if (guess[i] == answer[j])
		{
			count++;
		}
		i--;
		j--;
	}
	if (count == 3)
	{
		return count;
	}
	return count;
}
int numJewelsInStones(char * J, char * S){
	int count = 0;
	int len = strlen(J);
	char *str = J;
	while (*S)
	{
		str = J;
		while (*str)
		{
			if (*S == *str)
			{
				count++;
				break;
			}
			else
			{
				str++;
			}
		}
		S++;
	}
	return count;
}

int main()
{
	char *address = "1.1.1.1";
	printf("%s\n", defangIPaddr(address));
	system("pause");
	return 0;
}