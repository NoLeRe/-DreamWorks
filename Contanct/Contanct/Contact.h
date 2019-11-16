#include<stdio.h>
#include<string.h>

#pragma warning(disable:4996)

#define name_MAX    20
#define gender_MAX  5
#define tele_MAX    12
#define addr_MAX    50
#define data_MAX    200


typedef struct info
{
	char name[name_MAX];
	char gender[gender_MAX];
	int age;
	char tele[tele_MAX];
	char addr[addr_MAX];
}info;

typedef struct contact
{
	info data[data_MAX];
	int size;
}contact, *pcontact;


void init_contact(pcontact pc);//初始化
void add_contact(pcontact pc); //增
void del_contact(pcontact pc); //删
void ser_contact(pcontact pc); //查
void mod_contact(pcontact pc); //改
int  find_contact(pcontact pc, char *name);
