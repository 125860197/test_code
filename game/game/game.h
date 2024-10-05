#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3
#define COL 3


//棋盘声明
void InitBoard(char board[ROW][COL],int row,int col);

//打印棋盘
void DisplayBoard(char board[ROW][COL],int row,int col);

//玩家
void PlayerMove(char board[ROW][COL],int row,int col);

//电脑
void ComputerMove(char board[ROW][COL],int row, int col);

/*
返回四种状态:玩家赢'*'
			 电脑赢'@'
			 平局--'Q'
			 继续--'C'
*/
char IsWin(char board[ROW][COL],int row, int col);

//判断棋盘是否满格
int IsFull(char board[ROW][COL], int row, int col);