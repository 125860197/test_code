#include "game.h"

	//��ʼ������
void InitBoard(char board[ROW][COL],int row,int col)
{

	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			board[i][j] = ' ';
		}
	}
}

//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		//�߽��������������
		for (j = 0; j < col; j++)
		{
			printf(" %c ",board[i][j]);
			//���һ�б��ϲ���Ҫ�߽��
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//2,��ӡ�ָ���
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if(j < col -1)
					printf("|");
			}
			printf("\n");
		}
	}
}

//�������
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0; //x,y��ȷ������
	int y = 0;
	printf("�����:>\n");
	while (1)
	{
		printf("������������\n");
		scanf("%d%d", &x, &y);
		//�ж�x,y����Ϸ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//�ж�x,y�Ƿ��ظ�
			if (board[x-1][y-1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				//���ӽ�����������������
				break;
			}
			else
			{
				printf("�����걻ռ��\n");
			}
		}
		else
		{
			printf("����Ƿ�������������\n");

		}
	}
}

//��������
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("������>\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		//����������Ϸ������岢����
		//���Ϸ������������
		if (board[x][y] == ' ')
		{
			board[x][y] = '@';
			break;
		}
	}
}

//�ж���������1 �� 0δ��
int IsFull(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	for (i =0 ;i<row;i++)
	{
		for (j = 0;j<col;j++)
		{
			if (board[i][j] == ' ')
			{
				return '0';
			}
		}
	}
	return 1;
}

//�ж���Ӯ
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//�������ж�
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//�������ж�
	for (i = 0;i < col ; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//�Խ����ж�
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	//�����û�з��أ���������������ô����ƽ��
	if (1 == IsFull(board,ROW,COL))
	{
		return 'Q';
	}
	return 'C';
}