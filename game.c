
#include"game.h"

void init(char board[][ROWS])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < LINE; i++)
	{
		for (j = 0; j < ROWS; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void print_board(char board[][ROWS])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < LINE; i++)
	{
		for (j = 0; j < ROWS; j++)
		{

			printf("%3c", board[i][j]);
			printf(" |");
		}
		printf("\n -------------- \n");
	}
}
void p_game(char board[][ROWS])
{
	int line = 0;
	int row = 0;
	do
	{
		printf("玩家放置棋子：");
		scanf("%d %d", &line, &row);

	} while ((line >LINE) || (row > ROWS) || (board[line-1][row-1] != ' '));
	printf("\n");
	board[line-1][row-1] = 'X';
	print_board(board);
}

void npc_game(char board[][ROWS])
{
	int line = 0;
	int row = 0;
	printf("NPC放置棋子:\n");
	srand((unsigned)time(NULL));
	do
	{
		line = rand() % 3;
		row = rand() % 3;
	} while (board[line][row] != ' ');
	board[line][row] = 'O';
	print_board(board);
}
char check_win(char board[][ROWS])
{
	int i = 0;
	// 判断横行
	for (i = 0; i < LINE ; i++)
	{
		if ((board[i][0] == board[i][1])
			&& (board[i][0] == board[i][2])
			&& (board[i][0] != ' '))
			return board[i][0];
	}
	// 判断 竖列
	for (i = 0; i <ROWS; i++)
	{
		if ((board[0][i] == board[1][i])
			&& (board[1][i] == board[2][i])
			&& (board[0][i] != ' '))
			return board[0][i];
	}
	// 判断斜 
	{
		if ((board[0][0] == board[1][1])
			&& (board[1][1] == board[2][2])
			&& (board[0][0] != ' '))
			return board[0][0];
		if ((board[0][2] == board[1][1])
			&& (board[1][1] == board[2][0])
			&& (board[0][2] != ' '))
			return board[0][2];
	}
	 // 判断 平局
	if (check_full(board) == 1)
		return 'P';
	return 'Q';  // 没有下完

}

int check_full(char board[][ROWS])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < LINE; i++)
	{
		for (j = 0; j < ROWS; j++)
		{
			if (board[i][j] != ' ')
				;
			else
				return 0; // 棋盘未满
		}
	}
	return 1; //  棋盘满
}
