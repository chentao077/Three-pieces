#include<stdio.h>
#include<stdio.h>
#include<time.h>


#define ROW 3
#define COL 3	


void IntBroad(char broad[ROW][COL], int row, int col);
void PrintBrod(char broad[ROW][COL], int row, int col);
void PlayerMove(char broad[ROW][COL], int row, int col);
void ComputerMove(char broad[ROW][COL], int row, int col);
char IsWin(char broad[ROW][COL], int row, int col);