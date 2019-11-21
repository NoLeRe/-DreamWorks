#include<stdio.h>
#include<string.h>
#include<malloc.h>

#pragma warning(disable:4996)

#define NAME_MAX    20
#define GENDER_MAX  5
#define TELE_MAX    12
#define ADDER_MAX   20
#define DEFAULT     10


typedef struct info
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char tele[TELE_MAX];
	char addr[ADDER_MAX];
}info;

typedef struct contact
{
	info *data;
	int size;
	int capcity;
}contact,*pcontact;

void init_contact(pcontact pc); //初始化
void add_contact(pcontact pc);  //增
void del_contact(pcontact pc);  //删
void ser_contact(pcontact pc);  //查
void mod_contact(pcontact pc);  //改
void qsort(pcontact pc);		//排序
int capcity(pcontact pc);       //容量
int find(pcontact pc,char *name);//姓名比对
void load_contact(pcontact pc);
void save_contact(pcontact pc);
