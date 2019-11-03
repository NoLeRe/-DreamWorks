#include<stdio.h>
#pragma warning(disable:4996)

//int fla(int n)
//{
//	
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//		return fla(n - 1) + fla(n-2);
//		
//}
//int fia(int n)
//{
//	int a=1, b=1, c=0;
//	
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		for (int i = 0; i < n-2; i++)
//		{
//			c = a + b;
//			a = b;
//			b = c;
//		}
//		return c;
//	}
//}
int main()
{
	int n;
	printf("第几个数： ");
	scanf("%d", &n);
	printf("%d\n", fla(n));
	printf("%d\n", fia(n));
	system("pause");
	return 0;
	
}