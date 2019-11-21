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
		printf("��Ա���������ʧ�ܣ�\n");
	}
	printf("����������-����\n");
	scanf("%s", cur.name);
	printf("�������Ա�-����\n");
	scanf("%s", cur.gender);
	printf("����������-����\n");
	scanf("%d", &cur.age);
	printf("���������-����\n");
	scanf("%s", cur.tele);
	printf("�������ַ-����\n");
	scanf("%s", cur.addr);
	pc->data[pc->size] = cur;
	pc->size++;
}

void del_contact(pcontact pc)
{
	char name[NAME_MAX];
	printf("������Ҫɾ��������-��:\n");
	scanf("%s", name);
	int pos = find(pc, name);
	if (pos == -1)
	{
		printf("���޴��ˣ�\n");
		return;
	}
	else
	{
		pc->data[pos] = pc->data[pos + 1];
	}
	pc->size--;
	printf("ɾ����ɣ�\n");	
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
	printf("������Ҫ���ҵ�����-��:\n");
	scanf("%s", name);
	int pos = find(pc, name);
	if (pos == -1)
	{
		printf("���޴��ˣ�\n");
		return;
	}
	else
	{
		printf("=====================\n");
		printf("������%s \n", pc->data[pos].name);
		printf("�Ա�%s \n", pc->data[pos].gender);
		printf("���䣺%d \n", pc->data[pos].age);
		printf("�绰��%s \n", pc->data[pos].tele);
		printf("סַ��%s \n", pc->data[pos].addr);
		printf("=====================\n");
	}
}

void mod_contact(pcontact pc)
{
	char name[NAME_MAX];
	printf("������Ҫ�޸ĵ���ϵ��-����\n");
	scanf("%s", name);
	int pos = find(pc, name);
	if (pos == -1)
	{
		printf("���޴��ˣ�\n");
	}
	else
	{
		printf("����������-����\n");
		scanf("%s", pc->data[pos].name);
		printf("�������Ա�-����\n");
		scanf("%s", pc->data[pos].gender);
		printf("����������-����\n");
		scanf("%d", &pc->data[pos].age);
		printf("���������-����\n");
		scanf("%s", pc->data[pos].tele);
		printf("�������ַ-����\n");
		scanf("%s", pc->data[pos].addr);
	}
	printf("�޸���ɣ�\n");
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
		printf("���ļ�ʧ�ܣ�\n");
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
		printf("���ļ�ʧ�ܣ�\n");
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
		printf("������%s\n", pc->data[i].name);
		printf("�Ա�%s\n", pc->data[i].gender);
		printf("���䣺%d\n", pc->data[i].age);
		printf("�绰���룺%s\n", pc->data[i].tele);
		printf("��ַ��%s\n", pc->data[i].addr);
		printf("=========================\n");
		printf("\n");
	}
}