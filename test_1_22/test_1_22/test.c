#include<stdio.h>
#include <assert.h>
#include <string.h>

//char* my_strcat(char* dst, const char* src)
//{
//	assert(dst && dst);
//	char* ret = dst;
//
//	while (*dst != '\0')
//	{
//		++dst;
//	}
//
//	while (*dst++ = *src++);
//	//while (*src != '\0')
//	//{
//	//	*dst = *src;
//	//	++dst;
//	//	++src;
//	//}
//
//	//*dst = *src;
//
//	return ret;
//}
//
//int main()
//{
//	char* p1 = "hello";
//	char p2[12] = "world";
//	p2[10] = '1';
//
//	//strcpy(p2, p1);
//	my_strcat(p2, p1); // ×·¼Ó Æ´½Ó
//
//	return 0;
//}

int my_strcmp(const char* str1, const char* str2)
{
	int ret = 0;
	assert(str1 && str2);
	const char* s1 = str1;
	const char* s2 = str2;

	while (*s1 && *s2)
	{
		if (*s1 > *s2)
		{
			return 1;
		}
		else if (*s1 < *s2)
		{
			return -1;
		}
		else
		{
			++s1;
			++s2;
		}
	}

	// "hello"  "hello"
	// "hello"  "hello1"
	// "hello1" "hello"
	if (*s1 == '\0' && *s2 == '\0')
	{
		return 0;
	}
	else if (*s1 == '\0')
	{
		return -1;
	}
	else
	{
		return 1;
	}

	return ret;
}

//int main()
//{
//	char p1[] = "ÎÒÀ´ÁË";
//	char* p2 = "hello1";
//
//	printf("%d\n", strcmp(p1, p2));
//	printf("%d\n", my_strcmp(p1, p2));
//
//	char p3[] = "ÏëÄã";
//	p3[3] = -30;
//	p3[3] = -31;
//	p3[3] = -32;
//
//	return 0;
//}

//int main()
//{
//	//  int char char* char void*
//	//	0  '\0'  ""    '0'  NULL
//	char* p1 = "worldworld";
//	char p2[100] = "hello";
//	strncpy(p2, p1, 3);
//	printf("%s\n", p2);
//}

//
//	/*char* p1 = "worldworld";
//	char p2[100] = "hello";
//	strncat(p2, p1, 5);
//	printf("%s\n", p2);*/
//
//	//char* p1 = "helloworld";
//	//char* p2 = "hello";
//	//printf("%d\n", strncmp(p1, p2, 6));
//
//	return 0;
//}
//

//const char* my_strstr(const char* src, const char* sub)
//{
//	assert(src && sub);
//
//	const char* srci = src;
//	const char* subi = sub;
//
//	while (*srci != '\0')
//	{
//		while (*srci == *subi && *subi != '\0')
//		{
//			++srci;
//			++subi;
//		}
//
//		if (*subi == '\0')
//		{
//			return src;
//		}
//		else
//		{
//			subi = sub;
//			++src;
//			srci = src;
//		}
//	}
//
//	return NULL;
//}
//
//int main()
//{
//	//char* p1 = "abcde";
//	//char* p2 = "cdeab";
//
//	//char p3[11]; // "abcdeabcde"
//	//strcpy(p3, p1);
//	//strcat(p3, p1);
//
//	//if (my_strstr(p3, p2) != NULL)
//	//{
//	//	printf("ÊÇÐý×ª´®\n");
//	//}
//	//else
//	//{
//	//	printf("²»ÊÇÐý×ª´®\n");
//	//}
//
//	char* p1 = "aaaabcd";
//	char* p2 = "aaab";
//
//	char* pos = strstr(p1, p2);
//	printf("%s\n", pos);
//}
//

#include <stdio.h>
#include <string.h>
#include <errno.h>//±ØÐë°üº¬µÄÍ·ÎÄ¼þ

//int main()
//{
//	FILE * pFile;
//	pFile = fopen("unexist.ent", "r");
//	if (pFile == NULL)
//		printf("Error opening file unexist.ent: %s\n", strerror(errno));
//	//errno: Last error number
//	return 0;
//}

//struct Student
//{
//	char _name[10];
//	int  _age;
//};

//typedef unsigned int size_t;
void* my_memcpy(void* dst, const void* src, size_t num)
{
	assert(dst && src);

	char* str_dst = (char*)dst;
	char* str_src = (char*)src;
	for (size_t i = 0; i < num; ++i)
	{
		str_dst[i] = str_src[i]; // *(str_src+i)
	}

	return dst;
}

