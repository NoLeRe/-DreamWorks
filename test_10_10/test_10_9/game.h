#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning (disable:4996)

#define ROW 3
#define COL 3

void menu();
void intboard(char board[ROW][COL], int row, int col);
void printboard(char board[ROW][COL], int row, int col);
void playermove(char board[ROW][COL], int row, int col);
void commove(char board[ROW][COL],int row, int col);
int full(char board[ROW][COL], int row, int col);
char win(char board[ROW][COL], int row, int col);
void game(char board[ROW][COL]);
