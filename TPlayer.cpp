/*
	filename : TPlayer.cpp
	Implementation of the TPlayer class.

	By : Rafid Khalid

	created on : Thursday, November 19, 1999
	last modified on : Thursday, November 25, 1999
--------------------------------------------------------------------*/

#include "Main.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TPlayer::TPlayer( BYTE mapwidth, BYTE mapheight,
				 const char * blocksfilename, unsigned int width,
				 unsigned int height, unsigned int nxblocks,
				 unsigned int nyblocks, unsigned char bpp )
{
	Initialize();
	Create( mapwidth, mapheight, blocksfilename, width, height,
		nxblocks, nyblocks, bpp );
}

TPlayer::~TPlayer()
{
	Destroy();
}

//*******************************************************************
// function : Initialize
// Initializes the variable of this class.
// parameters : none
// return value : none
// created on : Friday, November 19, 1999
//*******************************************************************
void TPlayer::Initialize()
{
	pMap = NULL;
	pFigure = NULL;
}

//*******************************************************************
// function : Destroy
// Frees the memory that used by this class.
// parameters : none
// return value : none
// created on : Friday, November 19, 1999
//*******************************************************************
void TPlayer::Destroy()
{
	if( pMap )
		delete pMap;
	if( pFigure )
		delete pFigure;
	Initialize();
}

//*******************************************************************
// function : Create
// Creates the player.
// parameters : mapwidth, mapheight = the dimensions of the map.
// return value : none
// created on : Friday, November 19, 1999
// last modified on : Wednesday, November 24, 1999
//*******************************************************************
void TPlayer::Create( BYTE mapwidth, BYTE mapheight,
					 const char * blocksfilename, unsigned int width,
					 unsigned int height, unsigned int nxblocks,
					 unsigned int nyblocks, unsigned char bpp )
{
	if( !blocksfilename )
		return;
	// Destroys the existence player it it exist
	Destroy();
	// Creates the map
	pMap = new TMap( mapwidth, mapheight );
	pMap->Put( 0, 0 );
	int figure = random(7);
	// Creates the figure
	pFigure = new TFigure;
	pFigure->SetMap( pMap );
	pFigure->LoadBlocksBitmap( blocksfilename, width, height,
		nxblocks, nyblocks, bpp );
	pFigure->Create( Figures + figure * 16 * 4, 4, 4 );
	AttachObject( *pMap );
	AttachObject( *pFigure );
	Put();
}

//*******************************************************************
// function : Put
// Put the map of the player on the screen.
// parameters : x, y = the coordinates of the map.
// return value : none
// created on : Friday, November 19, 1999
//*******************************************************************
void TPlayer::Put( int x, int y )
{
	assert( pFigure && pMap );

	int mapwidthinpixel = pMap->GetWidth() *
		pFigure->Images[0]->GetWidth();
	int mapheightinpixel = pMap->GetHeight() *
		pFigure->Images[0]->GetHeight();
	if( x == -10000 ) x = 640/2 - mapwidthinpixel/2;
	if( y == -10000 ) y = 480/2 - mapheightinpixel/2;
	SetViewRegion( x, y, mapwidthinpixel, mapheightinpixel );
}

//*******************************************************************
// function : SetKeys
// Set the keys that will use to move the figure.
// parameters : left, right, up, down = the virtual code of the keys.
// return value : none
// created on : Monday, November 22, 1999
//*******************************************************************
void TPlayer::SetKeys( BYTE left, BYTE right, BYTE up, BYTE down )
{
	assert( pFigure );

	pFigure->SetKeys( left, right, up, down );
}

//*******************************************************************
// function : LoadBackground
// Load a bitmap from a file to set as a background.
// parameters : filename = the name of the file that contain the bitmap.
// return value : none
// created on : Thursday, November 25, 1999
//*******************************************************************
void TPlayer::LoadBackground( const char * filename )
{
	gsBack.Create( ViewRgn.right - ViewRgn.left + 1, ViewRgn.bottom -
		ViewRgn.top + 1, 1, 1,
		gwMainWindow.GetBufferSurface()->GetBitsPerPixel() );
	gsBack.Load( (char*)filename );
	gspBack.SetImage( &gsBack );
	gspBack.SetUsingColorKey( FALSE );
	AttachObject( gspBack );
	AttachObject( *pMap );
	AttachObject( *pFigure );
}