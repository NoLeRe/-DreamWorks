#include "game.h"

int main()
{
	srand((unsigned)time(NULL));
	int n;
	char ret;
	char board[ROW][COL] = { 0 };
	do
	{
		menu();
		scanf("%d", &n);
		intboard(board, ROW, COL);
		switch (n)
		{
			case 1:
				game(board);
				break;
			case 0:
				break;
			default:
				printf("ÇëÖØĞÂÊäÈë£º>");
				break;
		}
		
	} while (n!=0);
	system("pause");
	return 0;
}