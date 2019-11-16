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
		printf("��Ա���������ʧ�ܣ�\n");
		return;
	}
	printf("������������\n");
	scanf("%s", cur.name);
	printf("�������Ա�\n");
	scanf("%s", cur.gender);
	printf("���������䣺\n");
	scanf("%d", &cur.age);
	printf("��������룺\n");
	scanf("%s", cur.tele);
	printf("�������ַ��\n");
	scanf("%s", cur.addr);
	pc->data[pc->size] = cur;
	pc->size++;

}
void del_contact(pcontact pc)
{
	char name[name_MAX];
	printf("������Ҫɾ����������\n");
	scanf("%s", name);
	int pos = find_contact(pc, name);
	if (pos == -1)
	{
		printf("���޴��ˣ�ɾ��ʧ��\n");
		return;
	}
	for (int i = pos; i < pc->size; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->size--;
	printf("ɾ����ɣ�\n");
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
	printf("����������Ҫ���ҵ�������\n");
	scanf("%s", name);
	int pos = find_contact(pc, name);
	if (pos == -1)
	{
		printf("���޴��ˣ�\n");
		return;
	}
	printf("=========================\n");
	printf("������%s\n", pc->data[pos].name);
	printf("�Ա�%s\n", pc->data[pos].gender);
	printf("���䣺%d\n", pc->data[pos].age);
	printf("�绰���룺%s\n", pc->data[pos].tele);
	printf("��ַ��%s\n", pc->data[pos].addr);
	printf("=========================\n");

}
void mod_contact(pcontact pc)
{
	char name[name_MAX];
	printf("����������Ҫ�޸ĵ�������\n");
	scanf("%s", name);
	int pos = find_contact(pc, name);
	if (pos == -1)
	{
		printf("���޴��ˣ��޸�ʧ�ܣ�\n");
		return;
	}
	printf("������������\n");
	scanf("%s", pc->data[pos].name);
	printf("�������Ա�\n");
	scanf("%s", pc->data[pos].gender);
	printf("���������䣺\n");
	scanf("%d", &pc->data[pos].age);
	printf("��������룺\n");
	scanf("%s", pc->data[pos].tele);
	printf("�������ַ��\n");
	scanf("%s", pc->data[pos].addr);

}