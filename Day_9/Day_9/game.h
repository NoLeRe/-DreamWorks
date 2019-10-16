#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#pragma warning(disable:4996)

#define ROW 9
#define COL 9
#define ROWS 11
#define COLS 11
#define MAX 10



void menu();
void initboard(char board[ROWS][COLS], char ret, int rows, int cols);
void printboard(int board[ROWS][COLS], int row, int col);
void set_mine(char board[ROWS][COLS]);
int count_boom(char board[ROWS][COLS], int x, int y);
void game();