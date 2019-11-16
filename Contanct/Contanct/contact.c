#include"Contact.h"

void init_contact(pcontact pc)
{
	pc->size = 0;
}

void add_contact(pcontact pc)
{
	info cur;
	if (pc->size == data_MAX)
	{
		printf("人员已满！添加失败！\n");
		return;
	}
	printf("请输入姓名：\n");
	scanf("%s", cur.name);
	printf("请输入性别：\n");
	scanf("%s", cur.gender);
	printf("请输入年龄：\n");
	scanf("%d", &cur.age);
	printf("请输入号码：\n");
	scanf("%s", cur.tele);
	printf("请输入地址：\n");
	scanf("%s", cur.addr);
	pc->data[pc->size] = cur;
	pc->size++;

}
void del_contact(pcontact pc)
{
	char name[name_MAX];
	printf("请输入要删除的姓名：\n");
	scanf("%s", name);
	int pos = find_contact(pc, name);
	if (pos == -1)
	{
		printf("查无此人！删除失败\n");
		return;
	}
	for (int i = pos; i < pc->size; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->size--;
	printf("删除完成！\n");
}

int  find_contact(pcontact pc, char *name)
{
	for (int i = 0; i < pc->size; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;

}
void ser_contact(pcontact pc)
{
	char name[name_MAX];
	printf("请输入你需要查找的姓名：\n");
	scanf("%s", name);
	int pos = find_contact(pc, name);
	if (pos == -1)
	{
		printf("查无此人！\n");
		return;
	}
	printf("=========================\n");
	printf("姓名：%s\n", pc->data[pos].name);
	printf("性别：%s\n", pc->data[pos].gender);
	printf("年龄：%d\n", pc->data[pos].age);
	printf("电话号码：%s\n", pc->data[pos].tele);
	printf("地址：%s\n", pc->data[pos].addr);
	printf("=========================\n");

}
void mod_contact(pcontact pc)
{
	char name[name_MAX];
	printf("请输入你需要修改的姓名：\n");
	scanf("%s", name);
	int pos = find_contact(pc, name);
	if (pos == -1)
	{
		printf("查无此人！修改失败！\n");
		return;
	}
	printf("请输入姓名：\n");
	scanf("%s", pc->data[pos].name);
	printf("请输入性别：\n");
	scanf("%s", pc->data[pos].gender);
	printf("请输入年龄：\n");
	scanf("%d", &pc->data[pos].age);
	printf("请输入号码：\n");
	scanf("%s", pc->data[pos].tele);
	printf("请输入地址：\n");
	scanf("%s", pc->data[pos].addr);

}