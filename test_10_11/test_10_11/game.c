#include"game.h"

void menu()
{
	printf("****************************\n");
	printf("******** 1.开始游戏 ********\n");
	printf("******** 0.退出游戏 ********\n");
	printf("****************************\n");
}

void initboard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void printfboard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (j < col - 1)
			{
				printf(" %c |", board[i][j]);
			}
			else
				printf(" %c ", board[i][j]);
		}
		printf("\n");
		if (i < row - 1)
		{

			for (int k = 0; k < col; k++)
			{
				if (k < col - 1)
				{
					printf("---|");
				}
				else
				{
					printf("---");
				}

			}
		}
		printf("\n");
	}
}

void playermove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("请输入落子坐标：> ");
	while (1)
	{
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= row&&y > 0 && y <= col&&board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = '*';
			break;
		}
		else
		{
			printf("坐标非法，请重新输入: > ");
		}
	}
}
void commove(char board[ROW][COL], int row, int col)
{

	while (1)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (x > 0 && x <= row&&y > 0 && y <= col&&board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
int full(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char win(char board[ROW][COL], int row, int col)
{
	//判断行
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0]!=' ')
			return board[i][0];
	}
	//判断列
	for (int j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
			return board[0][j];
	}
	//判断对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	{
		return board[0][2];
	}
	if (full(board, ROW, COL) == 1)
	{
		return 'Q';
	}
	return 'C';
}
void game(char board[ROW][COL])
{
	char ret;
	while (1)
	{
		printfboard(board, ROW, COL);
		playermove(board, ROW, COL);
		ret = win(board, ROW, COL);
		if (ret != 'C')
		{
			printfboard(board, ROW, COL);
			break;
		}
		commove(board, ROW, COL);
		ret = win(board, ROW, COL);
		if (ret != 'C')
		{
			printfboard(board, ROW, COL);
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家获胜！\n");
	}
	if (ret == '#')
	{
		printf("电脑获胜！\n");
	}
	if (ret == 'Q')
	{
		printf("平局！\n");
	}
}
