#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

#define ROW 6
#define COL 6
#define MODE 5

void menu();
void initboard(char board[ROW][COL], int row, int col);
void printfboard(char board[ROW][COL], int row, int col);
void playermove(char board[ROW][COL], int row, int col);
void commove(char board[ROW][COL], int row, int col);
int full(char board[ROW][COL], int row, int col);
char win(char board[ROW][COL], int row, int col);
void game(char board[ROW][COL]);