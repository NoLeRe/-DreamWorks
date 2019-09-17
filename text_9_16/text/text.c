#include<stdio.h>

int main()
{
	int i, a;
	for ( i = 100; i <= 200; i++)
	{
		for ( a = 2; a<= i; a++)
		{
			if (i % a == 0)
			{
				break;
			}
		 }
		if (a == i)  //第二个循环结束，确定整个循环中没有被i整除
			printf("%d\n", i);
	}
		system("pause");
		return 0;
}

int main()
{
	int i, j, k;
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j < 10; j++)
		{
			k = i*j;
			printf("%d*%d=%d\t",i,j,k );
		}
	}
	system("pause");
	return 0;
}

int main()
{
	int i;
	for (i = 1000; i <= 2000; i++)
	{
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
			printf("%d\t", i);
	}
	system("pause");
	return 0;
}