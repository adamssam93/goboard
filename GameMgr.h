#include "stdafx.h"
#include <commdlg.h>

const char EMPTY = '\0';
const char X = 'X';
const char O = 'O';

extern char board[4][4];
extern bool wMove;
extern bool gameOver;
extern int xRect, yRect; //Rectangle to draw the ball in
extern int xInc, yInc; //How much to move the ball with each tick
extern HFONT fntchose; //Choose the font
extern char key;

void GameReset();
void GameDrawBoard(HWND hwdn, HDC hdc); //Draws the game board with Xs and Os
void GameSetMove(int i, int j); //Set the next move
void GameCheckWinner(HWND hwnd); 
void GameDrawWhite (HDC hdc, int i, int j);
void GameDrawBlack(HDC hdc, int i, int j);
void GameSetKey(WPARAM wParam);
void CheckLiberties(int i, int j);
void GameOver(HWND hwnd, HDC hdc);

//What we need:
//Update liberties function so it will work for more than one piece being surrounded at a time, capture a piece if it's on the edge
//Figure out how to TextOut values of variables
//Display winner once the game has ended
//Add a rules section in menu
