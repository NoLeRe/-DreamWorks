#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)


//int main()
//{
//	int a, b;
//	scanf("%d%d", &a, &b);
//	int i = 1;
//	while (1)
//	{
//		if (i%a != 0 || i%b != 0)
//			i++;
//		else
//		{
//
//			printf("%d", i);
//			break;
//		}
//	}
//	system("pause");
//	return 0;
//}
//int main() 
//{ 
//	int a = -1; 
//	signed char b = -1; 
//	unsigned char c = -1; 
//	printf("a=%d,b=%d,c=%d", a, b, c); 
//	system("pause");
//	return 0; 
//}
//int main() 
//{	char a = 128;//4294967168
//	printf("%u\n", a);
//	system("pause");
//	return 0;
//}
//int main()
//{	char a[1000];   
//	int i;     
//	for (i = 0; i<1000; i++)    
//	{ 
//		a[i] = -1 - i;
//	}    
//	printf("%d\n", strlen(a));
//	for (i = 0; i < 256; i++)
//	{
//		printf("%d\n", a[i]);
//	}
//	system("pause");
//	return 0;
//}
//unsigned char i = 0; 
//int main() 
//{ for (i = 0; i <= 255; i++)    
//{ 
//	printf("hello world\n"); 
//}   
//system("pause");
//return 0;
//}

int main()
{
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	printf("%d\n", strlen(arr)); 
	printf("%d\n", strlen(arr + 0)); 
	printf("%d\n", strlen(*arr)); 
	printf("%d\n", strlen(arr[1])); 
	printf("%d\n", strlen(&arr)); 
	printf("%d\n", strlen(&arr + 1)); 
	printf("%d\n", strlen(&arr[0] + 1));
	system("pause");
	return 0;
}
