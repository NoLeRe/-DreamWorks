#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#pragma warning(disable: 4996)

void color(int m)   /*设置颜色*/
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
				printf("  ");  //空地 
				break;
			case 1:          //砖块 
				printf("■");
				break;
			case 2:           //人物 
				printf("♂");
				break;
			case 3:
				printf("□"); //  箱子
				break;
			case 4:           //星星 
				printf("☆");
				break;
			case 5:           //成功 
				printf("★");
				break;
			case 6:
				printf("♀");   //标记人物
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
void keyboard(int map[][10])      //移动 
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
			//人前面是空地
			if (map[i - 1][j] == 0)
			{
				map[i - 1][j] = 2;
				if (map[i][j] == 6)
					map[i][j] = 4;
				else
					map[i][j] = 0;
			}
			//人前面是标记
			if (map[i - 1][j] == 4)
			{
				map[i - 1][j] = 6;
				if (map[i][j] == 6)
					map[i][j] = 4;
				else
					map[i][j] = 0;
			}
			//人前面是一个箱子
			if (map[i - 1][j] == 3)
			{
				//箱子前面是空地
				if (map[i - 2][j] == 0)
				{
					map[i - 2][j] = 3;
					map[i - 1][j] = 2;
					if (map[i][j] == 6)
						map[i][j] = 4;
					else
						map[i][j] = 0;
				}
				//箱子前面是标记
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
			//人前面是一个完成的箱子
			if (map[i - 1][j] == 5)
			{  //完成箱前面是一个空地
				if (map[i - 2][j] == 0)
				{
					map[i - 2][j] = 3;
					map[i - 1][j] = 6;
					if (map[i][j] = 6)
						map[i][j] = 4;
					else
						map[i][j] = 0;
				}
				//完成箱前面是一个标记
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
			//人下面是空地
			if (map[i + 1][j] == 0)
			{
				map[i + 1][j] = 2;
				if (map[i][j] == 6)
					map[i][j] = 4;
				else
					map[i][j] = 0;
			}
			//人下面是标记
			if (map[i + 1][j] == 4)
			{
				map[i + 1][j] = 6;
				if (map[i][j] == 6)
					map[i][j] = 4;
				else
					map[i][j] = 0;
			}
			//人下面是一个箱子
			if (map[i + 1][j] == 3)
			{
				//箱子下面是空地
				if (map[i + 2][j] == 0)
				{
					map[i + 2][j] = 3;
					map[i + 1][j] = 2;
					if (map[i][j] == 6)
						map[i][j] = 4;
					else
						map[i][j] = 0;
				}
				//箱子下面是标记
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
			//人下面是一个完成的箱子
			if (map[i + 1][j] == 5)
			{  //完成箱下面是一个空地
				if (map[i + 2][j] == 0)
				{
					map[i + 2][j] = 3;
					map[i + 1][j] = 6;
					if (map[i][j] = 6)
						map[i][j] = 4;
					else
						map[i][j] = 0;
				}
				//完成箱下面是一个标记
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
			//人左面是空地
			if (map[i][j - 1] == 0)
			{
				map[i][j - 1] = 2;
				if (map[i][j] == 6)
					map[i][j] = 4;
				else
					map[i][j] = 0;
			}
			//人左面是标记
			if (map[i][j - 1] == 4)
			{
				map[i][j - 1] = 6;
				if (map[i][j] == 6)
					map[i][j] = 4;
				else
					map[i][j] = 0;
			}
			//人左面是一个箱子
			if (map[i][j - 1] == 3)
			{
				//箱子左面是空地
				if (map[i][j - 2] == 0)
				{
					map[i][j - 2] = 3;
					map[i][j - 1] = 2;
					if (map[i][j] == 6)
						map[i][j] = 4;
					else
						map[i][j] = 0;
				}
				//箱子左面是标记
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
			//人左面是一个完成的箱子
			if (map[i][j - 1] == 5)
			{  //完成箱左面是一个空地
				if (map[i][j - 2] == 0)
				{
					map[i][j - 2] = 3;
					map[i][j - 1] = 6;
					if (map[i][j] = 6)
						map[i][j] = 4;
					else
						map[i][j] = 0;
				}
				//完成箱左面是一个标记
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
			//人左面是空地
			if (map[i][j + 1] == 0)
			{
				map[i][j + 1] = 2;
				if (map[i][j] == 6)
					map[i][j] = 4;
				else
					map[i][j] = 0;
			}
			//人左面是标记
			if (map[i][j + 1] == 4)
			{
				map[i][j + 1] = 6;
				if (map[i][j] == 6)
					map[i][j] = 4;
				else
					map[i][j] = 0;
			}
			//人左面是一个箱子
			if (map[i][j + 1] == 3)
			{
				//箱子左面是空地
				if (map[i][j + 2] == 0)
				{
					map[i][j + 2] = 3;
					map[i][j + 1] = 2;
					if (map[i][j] == 6)
						map[i][j] = 4;
					else
						map[i][j] = 0;
				}
				//箱子左面是标记
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
			//人左面是一个完成的箱子
			if (map[i][j + 1] == 5)
			{  //完成箱左面是一个空地
				if (map[i][j + 2] == 0)
				{
					map[i][j + 2] = 3;
					map[i][j + 1] = 6;
					if (map[i][j] = 6)
						map[i][j] = 4;
					else
						map[i][j] = 0;
				}
				//完成箱左面是一个标记
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
	printf("   推箱子小游戏            \n");
	printf("   1.开始游戏              \n");
	printf("   2.退出游戏                   \n  ");
	printf("***************\n");
	printf("请选择：1  OR  2  \n");
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
						printf("恭喜通关！\n");
					keyboard(map_2);
				}
			}
			keyboard(map_a);
			
		}
		break;
	case 2: system("cls");
		break;
	default:
		printf("请选择正确选项\n");
		break;
	}
	return 0;
}
