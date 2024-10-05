#include "game.h"

	//初始化棋盘
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

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		//边界符号由列来控制
		for (j = 0; j < col; j++)
		{
			printf(" %c ",board[i][j]);
			//最后一列边上不需要边界符
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//2,打印分割行
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

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0; //x,y来确定坐标
	int y = 0;
	printf("玩家走:>\n");
	while (1)
	{
		printf("输入下棋坐标\n");
		scanf("%d%d", &x, &y);
		//判断x,y坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//判断x,y是否重复
			if (board[x-1][y-1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				//落子结束跳出，电脑下棋
				break;
			}
			else
			{
				printf("该坐标被占用\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");

		}
	}
}

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走>\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		//若生成坐标合法，下棋并跳出
		//不合法继续随机生成
		if (board[x][y] == ' ')
		{
			board[x][y] = '@';
			break;
		}
	}
}

//判断棋盘满格1 满 0未满
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

//判断输赢
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//横三行判断
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//竖三列判断
	for (i = 0;i < col ; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//对角线判断
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	//如果都没有返回，并且棋盘满格，那么就是平局
	if (1 == IsFull(board,ROW,COL))
	{
		return 'Q';
	}
	return 'C';
}