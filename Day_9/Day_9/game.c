#include "game.h"

void menu()
{
	printf("*****************************\n");
	printf("*******   1.开始游戏   ******\n");
	printf("*******   0.退出游戏   ******\n");
	printf("*****************************\n");
}

void initboard(char board[ROWS][COLS], char ret, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = ret;
		}
	}
}

void printboard(char board[ROWS][COLS], int rows, int cols)
{
	for (int k = 0; k < rows- 1; k++)
	{
		printf("%d ", k);
	}
	printf("\n");
	for (int i = 1; i < rows-1; i++)
	{
		printf("%d ", i);
		for (int j = 1; j < cols-1;j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void set_mine(char board[ROWS][COLS])
{
	int count = MAX;
	while (count > 0)
	{
		int x = rand() % 9 + 1;
		int y = rand() % 9 + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
		
	}
	
}

int count_boom(char board[ROWS][COLS], int x, int y)//统计坐标周围雷数目的函数
{
	return board[x - 1][y - 1]
		+ board[x][y - 1] + board[x + 1][y - 1]
		+ board[x + 1][y] + board[x + 1][y + 1]
		+ board[x][y + 1] + board[x - 1][y + 1]
		+ board[x - 1][y] - 8 * '0';  //由于数组中存放的是字符'0',周围是8个数字，所以-8*'0'才能返回雷数的int值
}


void game()
{
	int x, y;
	int win = 0;
	char mine_board[ROWS][COLS] = { 0 };
	char show_board[ROWS][COLS] = { 0 };
	initboard(show_board, '*', ROWS, COLS);
	initboard(mine_board, '0', ROWS, COLS);
	set_mine(mine_board);
	//printboard(mine_board, ROWS, COLS);
	printboard(show_board, ROWS, COLS);
	while (1)
	{
		printf("请输入探索坐标：> ");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= ROWS - 2 && y >= 1 && y <= COLS - 2)
		{
			if (mine_board[x][y] == '1')
			{
				printf("你被炸死了！\n");
				break;
			}
			else
			{
				int sum = count_boom(mine_board, x, y);
				show_board[x][y] = sum + '0';
				win++;
				printboard(show_board, ROWS, COLS);
			}
		}
		else
		{
			printf("坐标非法！请重新输入：> ");
		}
		if (win == MAX)
		{
			printf("排雷成功！\n");
			break;
		}
		
	}
}

