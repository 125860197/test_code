//�����ļ�
#include "game.h"

//���˵�
void menu()
{
	printf("********************\n");
	printf("****1.play 0.exit****\n");
	printf("********************\n");
}

//��Ϸ����
void game()
{
	//�����Ϸ����״̬
	char ret = 0;
	//����-���������Ϣ
	char board[ROW][COL] = {0};
	//��ʼ������
	InitBoard(board,ROW,COL);
	//��ӡ����
	DisplayBoard(board,ROW,COL);
	//����
	while (1)
	{
		//�������
		PlayerMove(board,ROW,COL);
		//��ʾ����״̬
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if(ret !='C')
		{
			break;
		}
		//��������
		ComputerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ
		ret =IsWin(board,ROW,COL);
		if (ret !='C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("��һ�ʤ\n");
	}
	else if(ret =='@')
	{
		printf("���Ի�ʤ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int) time(NULL));
	do
	{
		menu();
		printf("������\n");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	}
	while (input);
}
int main()
{
	test();
	return 0;
}