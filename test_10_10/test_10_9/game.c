#include "game.h"
void menu()
{
	printf("******************************\n");
	printf("*******  1.��ʼ��Ϸ  *********\n");
	printf("*******  0.�˳���Ϸ  *********\n");
	printf("******************************\n");
	printf("��ѡ��> ");

}
void intboard(char board[ROW][COL], int row,int col)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void printboard(char board[ROW][COL], int row, int col)
{
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (j < col - 1)
				printf(" %c |", board[i][j]);
			else
				printf(" %c ", board[i][j]);
	
		}
		printf("\n");
		if (i < row - 1)
		{
			for (int k = 0; k < col; k++)
			{
				if (k < col - 1)
					printf("- -|");
				else
					printf("- -");
			}
		}
		printf("\n");
	}
}
void playermove(char board[ROW][COL],int row,int col)
{
	int x, y;
	while (1)
	{
		printf("�������������꣺> ");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= row&&y > 0 && y <= col)
		{
			if (board[x-1][y-1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("��λ����ռ�ã����������룡\n");
			}
		}
		else
			printf("�������������꣡\n");
	}
}
void commove(char board[ROW][COL],int row,int col)
{
	int x, y;
	printf("�����ߣ�>\n");
	while (1)
	{
		x = rand() % row+1;
		y = rand() % col+1;
		if (x > 0 && x <= row&&y > 0 && y <= col)
		{
			if (board[x-1][y-1] == ' ')
			{
				board[x - 1][y - 1] = '#';
				break;
			}
		}		
	}
}
int full(char board[ROW][COL],int row,int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char win(char board[ROW][COL], int row, int col)
{
	int i;
	//�ж���
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	//�ж���
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	//б�Խ�
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
	printboard(board, ROW, COL);
	while (1)
	{
		
		playermove(board, ROW, COL);
		ret = win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		commove(board, ROW, COL);
		printboard(board, ROW, COL);
		ret = win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		
	}
		if (ret == '*')
		{
			printf("��һ�ʤ��\n");

		}
		else if (ret == '#')
		{
			printf("���Ի�ʤ��\n");
			
		}
		else if (ret == 'Q')
		{
			printf("ƽ�֣�\n");
			
		}
}