// ÄÚ´æÖØµþ
//void* my_memmove(void* dst, const void* src, size_t num)
//{
//	assert(src && dst);
//
//	char* str_dst = (char*)dst;
//	char* str_src = (char*)src;
//	if (dst < src) // Ç°ÖØµþ »òÕß ²»ÖØµþ  ´ÓÇ°Íùºó¿½±´
//	{
//		for (size_t i = 0; i < num; ++i)
//		{
//			str_dst[i] = str_src[i];
//		}
//	}
//	else //ºóÖØµþ »òÕß ²»ÖØµþ  ´ÓºóÍùÇ°¿½±´
//	{
//		for (int i = num-1; i >= 0; --i)
//		{
//			str_dst[i] = str_src[i];
//		}
//	}
//
//	return dst;
//}

//void* my_memmove(void* dst, const void* src, size_t num)
//{
//	assert(src && dst);
//
//	char* str_dst = (char*)dst;
//	char* str_src = (char*)src;
//	if (str_src < str_dst && dst < str_src + num) //ºóÖØµþ  ´ÓºóÍùÇ°¿½±´
//	{
//		for (int i = num - 1; i >= 0; --i)
//		{
//			str_dst[i] = str_src[i];
//		}
//	}
//	else  // Ç°ÖØµþ ²»ÖØµþ ´ÓÇ°Íùºó¿¼
//	{
//		for (size_t i = 0; i < num; ++i)
//		{
//			str_dst[i] = str_src[i];
//		}
//	}
//
//	return dst;
//}

//int main()
//{
//	int a1[10] = { 1, 2, 3, 4, 5 };
//	int a2[10];
//	my_memcpy(a2, a1, 10 * sizeof(int));
//	
//	struct Student s1 = {"peter", 18};
//	//strcpy(s1._name,"peter");
//	//s1._age = 18;
//
//	struct Student s2;
//	//strcpy(s2._name, s1._name);
//	//s2._age = s1._age;
//	my_memcpy(&s2, &s1, sizeof(struct Student));
//
//	int c = 1;
//	float a =111.0, b = 1.11;
//	//scanf("%2d%3f%4f", &c, &a, &b);
//	printf("%d,%f,%f",c, a, b);
//
//	return 0;
//}


//int main()
//{
//	int a1[10] = { 1, 2, 3, 4, 5 };
//	//my_memcpy(a1+3, a1, 5 * sizeof(int));
//	memmove(a1 + 3, a1, 5 * sizeof(int));
//
//	for (size_t i = 0; i < 10; ++i)
//	{
//		printf("%d ", a1[i]);
//	}
//	printf("\n");
//
//	int a3[10] = { 1, 2, 3, 4, 5 };
//	int a4[10];
//	my_memmove(a4, a3, 10 * sizeof(int));
//	for (size_t i = 0; i < 10; ++i)
//	{
//		printf("%d ", a4[i]);
//	}
//	printf("\n");
//
//	return 0;
//}

//struct Student
//{
//	char name[128];
//	int age;
//	char tel[20];
//};
//
//// typedef struct Student S;
//typedef struct Student
//{
//	char name[128];
//	int age;
//	char tel[20];
//}S; // SÊÇ½á¹¹ÌåÀàÐÍ

// ½¨Òé²»ÒªÕâÑùÓÃ
//struct Student
//{
//	char name[128];
//	int age;
//	char tel[20];
//}S, *p, a[10]; // SÊÇstruct StudentÀàÐÍµÄ½á¹¹Ìå±äÁ¿
//
////struct
////{
////	char name[128];
////	int age;
////	char tel[20];
////}S; // SÊÇÎÞÀàÐÍÀàÐÍµÄ½á¹¹Ìå±äÁ¿
//typedef struct Node
//{
//	int data;
//	struct Node* next;
//}Node;
//
//int main()
//{
//	struct Student s;
//
//	return 0;
//}

struct Point
{
	int x;
	int y;
};

typedef struct Student
{
	char name[128];
	int  age;
	char tel[20];
	struct Point p;
}Student;

//int main()
//{
//	struct Point p1;
//	p1.x = 1;
//	p1.x = 2;
//
//	struct Point p2 = {3, 4};
//
//	Student s1;
//	strcpy(s1.name, "peter");
//	s1.age = 18;
//	strcpy(s1.tel, "110");
//	s1.p.x = 1;
//	s1.p.y = 2;
//
//	Student s2 = { "jack", 5, "112", {2,3} };
//	Student copy;
//	memcpy(&copy, &s1, sizeof(Student));
//
//	return 0;
//}

//Á·Ï°1
struct S1
{
	char c1;
	int i;
	char c2;
};

//Á·Ï°2
struct S2
{
	char c1;
	char c2;
	int i;
};

struct S3
{
	double d;
	char c;
	int i;
};

struct S4
{
	char c1;
	struct S3 s3;
	double d;
};

int main()
{
	printf("%d\n", sizeof(struct S1));
	printf("%d\n", sizeof(struct S2));
	printf("%d\n", sizeof(struct S3));
	printf("%d\n", sizeof(struct S4));

	struct S4 s;
	static int n = 10;
	char* p = "hello";

	int* a = (int*)malloc(sizeof(int)* 100);
	free(a);

	return 0;
}