#include"contact.h"

enum cat
{
	eit,
	add,
	del,
	ser,
	change,
	inint,
	check,
	load,
	save

};

void menu()
{
	printf("============================\n");
	printf("==0.�˳�======1.���========\n");
	printf("==2.ɾ��======3.����========\n");
	printf("==4.����======5.���========\n");
	printf("==6.�鿴======7.����========\n");
	printf("==8.�洢====================\n");
}

int main()
{
	contact ct;
	int n;
	init_contact(&ct);
	do{
		menu();
		printf("��ѡ��ѡ�-�� ");
		scanf("%d", &n);
		switch (n)
		{
		case eit:
			break;
		case add:
			add_contact(&ct);
			break;
		case del:
			del_contact(&ct);
			break;
		case ser:
			ser_contact(&ct);
			break;
		case change:
			mod_contact(&ct);
			break;
		case inint:
			init_contact(&ct);
			break;
		case check:
			check_contact(&ct);
			break;
		case load:
			load_contact(&ct);
			break;
		case save:
			save_contact(&ct);
			break;
		default:
			printf("��Чѡ����������룺\n");
			break;
		}

	} while (n);


	system("pause");
	return 0;
}