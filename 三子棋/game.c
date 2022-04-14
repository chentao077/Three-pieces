#include "game.h"
void IntBroad(char broad[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for ( i = 0; i < row; i++)
	{
		for ( j = 0; j < col; j++)
		{
			broad[i][j] = ' ';
		}
	}

}
void PrintBrod(char broad[ROW][COL], int row, int col)
{
	int i = 0;
	for ( i = 0; i < row; i++)
	{
		//打印一行
		int j = 0;
		for ( j = 0; j < col; j++)
		//打印一列
		{
			printf(" %c ", broad[i][j]);
			//打印分割符
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
			//打印分割行
		{
			for ( j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");

	}
}
void PlayerMove(char broad[ROW][COL], int row, int col)//玩家走
{
	printf("玩家走"); 
	int x = 0;
	int y = 0;
	//判断坐标的合法性
	while (1)
	{
		printf("请输入要下的坐标");
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (broad[x][y] = ' ')
			{
				broad[x-1][y-1] = '*';
				break;
			}
			else
			{
				printf("坐标已被占用\n");
			}
		}
		else
		{
			printf("输入非法，请重新输入\n");
		}
	}
}
//电脑走
void ComputerMove(char broad[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (broad[x][y] == ' ')
		{
			broad[x][y] = '#';
			break;
		}
	}
}
//判读棋盘是否已经满了
//返回0表示没有满
//返回1表示已经满了
int IsFull(char broad[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (broad[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char IsWin(char broad[ROW][COL], int row, int col)
//*玩家赢  #电脑赢  ‘c’继续  ‘q’平局
{
	//三横行相等
	int i = 0;
	for ( i = 0; i < row; i++)
	{
		if (broad[i][0] == broad[i][1] && broad[i][0] == broad[i][2] && broad[i][0] != ' ')
		{
			return broad[i][1];
		}
	}
	//三列相等
	for ( i = 0; i < col; i++)
	{
		if (broad[0][i] == broad[1][i] && broad[0][i] == broad[2][i] && broad[0][i] != ' ')
		{
			return broad[0][i];
		}
	}
	//三斜线相等
	if (broad[0][0] == broad[1][1] && broad[0][0] == broad[2][2] && broad[0][0] != ' ')
	{
		return broad[0][0];
	}
	if (broad[0][2] == broad[1][1] && broad[0][2] == broad[2][0] && broad[0][2] != ' ')
	{
		return broad[0][2];
	}
	//判读是否平局
	if (IsFull(broad,ROW,COL) == 1)
	{
		return 'q';
	}
	return 'c';
}