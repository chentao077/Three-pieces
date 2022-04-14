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
		//��ӡһ��
		int j = 0;
		for ( j = 0; j < col; j++)
		//��ӡһ��
		{
			printf(" %c ", broad[i][j]);
			//��ӡ�ָ��
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
			//��ӡ�ָ���
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
void PlayerMove(char broad[ROW][COL], int row, int col)//�����
{
	printf("�����"); 
	int x = 0;
	int y = 0;
	//�ж�����ĺϷ���
	while (1)
	{
		printf("������Ҫ�µ�����");
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
				printf("�����ѱ�ռ��\n");
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}
}
//������
void ComputerMove(char broad[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("������\n");
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
//�ж������Ƿ��Ѿ�����
//����0��ʾû����
//����1��ʾ�Ѿ�����
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
//*���Ӯ  #����Ӯ  ��c������  ��q��ƽ��
{
	//���������
	int i = 0;
	for ( i = 0; i < row; i++)
	{
		if (broad[i][0] == broad[i][1] && broad[i][0] == broad[i][2] && broad[i][0] != ' ')
		{
			return broad[i][1];
		}
	}
	//�������
	for ( i = 0; i < col; i++)
	{
		if (broad[0][i] == broad[1][i] && broad[0][i] == broad[2][i] && broad[0][i] != ' ')
		{
			return broad[0][i];
		}
	}
	//��б�����
	if (broad[0][0] == broad[1][1] && broad[0][0] == broad[2][2] && broad[0][0] != ' ')
	{
		return broad[0][0];
	}
	if (broad[0][2] == broad[1][1] && broad[0][2] == broad[2][0] && broad[0][2] != ' ')
	{
		return broad[0][2];
	}
	//�ж��Ƿ�ƽ��
	if (IsFull(broad,ROW,COL) == 1)
	{
		return 'q';
	}
	return 'c';
}