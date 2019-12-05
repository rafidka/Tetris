/*
	filename : TFigure.cpp
	Implementation of the TFigure class. This class is responsible
	for making figures and put it on the map.

	By : Rafid Khalid

	created on : Thursday, November 18, 1999
	last modified on : Tuesday, December 7, 1999
--------------------------------------------------------------------*/

#include "Main.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TFigure::TFigure( TMap * pmap, BYTE * pfigure, BYTE figurewidth,
				 BYTE figureheight )
{
	Initialize();
	if( pmap )
		SetMap( pmap );
	if( pfigure && figurewidth > 0 && figureheight > 0 )
		Create( pfigure, figurewidth, figureheight );
}

TFigure::~TFigure()
{
	Destroy();
}

//*******************************************************************
// function : Initialize
// Initialize the variable of the figure.
// parameters : none
// return value : none
// created on : Thursday, November 18, 1999
// last modified on : Tuesday, December 7, 1999
//*******************************************************************
void TFigure::Initialize()
{
	pMap = NULL;
	pFigure = NULL;
	XPos = YPos = FigureWidth = FigureHeight = 0;
	Keys[0] = VK_LEFT; Keys[1] = VK_RIGHT;
	Keys[2] = VK_UP; Keys[3] = VK_DOWN;
	PrevTime = timeGetTime();
	NextFigure = random(7);
}

//*******************************************************************
// function : Destroy
// Free the memory of the figure.
// parameters : none
// return value : none
// created on : Thursday, November 18, 1999
//*******************************************************************
void TFigure::Destroy()
{
	if( pFigure )
		delete pFigure;
	Initialize();
}

//*******************************************************************
// function : Create
// Creates the figure.
// parameters : pfigure = a pointer to a memory containing the blocks
//                        of the figure.
//              width, height = the dimensions of the figure.
// return value : TRUE if the figure can't put on the map( the map is
//                full ), otherwise FALSE.
// created on : Thursday, November 18, 1999
// last modified on : Saturday, November 20, 1999
//*******************************************************************
BOOL TFigure::Create( BYTE * pfigure, BYTE width, BYTE height )
{
	FigureWidth = width; FigureHeight = height;
	XPos = pMap->GetWidth() / 2 - FigureWidth / 2; YPos = -2;
	if( !pfigure ) return FALSE;
	for( BYTE x = 0; x < width; x++ )
		for( BYTE y = 0; y < height; y++ )
			if( pMap->GetBlock( x + XPos, y + YPos ) != 0 &&
				pfigure[y*width+x] != 0 )
				return FALSE;
	// Frees the memory of figure blocks if it exist
	if( pFigure )
		delete pFigure;
	// Allocates memory for the figure blocks
	pFigure = new BYTE[width*height*4];
	CopyMemory( pFigure, pfigure, width*height*4 );
	// Creates the plane of the figure and set its image
	GPlane::Create( FigureWidth, FigureHeight );
	SetImage( &gsBlocks );
	SetFigure();
	return TRUE;
}

//*******************************************************************
// function : SetFigure
// Sets the blocks of the figure.
// parameters : none
// return value : none
// created on : Thursday, November 18, 1999
// last modified on : Saturday, November 20, 1999
//*******************************************************************
void TFigure::SetFigure()
{
	assert( pMap && pFigure && Images );

	for( BYTE x = 0; x < FigureWidth; x++ )
		for( BYTE y = 0; y < FigureHeight; y++ )
			if( pFigure[y*FigureWidth+x] == 0 )
				SetBlock( x, y, 0, 0, -1 );
			else
				SetBlock( x, y, pFigure[y*FigureWidth+x] - 1, 0 );

	Put( gsBlocks.GetWidth()*XPos, gsBlocks.GetHeight()*YPos );
}

//*******************************************************************
// function : SetMap
// Get a pointer to the owner map.
// parameters : pmap = a pointer to the owner map.
// return value : none
// created on : Thursday, November 18, 1999
// last modified on : Tuesday, November 23, 1999
//*******************************************************************
void TFigure::SetMap( TMap * pmap )
{
	pMap = pmap;
	pMap->SetImage( &gsBlocks );
}

//*******************************************************************
// function : MoveRight
// Move the figure one block to right if we can do that.
// parameters : none
// return value : none
// created on : Thursday, November 18, 1999
//*******************************************************************
void TFigure::MoveRight()
{
	assert( pFigure && pMap && Images );

	// Check if the figure can move right
	for( BYTE x = 0; x < FigureWidth; x++ )
		for( BYTE y = 0; y < FigureHeight; y++ )
			if( pFigure[y*FigureWidth+x] != 0 &&
				pMap->GetBlock( x+XPos+1, y+YPos ) != 0 )
					return;
	// Move the figure right
	XPos++;
	MoveTo( gsBlocks.GetWidth()*XPos, gsBlocks.GetHeight()*YPos,
		75 );
}

//*******************************************************************
// function : MoveLeft
// Move the figure one block to left if we can do that.
// parameters : none
// return value : none
// created on : Thursday, November 18, 1999
//*******************************************************************
void TFigure::MoveLeft()
{
	assert( pFigure && pMap && Images );

	// Check if the figure can move right
	for( BYTE x = 0; x < FigureWidth; x++ )
		for( BYTE y = 0; y < FigureHeight; y++ )
			if( pFigure[y*FigureWidth+x] != 0 &&
				pMap->GetBlock( x+XPos-1, y+YPos ) != 0 )
					return;
	// Move the figure left
	XPos--;
	MoveTo( gsBlocks.GetWidth()*XPos, gsBlocks.GetHeight()*YPos,
		75 );
}

