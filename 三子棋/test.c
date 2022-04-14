#include"game.h"
int ret = 0;
void menu()
{
	printf("#######################\n");
	printf("####1.play  2.exit#####\n");
	printf("#######################\n");
}
void game()//游戏的实现
{
	char broad[ROW][COL] = { '0'};//存放数据的棋盘
	IntBroad(broad, ROW, COL);//初始化棋盘
	PrintBrod(broad, ROW, COL);//打印棋盘
	while (1)//下棋
	{
		PlayerMove(broad, ROW, COL);//玩家走
		PrintBrod(broad, ROW, COL);//打印棋盘
		ret = IsWin(broad, ROW, COL);//判断输赢
		if (ret != 'c')
		{
			break;
		}
		ComputerMove(broad, ROW, COL);//电脑走
		PrintBrod(broad, ROW, COL);//打印棋盘
		ret = IsWin(broad, ROW, COL);//判断输赢
		if (ret != 'c')
		{
			break;
		}
	}
	if (ret = '#')
	{
		printf("电脑赢");
	}
	else if (ret = '*')
	{
		printf("玩家赢");
	}
	else
	{
		printf("平局");

	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}