#include "stdafx.h"
#include "GameMgr.h"

char board[4][4];
bool wMove = true;
bool gameOver = false;
int wSum = 0;
int bSum = 0;
char key;


void GameReset() 
{
	gameOver = false;
	wMove = true;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
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

	//Create title
	TextOut(hdc, 222, 50, _T("Go!"), 3);

	//Display amount of pieces captured for each player **Figure out how to TextOut a variable
	TextOut(hdc, 190, 450, _T("Player 1 score: " + wSum), 25);
	TextOut(hdc, 190, 480, _T("Player 2 score: " + bSum), 25);

	

	//Walk through the board and draw an X or O wherever that value is
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (board[i][j] == X)
				GameDrawWhite(hdc, i, j);
			else if (board[i][j] == O)
				GameDrawBlack(hdc, i, j);
			
		}
	}

	

	
}

void GameSetMove(int i, int j)
{

	//Allow user to pass
	if (key == VK_SPACE){
		wMove = !wMove;
		key = VK_DOWN;
	}

	//End the game
	//if (key == VK_RETURN){
		//GameOver();
//	}

	//Check if the move is inside the board, assign the value of the player to that array element, then check for liberties
	if (i >= 0 && i <= 3 && j >= 0 && j <= 3 && board[i][j] == 0){
		if (!gameOver){
			if (wMove){
				board[i][j] = X;
				for (int i = 0; i < 3; i++){
					for (int j = 0; j < 3; j++){
						CheckLiberties(i, j);
					}
				}
			}
			else{
				board[i][j] = O;
				for (int i = 0; i < 3; i++){
					for (int j = 0; j < 3; j++){
						CheckLiberties(i, j);
					}
				}
			}
			//Next player's move
			wMove = !wMove;
		} 
	}
}

void GameCheckWinner(HWND hwnd) {}

void GameDrawWhite(HDC hdc, int i, int j) 
{

	//Draw white piece
	HPEN pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
	HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));

	HGDIOBJ penOld = SelectObject(hdc, pen);
	HGDIOBJ brushOld = SelectObject(hdc, brush);

	Ellipse(hdc, 60 + (100 * i), 60 + (100 * j), 140 + (100 * i), 140 + (100 * j));

	SelectObject(hdc, penOld);
	SelectObject(hdc, brushOld);
	DeleteObject(pen);
	DeleteObject(brush);
}


void GameDrawBlack(HDC hdc, int i, int j)
{
	//Draw black piece
	HPEN pen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
	HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));

	HGDIOBJ penOld = SelectObject(hdc, pen);
	HGDIOBJ brushOld = SelectObject(hdc, brush);

	
	Ellipse(hdc, 60 + (100 * i), 60 + (100 * j), 140 + (100 * i), 140 + (100 * j));

	SelectObject(hdc, penOld);
	SelectObject(hdc, brushOld);
	DeleteObject(pen);
	DeleteObject(brush);
}

void CheckLiberties(int i, int j)
{
	if (board[i][j] == O){
		if (board[i - 1][j] != EMPTY && board[i + 1][j] != EMPTY && board[i][j - 1] != EMPTY && board[i][j + 1] != EMPTY){
			if (board[i - 1][j] == X && board[i + 1][j] == X && board[i][j - 1] == X && board[i][j + 1] == X){


				board[i][j] = EMPTY;
				wSum += 1;
			}
		}
	}

		else if (board[i][j] == X){
			if (board[i - 1][j] != EMPTY && board[i + 1][j] != EMPTY && board[i][j - 1] != EMPTY && board[i][j + 1] != EMPTY){
				if (board[i - 1][j] == O && board[i + 1][j] == O && board[i][j - 1] == O && board[i][j + 1] == O){

				
					board[i][j] = EMPTY;
					bSum += 1;
				}
			}
		}
}
void GameSetKey(WPARAM wParam)
{
	key = (char)wParam;
}

//void GameOver()
//{
	//if (wSum > bSum)
		//TextOut(hdc, 250, 50, _T("Player 1 wins!"), 14);
	//else if (bSum > wSum)
		//TextOut(hdc, 250, 50, _T("Player 2 wins!"), 14);


//}
