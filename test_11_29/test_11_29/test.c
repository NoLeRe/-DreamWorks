#include<stdio.h>
#include<math.h>

#pragma warning(disable:4996)

int main()
{
	int x;
	int count = 0;
	long long num=0;
	scanf("%d", &x);
	int ret = x;
	while (ret)
	{
		ret /= 10;
		count++;
	}
	int p = count;
	if (count == 1)
	{
		return x;
	}
	for (int i = 0; i < count; i++)
	{
		long long ten = 1;

		for (int j = 0; j < p - 1;j++)
		{
			ten = ten * 10;
		}
		long long a = x % 10;
		x  /=10;
		num = a*ten + num;
		p -=1;
	}
	if (num>pow(2, 31) - 1 || num < pow(-2, 31))
	{
		printf("0\n");
	}
	printf("%d\n", num);
	system("pause");
	return 0;
}