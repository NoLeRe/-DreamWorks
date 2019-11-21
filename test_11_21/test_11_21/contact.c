#include"contact.h"



void init_contact(pcontact pc)
{
	pc->size = 0;
	pc->data = (info*)malloc(sizeof(info)* DEFAULT);
	pc->capcity = DEFAULT;
}

int capcity(pcontact pc)
{
	if (pc->size == pc->capcity)
	{
		pc->data = (info*)realloc(pc->data, pc->capcity + 10);
		if (pc->data == NULL)
		{
			return 0;
		}
	}
	return 1;
}



void add_contact(pcontact pc)
{
	info cur;
	if (capcity(pc) == 0)
	{
		printf("人员已满！添加失败！\n");
	}
	printf("请输入姓名-》：\n");
	scanf("%s", cur.name);
	printf("请输入性别-》：\n");
	scanf("%s", cur.gender);
	printf("请输入年龄-》：\n");
	scanf("%d", &cur.age);
	printf("请输入号码-》：\n");
	scanf("%s", cur.tele);
	printf("请输入地址-》：\n");
	scanf("%s", cur.addr);
	pc->data[pc->size] = cur;
	pc->size++;
}

void del_contact(pcontact pc)
{
	char name[NAME_MAX];
	printf("请输入要删除的名字-》:\n");
	scanf("%s", name);
	int pos = find(pc, name);
	if (pos == -1)
	{
		printf("查无此人！\n");
		return;
	}
	else
	{
		pc->data[pos] = pc->data[pos + 1];
	}
	pc->size--;
	printf("删除完成！\n");	
}

int find(pcontact pc,char *name)
{
	for (int i = 0; i < pc->size; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
			return i;
	}
	return -1;

}

void ser_contact(pcontact pc)
{
	char name[NAME_MAX];
	printf("请输入要查找的名字-》:\n");
	scanf("%s", name);
	int pos = find(pc, name);
	if (pos == -1)
	{
		printf("查无此人！\n");
		return;
	}
	else
	{
		printf("=====================\n");
		printf("姓名：%s \n", pc->data[pos].name);
		printf("性别：%s \n", pc->data[pos].gender);
		printf("年龄：%d \n", pc->data[pos].age);
		printf("电话：%s \n", pc->data[pos].tele);
		printf("住址：%s \n", pc->data[pos].addr);
		printf("=====================\n");
	}
}

void mod_contact(pcontact pc)
{
	char name[NAME_MAX];
	printf("请输入要修改的联系人-》：\n");
	scanf("%s", name);
	int pos = find(pc, name);
	if (pos == -1)
	{
		printf("查无此人！\n");
	}
	else
	{
		printf("请输入姓名-》：\n");
		scanf("%s", pc->data[pos].name);
		printf("请输入性别-》：\n");
		scanf("%s", pc->data[pos].gender);
		printf("请输入年龄-》：\n");
		scanf("%d", &pc->data[pos].age);
		printf("请输入号码-》：\n");
		scanf("%s", pc->data[pos].tele);
		printf("请输入地址-》：\n");
		scanf("%s", pc->data[pos].addr);
	}
	printf("修改完成！\n");
}

void qsort(pcontact pc)
{
	for (int i = 0; i < pc->size; i++)
	{
		for (int j = 0; j < pc->size - 1; j++)
		{
			if (strcmp(pc->data[j].name, pc->data[j + 1].name)>0)
			{
				info ret = pc->data[j];
				pc->data[j] = pc->data[j + 1];
				pc->data[j + 1] = ret;
			}

		}
	}

}

void load_contact(pcontact pc)
{
	FILE* pf = fopen("contact.dat", "rb");
	if (pf == NULL)
	{
		printf("打开文件失败！\n");
		return;
	}
	info curinfo;
	while (fread(&curinfo, sizeof(info), 1, pf))
	{
		if (capcity(pc))
		{
			pc->data[pc->size] = curinfo;
			pc->size++;
		}
	}
	fclose(pf);
}
void save_contact(pcontact pc)
{
	FILE* pf = fopen("contact.dat", "wb");
	if (pf == NULL)
	{
		printf("打开文件失败！\n");
		return;
	}
	for (int i = 0; i < pc->size; i++)
	{
		fwrite(pc->data + i, sizeof(info), 1, pf);

	}
	fclose(pf);
}
void check_contact(pcontact pc)
{

	qsort(pc);
	for (int i = 0; i < pc->size; i++)
	{
		printf("=========================\n");
		printf("姓名：%s\n", pc->data[i].name);
		printf("性别：%s\n", pc->data[i].gender);
		printf("年龄：%d\n", pc->data[i].age);
		printf("电话号码：%s\n", pc->data[i].tele);
		printf("地址：%s\n", pc->data[i].addr);
		printf("=========================\n");
		printf("\n");
	}
}