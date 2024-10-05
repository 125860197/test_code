//测试文件
#include "game.h"

//主菜单
void menu()
{
	printf("********************\n");
	printf("****1.play 0.exit****\n");
	printf("********************\n");
}

//游戏主体
void game()
{
	//存放游戏结束状态
	char ret = 0;
	//数组-存放棋盘信息
	char board[ROW][COL] = {0};
	//初始化数组
	InitBoard(board,ROW,COL);
	//打印棋盘
	DisplayBoard(board,ROW,COL);
	//下棋
	while (1)
	{
		//玩家下棋
		PlayerMove(board,ROW,COL);
		//显示棋盘状态
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢
		ret = IsWin(board, ROW, COL);
		if(ret !='C')
		{
			break;
		}
		//电脑下棋
		ComputerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否赢
		ret =IsWin(board,ROW,COL);
		if (ret !='C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家获胜\n");
	}
	else if(ret =='@')
	{
		printf("电脑获胜\n");
	}
	else
	{
		printf("平局\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int) time(NULL));
	do
	{
		menu();
		printf("请输入\n");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
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