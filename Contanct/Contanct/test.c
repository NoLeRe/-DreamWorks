#include"Contact.h"

void menu()
{
	printf("============================\n");
	printf("==0.�˳�======1.���========\n");
	printf("==2.ɾ��======3.����========\n");
	printf("==4.����======5.���========\n");
	printf("============================\n");
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
		case 0:
			break;
		case 1:
			add_contact(&ct);
			break;
		case 2:
			del_contact(&ct);
			break;
		case 3:
			ser_contact(&ct);
			break;
		case 4:
			mod_contact(&ct);
			break;
		case 5:
			init_contact(&ct);
			break;
		default:
			break;
		}

	} while (n);


	system("pause");
	return 0;
}