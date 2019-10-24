#include<stdio.h>
#pragma warning(disable:4996)

int main()
{
	int a, b, c, d, e;
	for (a = 1; a < 6; a++)
	{
		for (b = 1; b < 6; b++)
		{
			for (c = 1; c < 6; c++)
			{
				for (d = 1; d < 6; d++)
				{
					for (e = 1; e < 6; e++)
					{
						if ((a*b*c*d*e == 120) &&
							((b == 2) ^ (a == 3)) &&
							((b == 2) ^ (e == 4)) &&
							((c == 1) ^ (d == 2)) &&
							((d == 3) ^ (c == 5)) &&
							((a == 1) ^ (e == 4))
							)
						{
							printf("A是第%d名，B是第%d名，C是第%d名，D是第%d名,E是第%d名\n", a, b, c, d, e);
						}
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}

int main()
{
	int kill = 0;
	for (kill = 'A'; kill <= 'D'; kill++)
	{
		if (((kill != 'A') + (kill == 'C') + (kill == 'D') + (kill != 'D')) == 3)
			printf("凶手是%c\n", kill);
	}
	system("pause");
	return 0;
}

int main()
{
	int n;
	int arr[10][10];
	printf("请输入你需要的行数(1-10阶)：\n");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		arr[i][0] = 1;
		arr[i][i] = 1;
	}

	for (int i = 2; i < n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}