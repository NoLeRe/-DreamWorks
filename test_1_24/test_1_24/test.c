#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#pragma warning(disable: 4996)

void color(int m)   /*ÉèÖÃÑÕÉ«*/
{
	HANDLE hconsole;
	hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hconsole, m);
}
int map_a[10][10] = {
	{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 0, 1, 1, 1, 0, 0, 0, 0, 1, 1 },
	{ 1, 1, 4, 0, 3, 1, 1, 0, 1, 1 },
	{ 1, 4, 4, 3, 0, 3, 0, 0, 2, 1 },
	{ 1, 4, 4, 0, 3, 0, 3, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 0, 0, 0, 1 },
	{ 0, 0, 0, 0, 0, 1, 1, 1, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};
int map_2[10][10] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
	{ 0, 0, 1, 4, 4, 1, 0, 0, 0, 0 },
	{ 1, 1, 1, 0, 4, 1, 1, 1, 0, 0 },
	{ 1, 0, 0, 0, 3, 4, 4, 1, 0, 0 },
	{ 1, 0, 0, 3, 0, 0, 0, 1, 0, 0 },
	{ 1, 0, 0, 1, 3, 3, 3, 1, 0, 0 },
	{ 1, 0, 0, 2, 0, 0, 0, 1, 0, 0 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

};

void transform(int map[][10])
{
	int i, j;

	for (i = 0; i<10; i++)
	{
		for (j = 0; j<10; j++)
		{
			switch (map[i][j])
			{
			case 0:
				printf("  ");  //¿ÕµØ 
				break;
			case 1:          //×©¿é 
				printf("¡ö");
				break;
			case 2:           //ÈËÎï 
				printf("¡á");
				break;
			case 3:
				printf("¡õ"); //  Ïä×Ó
				break;
			case 4:           //ÐÇÐÇ 
				printf("¡î");
				break;
			case 5:           //³É¹¦ 
				printf("¡ï");
				break;
			case 6:
				printf("¡â");   //±ê¼ÇÈËÎï
				break;

			}

		}
		printf("\n");
	}
}

int gameover(int map[][10])
{
	int i, j;
	int com = 5;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (map[i][j] == 5)
				com--;
		}
	}
	return com;

}
void keyboard(int map[][10])      //ÒÆ¶¯ 
{
	int i, j;
	char pos;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (map[i][j] == 2 || map[i][j] == 6)
				break;
		}
		if (map[i][j] == 2 || map[i][j] == 6)
			break;
	}
	pos = getch();
	switch (pos)
	{
	case 'w':
		//ÈËÇ°ÃæÊÇ¿ÕµØ
		if (map[i - 1][j] == 0)
		{
			map[i - 1][j] = 2;
			if (map[i][j] == 6)
				map[i][j] = 4;
			else
				map[i][j] = 0;
		}
		//ÈËÇ°ÃæÊÇ±ê¼Ç
		if (map[i - 1][j] == 4)
		{
			map[i - 1][j] = 6;
			if (map[i][j] == 6)
				map[i][j] = 4;
			else
				map[i][j] = 0;
		}
		//ÈËÇ°ÃæÊÇÒ»¸öÏä×Ó
		if (map[i - 1][j] == 3)
		{
			//Ïä×ÓÇ°ÃæÊÇ¿ÕµØ
			if (map[i - 2][j] == 0)
			{
				map[i - 2][j] = 3;
				map[i - 1][j] = 2;
				if (map[i][j] == 6)
					map[i][j] = 4;
				else
					map[i][j] = 0;
			}
			//Ïä×ÓÇ°ÃæÊÇ±ê¼Ç
			if (map[i - 2][j] == 4)
			{
				map[i - 2][j] = 5;
				map[i - 1][j] = 2;
				if (map[i][j] == 6)
					map[i][j] = 4;
				else
					map[i][j] = 0;
			}
		}
		//ÈËÇ°ÃæÊÇÒ»¸öÍê³ÉµÄÏä×Ó
		if (map[i - 1][j] == 5)
		{  //Íê³ÉÏäÇ°ÃæÊÇÒ»¸ö¿ÕµØ
			if (map[i - 2][j] == 0)
			{
				map[i - 2][j] = 3;
				map[i - 1][j] = 6;
				if (map[i][j] = 6)
					map[i][j] = 4;
				else
					map[i][j] = 0;
			}
			//Íê³ÉÏäÇ°ÃæÊÇÒ»¸ö±ê¼Ç
			if (map[i - 2][j] == 4)
			{
				map[i - 2][j] = 5;
				map[i - 1][j] = 6;
				if (map[i][j] == 6)
					map[i][j] = 4;
				else
					map[i][j] = 0;
			}
		}
		break;
	case 's':
		//ÈËÏÂÃæÊÇ¿ÕµØ
		if (map[i + 1][j] == 0)
		{
			map[i + 1][j] = 2;
			if (map[i][j] == 6)
				map[i][j] = 4;
			else
				map[i][j] = 0;
		}
		//ÈËÏÂÃæÊÇ±ê¼Ç
		if (map[i + 1][j] == 4)
		{
			map[i + 1][j] = 6;
			if (map[i][j] == 6)
				map[i][j] = 4;
			else
				map[i][j] = 0;
		}
		//ÈËÏÂÃæÊÇÒ»¸öÏä×Ó
		if (map[i + 1][j] == 3)
		{
			//Ïä×ÓÏÂÃæÊÇ¿ÕµØ
			if (map[i + 2][j] == 0)
			{
				map[i + 2][j] = 3;
				map[i + 1][j] = 2;
				if (map[i][j] == 6)
					map[i][j] = 4;
				else
					map[i][j] = 0;
			}
			//Ïä×ÓÏÂÃæÊÇ±ê¼Ç
			if (map[i + 2][j] == 4)
			{
				map[i + 2][j] = 5;
				map[i + 1][j] = 2;
				if (map[i][j] == 6)
					map[i][j] = 4;
				else
					map[i][j] = 0;
			}
		}
		//ÈËÏÂÃæÊÇÒ»¸öÍê³ÉµÄÏä×Ó
		if (map[i + 1][j] == 5)
		{  //Íê³ÉÏäÏÂÃæÊÇÒ»¸ö¿ÕµØ
			if (map[i + 2][j] == 0)
			{
				map[i + 2][j] = 3;
				map[i + 1][j] = 6;
				if (map[i][j] = 6)
					map[i][j] = 4;
				else
					map[i][j] = 0;
			}
			//Íê³ÉÏäÏÂÃæÊÇÒ»¸ö±ê¼Ç
			if (map[i + 2][j] == 4)
			{
				map[i + 2][j] = 5;
				map[i + 1][j] = 6;
				if (map[i][j] == 6)
					map[i][j] = 4;
				else
					map[i][j] = 0;
			}
		}
		break;
	case 'a':
		//ÈË×óÃæÊÇ¿ÕµØ
		if (map[i][j - 1] == 0)
		{
			map[i][j - 1] = 2;
			if (map[i][j] == 6)
				map[i][j] = 4;
			else
				map[i][j] = 0;
		}
		//ÈË×óÃæÊÇ±ê¼Ç
		if (map[i][j - 1] == 4)
		{
			map[i][j - 1] = 6;
			if (map[i][j] == 6)
				map[i][j] = 4;
			else
				map[i][j] = 0;
		}
		//ÈË×óÃæÊÇÒ»¸öÏä×Ó
		if (map[i][j - 1] == 3)
		{
			//Ïä×Ó×óÃæÊÇ¿ÕµØ
			if (map[i][j - 2] == 0)
			{
				map[i][j - 2] = 3;
				map[i][j - 1] = 2;
				if (map[i][j] == 6)
					map[i][j] = 4;
				else
					map[i][j] = 0;
			}
			//Ïä×Ó×óÃæÊÇ±ê¼Ç
			if (map[i][j - 2] == 4)
			{
				map[i][j - 2] = 5;
				map[i][j - 1] = 2;
				if (map[i][j] == 6)
					map[i][j] = 4;
				else
					map[i][j] = 0;
			}
		}
		//ÈË×óÃæÊÇÒ»¸öÍê³ÉµÄÏä×Ó
		if (map[i][j - 1] == 5)
		{  //Íê³ÉÏä×óÃæÊÇÒ»¸ö¿ÕµØ
			if (map[i][j - 2] == 0)
			{
				map[i][j - 2] = 3;
				map[i][j - 1] = 6;
				if (map[i][j] = 6)
					map[i][j] = 4;
				else
					map[i][j] = 0;
			}
			//Íê³ÉÏä×óÃæÊÇÒ»¸ö±ê¼Ç
			if (map[i][j - 2] == 4)
			{
				map[i][j - 2] = 5;
				map[i][j - 1] = 6;
				if (map[i][j] == 6)
					map[i][j] = 4;
				else
					map[i][j] = 0;
			}
		}
		break;
	case 'd':
		//ÈË×óÃæÊÇ¿ÕµØ
		if (map[i][j + 1] == 0)
		{
			map[i][j + 1] = 2;
			if (map[i][j] == 6)
				map[i][j] = 4;
			else
				map[i][j] = 0;
		}
		//ÈË×óÃæÊÇ±ê¼Ç
		if (map[i][j + 1] == 4)
		{
			map[i][j + 1] = 6;
			if (map[i][j] == 6)
				map[i][j] = 4;
			else
				map[i][j] = 0;
		}
		//ÈË×óÃæÊÇÒ»¸öÏä×Ó
		if (map[i][j + 1] == 3)
		{
			//Ïä×Ó×óÃæÊÇ¿ÕµØ
			if (map[i][j + 2] == 0)
			{
				map[i][j + 2] = 3;
				map[i][j + 1] = 2;
				if (map[i][j] == 6)
					map[i][j] = 4;
				else
					map[i][j] = 0;
			}
			//Ïä×Ó×óÃæÊÇ±ê¼Ç
			if (map[i][j + 2] == 4)
			{
				map[i][j + 2] = 5;
				map[i][j + 1] = 2;
				if (map[i][j] == 6)
					map[i][j] = 4;
				else
					map[i][j] = 0;
			}
		}
		//ÈË×óÃæÊÇÒ»¸öÍê³ÉµÄÏä×Ó
		if (map[i][j + 1] == 5)
		{  //Íê³ÉÏä×óÃæÊÇÒ»¸ö¿ÕµØ
			if (map[i][j + 2] == 0)
			{
				map[i][j + 2] = 3;
				map[i][j + 1] = 6;
				if (map[i][j] = 6)
					map[i][j] = 4;
				else
					map[i][j] = 0;
			}
			//Íê³ÉÏä×óÃæÊÇÒ»¸ö±ê¼Ç
			if (map[i][j + 2] == 4)
			{
				map[i][j + 2] = 5;
				map[i][j + 1] = 6;
				if (map[i][j] == 6)
					map[i][j] = 4;
				else
					map[i][j] = 0;
			}
		}
		break;
	}
}

int main()
{
	system("mode con cols=22 lines=11");
	int x;
	printf("  ****************\n");
	printf("   ÍÆÏä×ÓÐ¡ÓÎÏ·            \n");
	printf("   1.¿ªÊ¼ÓÎÏ·              \n");
	printf("   2.ÍË³öÓÎÏ·                   \n  ");
	printf("***************\n");
	printf("ÇëÑ¡Ôñ£º1  OR  2  \n");
	scanf("%d", &x);
	fflush(stdout);
	switch (x)
	{
	case 1:
		while (1)
		{
			system("cls");
			transform(map_a);
			if (gameover(map_a) == 0)
			{
				while (1)
				{
					system("cls");
					transform(map_2);
					if (gameover(map_2) == 0)
						printf("¹§Ï²Í¨¹Ø£¡\n");
					keyboard(map_2);
				}
			}
			keyboard(map_a);

		}
		break;
	case 2: system("cls");
		break;
	default:
		printf("ÇëÑ¡ÔñÕýÈ·Ñ¡Ïî\n");
		break;
	}
	return 0;
}