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
	printf("==0.退出======1.添加========\n");
	printf("==2.删除======3.查找========\n");
	printf("==4.更改======5.清空========\n");
	printf("==6.查看======7.加载========\n");
	printf("==8.存储====================\n");
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
			printf("无效选项，请重新输入：\n");
			break;
		}

	} while (n);


	system("pause");
	return 0;
}