#include"Contact.h"

void menu()
{
	printf("============================\n");
	printf("==0.退出======1.添加========\n");
	printf("==2.删除======3.查找========\n");
	printf("==4.更改======5.清空========\n");
	printf("==6.查看====================\n");
	printf("============================\n");
}

int main()
{
	contact ct;
	int n;
	init_contact(&ct);
	do{
		menu();
		printf("请选择选项：-》 ");
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
		case 6:
			check_contact(&ct);
			break;
		default:
			printf("无效选项，请重新输入：\n");
			break;
		}

	} while (n);


	system("pause");
	return 0;
}