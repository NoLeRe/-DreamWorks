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
		if (x > 0 && x <= row&&y > 0 && y <= col&&board[x-1][y-1] == ' ')
		{
			board[x-1][y-1] = '#';
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
char win(char board[ROW][COL], int row, int col,int mode)
{
	int i = 0;
	int j = 0;
	int mode_1 = 0;
	int flag = 0;
	//判断行
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col - 1; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j + 1] != ' ')
				flag++;
			if (flag == mode - 1)
			{
				flag = 0;
				return board[i][j];
			}
		}
		flag = 0;
	}
	//判断列
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < row - 1; j++)
		{
			if (board[j][i] == board[j + 1][i] && board[j + 1][i] != ' ')
				flag++;
			if (flag == mode - 1)
			{
				flag = 0;
				return board[j][i];
			}
		}
		flag = 0;
	}

	//判断对角线
	for (mode_1 = mode - 1; mode_1 < col; mode_1++)
	{
		for (i = 0, j = mode_1; j > 0; i++, j--)
		{
			if (board[i][j] == board[i + 1][j - 1] && board[i][j] != ' ')
				flag++;
			if (flag == mode - 1)
			{
				flag = 0;
				return board[i][j];
			}
		}
		flag = 0;
	}
	for (mode_1 = 1; mode_1 < col - mode + 1; mode_1++)
	{
		for (i = row - 1, j = mode_1; j <col; i--, j++)
		{
			if (board[i][j] == board[i - 1][j + 1] && board[i][j] != ' ')
				flag++;
			if (flag == mode - 1)
			{
				flag = 0;
				return board[i][j];
			}
		}
		flag = 0;
	}

	for (mode_1 = 0; mode_1 < col - mode + 1; mode_1++)
	{
		for (i = 0, j = mode_1; j < col; i++, j++)
		{
			if (board[i][j] == board[i + 1][j + 1] && board[i][j] != ' ')
				flag++;
			if (flag == mode - 1)
			{
				flag = 0;
				return board[i][j];
			}
		}
		flag = 0;
	}
	for (mode_1 = mode - 1; mode_1 < col - 1; mode_1++)
	{
		for (i = row - 1, j = mode_1; j > 0; i--, j--)
		{
			if (board[i][j] == board[i - 1][j - 1] && board[i][j] != ' ')
				flag++;
			if (flag == mode - 1)
			{
				flag = 0;
				return board[i][j];
			}
		}
		flag = 0;
	}
	if (full(board, row, col) == 1)
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
		ret = win(board, ROW, COL,MODE);
		if (ret != 'C')
		{
			printfboard(board, ROW, COL);
			break;
		}
		commove(board, ROW, COL);
		ret = win(board, ROW, COL,MODE);
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
