/*
	filename : Main.h
	The main header file for the game. This file includes all
	application header files and defines all the definitions
	that the application use it.

	By : Rafid Khalid

	created on : Thursday, November 18, 1999
	last modified on : Tuesday, December 7, 1999
--------------------------------------------------------------------*/

// Game Class Lib header files
#include "C:\RealGo\Include\RealGo.h"

#include <stdio.h>

// Tetris classes
class TPlayer;
class TMap;
class TFigure;
class TWindow;

// Tetris header files
#include "TPlayer.h"
#include "TMap.h"
#include "TFigure.h"
#include "TWindow.h"

#define random(x) (rand()*x)/RAND_MAX

// 
extern BYTE Figures[];
extern TWindow gwMainWindow;
extern GSurface gsBack;
extern GSprite gspBack;
extern GPlane gpNextFigure;
//extern GFontEx gfFont;
extern GText gtScoreText;
extern DWORD dwScore;
extern HMENU hMenu;