//*******************************************************************
// function : MoveDown
// Move the figure one block to down if we can do that.
// parameters : none
// return value : If the block cannot move down the return value is 
//                FALSE, otherwise TRUE.
// created on : Thursday, November 18, 1999
// last modified on : Tuesday, December 7, 1999
//*******************************************************************
BOOL TFigure::MoveDown()
{
	assert( pFigure && pMap && Images );

	// Check if the figure can move down
	for( BYTE x = 0; x < FigureWidth; x++ )
		for( BYTE y = 0; y < FigureHeight; y++ )
			if( pFigure[y*FigureWidth+x] != 0 &&
				pMap->GetBlock( x+XPos, y+YPos+1 ) != 0 )
			{
				CopyFigureToMap();
				BYTE figure = NextFigure;
				NextFigure = random(7);
				if( !Create( Figures + figure * 16 * 4, 4, 4 ) )
				{
					int rval = MessageBox( gwMainWindow.GetHandle(),
						"You lose.\nDo you want to play again?",
						"Tetris", MB_YESNO | MB_ICONQUESTION );
					if( rval == IDYES )
					{
						pMap->EmptyMap();
						Create( Figures + figure * 16 * 4, 4, 4 );
					}
					else
						::SendMessage( gwMainWindow.GetHandle(),
						WM_CLOSE, 0, 0 );
				}
				pMap->CheckLines();
				return FALSE;
			}
	// Move the figure to down
	YPos++;
	MoveTo( gsBlocks.GetWidth()*XPos, gsBlocks.GetHeight()*YPos,
		75 );
	PrevTime = timeGetTime();
	return TRUE;
}

//*******************************************************************
// function : Rotate
// Rotates the figure.
// parameters : bclockwise = If TRUE rotates the figure to clockwise.
// return value : none
// created on : Monday, November 22, 1999
//*******************************************************************
void TFigure::Rotate( BOOL bclockwise )
{
	assert( pFigure && pMap && Images );

	BYTE * pfigure = new BYTE[FigureWidth * FigureHeight];
	CopyMemory( pfigure, pFigure + FigureWidth * FigureHeight * 3,
		FigureWidth * FigureHeight );
	// Check if the figure can rotate
	for( BYTE x = 0; x < FigureWidth; x++ )
		for( BYTE y = 0; y < FigureHeight; y++ )
			if( pfigure[y*FigureWidth+x] != 0 &&
				pMap->GetBlock( x+XPos, y+YPos ) != 0 )
			{
				delete pfigure;
				return;
			}
	CopyMemory( pFigure + FigureWidth * FigureHeight,
		pFigure, FigureWidth * FigureHeight * 3 );
	CopyMemory( pFigure, pfigure, FigureWidth * FigureHeight );
	delete pfigure;
	SetFigure();
}

//*******************************************************************
// function : SetKeys
// Sets the keys to use to move and rotate the figure.
// parameters : left, right, up, down = the virtual code of the keys.
// return value : none
// created on : Thursday, November 18, 1999
//*******************************************************************
void TFigure::SetKeys( BYTE left, BYTE right, BYTE up, BYTE down )
{
	Keys[0] = left; Keys[1] = right;
	Keys[2] = up; Keys[3] = down;
}

//*******************************************************************
// function : LoadBlocksBitmap
// Load a bitmap containing blocks.
// parameters : width = width of each block.
//              height = height of each block.
//              nxblocks = number of columns of blocks.
//              nyblocks = number of rows of blocks.
//              bpp = the number of bits per pixel.
// return value : none
// created on : Saturday, November 20, 1999
//*******************************************************************
void TFigure::LoadBlocksBitmap( const char * filename, unsigned int width,
							   unsigned int height, unsigned int nxblocks,
							   unsigned int nyblocks, unsigned char bpp )
{
	gsBlocks.Create( width, height, nxblocks, nyblocks, bpp );
	gsBlocks.Load( (char*)filename );
}

//*******************************************************************
// function : CopyFigureToMap
// Copy the indexes of the figure blocks on the map blocks.
// parameters : none
// return value : none
// created on : Saturday, November 20, 1999
//*******************************************************************
void TFigure::CopyFigureToMap()
{
	assert( pMap && pFigure && Images );

	for( BYTE x = 0; x < FigureWidth; x++ )
		for( BYTE y = 0; y < FigureHeight; y++ )
			if( pFigure[y*FigureWidth+x] != 0 )
				pMap->SetBlock( x+XPos, y+YPos, pFigure[y*FigureWidth+x] );
}

//*******************************************************************
// function : Run
// Processes the movement of the figure. This function is derived from
// class GPlane.
// parameters : none
// note : the parameter parg will not be used.
// return value : none
// created on : Thursday, November 18, 1999
// last modified on : Wednesday, November 24, 1999
//*******************************************************************
void TFigure::Run( void * parg )
{
	if( !Moving )
	{
		if( GetKeyState(Keys[0])&0x8000 )
			MoveLeft();
		if( GetKeyState(Keys[1])&0x8000 )
			MoveRight();
		if( GetKeyState(Keys[2])&0x8000 &&
			timeGetTime() - RotatePrevTime > 100 )
		{
			RotatePrevTime = timeGetTime();
			Rotate();
		}
		if( GetKeyState(Keys[3])&0x8000 )
			MoveDown();
	}
	// Checks if it now time to move the figure down
	if( timeGetTime() - PrevTime > 1000 )
		MoveDown();

	GPlane::Run( NULL );
}
