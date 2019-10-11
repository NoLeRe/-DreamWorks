#include"game.h"

int main()
{
	srand((unsigned int)time(NULL));
	char board[ROW][COL] = { 0 };
	int n = 0;
	do
	{
		menu();
		scanf("%d", &n);
		initboard(board, ROW, COL);
		switch (n)
		{
		case 1:
			game(board);
			break;
		case 2:
			break;
		default:
			printf("ÇëÖØĞÂÊäÈë: >\n");
			break;
		}

	} while (n != 0);
	system("pause");
	return 0;
}