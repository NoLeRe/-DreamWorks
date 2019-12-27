#include<stdio.h>

void test(int** ptr)
{ 
	printf("num = %d\n", **ptr);
}
int main()
{
	/*char a[5] = { 'A', 'B', 'C', 'D' };
	char(*p3)[5] = &a;
	char(*p4)[5] = a;
	printf("%c\n", (*p3+1)[0]);
	printf("%p\n", a+1);*/
	/*int n = 10;
	int*p = &n;
	int **pp = &p;
	test(pp);
	test(&p);
	int a[4] = { 1, 2, 3, 4 };
	int *ptr1 = (int *)(&a + 1);
	int *ptr2 = (int *)((int)a + 1);
	printf("%x,%x", ptr1[-1], *ptr2);*/
	char *c[] = { "ENTER", "NEW", "POINT", "FIRST" };
	char**cp[] = { c + 3, c + 2, c + 1, c };
	char***cpp = cp;
	printf("%s\n", **++cpp); 
	printf("%s\n", *--*++cpp + 3);
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);
	system("pause");
	return 0;
}