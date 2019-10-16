#include"game.h"

int main()
{
	srand((unsigned int)time(NULL));
	char mine_board[ROWS][COLS] = { 0 };
	char show_board[ROWS][COLS] = { 0 };
	int n;
	do
	{
		menu();
		scanf("%d", &n);
		switch (n)
		{
			case 1:
				game();
				break;
			case 0:
				break;
			default:
				printf("ÇëÖØĞÂÊäÈë£º>");
				break;
		}
	} while (n != 0);
	system("pause");
	return 0;
}