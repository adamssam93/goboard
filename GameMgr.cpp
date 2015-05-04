#include "stdafx.h"
#include "GameMgr.h"

char board[4][4];
bool xMove = true;
bool gameOver = false;

void GameReset() 
{
	gameOver = false;
	xMove = true;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			board[i][j] = EMPTY;
		}
	}
}

void GameDrawBoard(HWND hwnd, HDC hdc) 
{
	//Creates outer box
	MoveToEx(hdc, 100, 100, NULL); LineTo(hdc, 100, 400);
	MoveToEx(hdc, 100, 100, NULL); LineTo(hdc, 400, 100);
	MoveToEx(hdc, 400, 100, NULL); LineTo(hdc, 400, 400);
	MoveToEx(hdc, 100, 400, NULL); LineTo(hdc, 400, 400);

	//Creates intersections
	MoveToEx(hdc, 200, 100, NULL); LineTo(hdc, 200, 400);
	MoveToEx(hdc, 300, 100, NULL); LineTo(hdc, 300, 400);
	MoveToEx(hdc, 100, 200, NULL); LineTo(hdc, 400, 200);
	MoveToEx(hdc, 100, 300, NULL); LineTo(hdc, 400, 300);

	//Walk through the board and draw an X or O wherever that value is
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (board[i][j] == X)
				GameDrawX(hdc, i, j);
			else if (board[i][j] == O)
				GameDrawO(hdc, i, j);
		}
	}
}

void GameSetMove(int i, int j)
{
	//Check if the move is inside the board
	if (i >= 0 && i <= 3 && j >= 0 && j <= 3){
		if (!gameOver){
			if (xMove)
				board[i][j] = X;
			else
				board[i][j] = O;
			//Next player's move
			xMove = !xMove;
		}
	}
}

void GameCheckWinner(HWND hwnd) {}

void GameDrawX(HDC hdc, int i, int j) 
{
	MoveToEx(hdc, 70 + (100 * i), 70 + (100 * j), NULL);
	LineTo(hdc, 130 + (100 * i), 130 + (100 * j));

	MoveToEx(hdc, 130 + (100 * i), 70 + (100 * j), NULL);
	LineTo(hdc, 70 + (100 * i), 130 + (100 * j));
}
void GameDrawO(HDC hdc, int i, int j)
{
	POINT pt[5];
	pt[0].x = 100 + (100 * i); pt[0].y = 60 + (100 * j);
	pt[1].x = 140 + (100 * i); pt[1].y = 100 + (100 * j);
	pt[2].x = 100 + (100 * i); pt[2].y = 140 + (100 * j);
	pt[3].x = 60 + (100 * i); pt[3].y = 100 + (100 * j);
	pt[4].x = 100 + (100 * i); pt[4].y = 60 + (100 * j);

	Polyline(hdc, pt, 5);
}
