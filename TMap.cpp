/*
	filename : TMap.cpp
	Implementation of the TMap class. This class is responsible
	for making map of blocks to use in the game.

	note : I put at the left and the right of the map the byte
	 0xff to recognize the end of the left and the right of the
	 map and I put at the bottom of the map the same byte too
	 to recognize the bottom of the map, So we should add 2
	 to the width, 1 to the height and 1 to the x to get the
	 true index of the block.

	By : Rafid Khalid

	created on : Thursday, November 18, 1999
	last modified on : Thursday, November 25, 1999
--------------------------------------------------------------------*/

#include "Main.h"

//////////////////////////////////////////////////////////////////////
// Constructions / Destruction
//////////////////////////////////////////////////////////////////////

TMap::TMap()
{
	Initialize();
}

TMap::TMap( BYTE width, BYTE height )
{
	Initialize();
	Create( width, height );
}

TMap::~TMap()
{
	Destroy();
}

//*******************************************************************
// function : Initialize
// Initializes the variable of this class.
// parameters : none
// return value : none
// created on : Thursday, November 18, 1999
//*******************************************************************
void TMap::Initialize()
{
	pMap = NULL;
	MapWidth = MapHeight = 0;
}

//*******************************************************************
// function : Destroy
// Frees the memory of the map.
// parameters : none
// return value : none
// created on : Thursday, November 18, 1999
//*******************************************************************
void TMap::Destroy()
{
	if( pMap )
		delete pMap;
	Initialize();
}

//*******************************************************************
// function : Create
// Allocate memory for the map.
// parameters : width, height = the dimensions of the map.
// return value : none
// created on : Thursday, November 18, 1999
// last modified on : Monday, November 22, 1999
//*******************************************************************
void TMap::Create( BYTE width, BYTE height )
{
	// Destroy the map if it exist
	Destroy();

	BYTE rowlength = width+2;
	MapWidth = width; MapHeight = height;
	pMap = new BYTE[rowlength*(MapHeight+1)];
	ZeroMemory( pMap, rowlength*(MapHeight+1) );
	GPlane::Create( MapWidth, MapHeight );
	// Draws the frame of the map
	for( BYTE i = 0; i < MapHeight; i++ )
	{
		pMap[i*rowlength] = 0xff;
		pMap[i*rowlength+(rowlength-1)] = 0xff;
	}
	for( i = 0; i < rowlength; i++ )
		pMap[MapHeight*rowlength+i] = 0xff;

	for( int x = 0; x < MapWidth; x++ )
		for( int y = 0; y < MapHeight; y++ )
			SetBlock( x, y, GetBlock( x, y ) );
}

//*******************************************************************
// function : CheckLines
// Checks if any line completes and remove it.
// parameters : none
// return value : none
// created on : Tuesday, November 23, 1999
//*******************************************************************
void TMap::CheckLines()
{
	assert( pMap );

	static char ScoreText[100];
	int nlinesremoved = 0;
	for( BYTE y = 0; y < MapHeight; y++ )
	{
		BOOL bremoveline = TRUE;
		for( BYTE x = 0; x < MapWidth; x++ )
			if( GetBlock( x, y ) == 0 )
				bremoveline = FALSE;
		if( bremoveline )
		{
			nlinesremoved++;
			for( BYTE j = y - 1; j > 0; j-- )
				for( BYTE i = 0; i < MapWidth; i++ )
					SetBlock( i, j+1, GetBlock( i, j ) );
			for( BYTE i = 0; i < MapWidth; i++ )
				SetBlock( i, 0, 0 );
		}
	}
	dwScore += 10 * nlinesremoved;
	if( nlinesremoved == 4 )
		dwScore += 10;
	sprintf( ScoreText, "%d", dwScore );
	gtScoreText.SetText( ScoreText, TRUE, ALIGN_CENTER );
	gtScoreText.Put( 549, 98 );
}

//*******************************************************************
// function : EmptyMap
// Empties the map from the blocks.
// parameters : none
// return value : none
// created on : Wednesday, November 24, 1999
//*******************************************************************
void TMap::EmptyMap()
{
	assert( pMap );

	for( BYTE x = 0; x < MapWidth; x++ )
		for( BYTE y = 0; y < MapHeight; y++ )
			SetBlock( x, y, 0 );
}

//*******************************************************************
// function : GetBlockIndex
// Get the index of a block in the map array.
// parameters : x, y = the coordinates of the block in the map.
// return value : the index of a block in the map array.
// created on : Thursday, November 18, 1999
//*******************************************************************
WORD TMap::GetBlockIndex( int x, int y )
{
	assert( pMap );

	int rowlength = (MapWidth+2);
	return (WORD)(y*rowlength+(x+1));
}

//*******************************************************************
// function : SetBlock
// Set the index of a block in the map.
// parameters : x, y = the coordinates of the block in the map.
// return value : none
// created on : Thursday, November 18, 1999
//*******************************************************************
BYTE TMap::SetBlock( BYTE x, BYTE y, BYTE block )
{
	assert( pMap );

	BYTE prevblock = GetBlock( x, y );
	pMap[GetBlockIndex( x, y )] = block;
	if( pMap[GetBlockIndex( x, y )] == 0 )
		GPlane::SetBlock( x, y, 0, 0, -1 );	
	else
		GPlane::SetBlock( x, y, block-1, 0 );
	return prevblock;
}

//*******************************************************************
// function : GetBlock
// Get the index of a block in the map.
// parameters : x, y = the coordinates of the block in the map.
// return value : the index of the block in the map.
// created on : Thursday, November 18, 1999
// last modified on : Wednesday, November 24, 1999
//*******************************************************************
BYTE TMap::GetBlock( int x, int y )
{
	assert( pMap );

	x = max( -1, x );
	y = max( 0, y );

	return pMap[min( (MapWidth+2)*(MapHeight+1), GetBlockIndex( x, y ) )];
}
