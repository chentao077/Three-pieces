#include"game.h"
int ret = 0;
void menu()
{
	printf("#######################\n");
	printf("####1.play  2.exit#####\n");
	printf("#######################\n");
}
void game()//��Ϸ��ʵ��
{
	char broad[ROW][COL] = { '0'};//������ݵ�����
	IntBroad(broad, ROW, COL);//��ʼ������
	PrintBrod(broad, ROW, COL);//��ӡ����
	while (1)//����
	{
		PlayerMove(broad, ROW, COL);//�����
		PrintBrod(broad, ROW, COL);//��ӡ����
		ret = IsWin(broad, ROW, COL);//�ж���Ӯ
		if (ret != 'c')
		{
			break;
		}
		ComputerMove(broad, ROW, COL);//������
		PrintBrod(broad, ROW, COL);//��ӡ����
		ret = IsWin(broad, ROW, COL);//�ж���Ӯ
		if (ret != 'c')
		{
			break;
		}
	}
	if (ret = '#')
	{
		printf("����Ӯ");
	}
	else if (ret = '*')
	{
		printf("���Ӯ");
	}
	else
	{
		printf("ƽ��");

	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}