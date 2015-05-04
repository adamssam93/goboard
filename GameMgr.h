#include "stdafx.h"
#include <commdlg.h>

const char EMPTY = '\0';
const char X = 'X';
const char O = 'O';

const int XBALLSTART = 177;
const int YBALLSTART = 277;
const int XBALLINC = 3;
const int YBALLINC = 3;
const int BALLWIDTH = 20;
const int BALLHEIGHT = 20;

extern char board[4][4];
extern bool xMove;
extern bool gameOver;
extern int xRect, yRect; //Rectangle to draw the ball in
extern int xInc, yInc; //How much to move the ball with each tick
extern HFONT fntchose; //Choose the font
extern char key;

void GameReset();
void GameDrawBoard(HWND hwdn, HDC hdc); //Draws the game board with Xs and Os
void GameSetMove(int i, int j); //Set the next move
void GameCheckWinner(HWND hwnd); 
void GameDrawX (HDC hdc, int i, int j);
void GameDrawO(HDC hdc, int i, int j);
void GameDrawBall(HWND hwnd, HDC hdc);
void GameCreateFont();
void GameSetKey(WPARAM wParam);
