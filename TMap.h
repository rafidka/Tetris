/*
	filename : TMap.h
	Interface for the TMap class. This class is responsible
	for making map of blocks to use in the game.

	note : I put at the left and the right of the map the byte
	 0xff to recognize the end of the left and the right of the
	 map and I put at the bottom of the map the same byte too
	 to recognize the bottom of the map, So we should add 2
	 to the width, 1 to the height and 1 to the x to get the
	 true index of the block.

	By : Rafid Khalid

	created on : Thursday, November 18, 1999
	last modified on : Wednesday, November 24, 1999
--------------------------------------------------------------------*/

#if !defined(AFX_TMAP_H__CDCB6EE5_9DD6_11D3_B055_DA618E836B1D__INCLUDED_)
#define AFX_TMAP_H__CDCB6EE5_9DD6_11D3_B055_DA618E836B1D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class TMap : public GPlane
{
// Constructions/Destruction
public:
	TMap();
	TMap( BYTE width, BYTE height );
	virtual ~TMap();

// Member functions
public:
	void Initialize();
	void Destroy();
	void Create( BYTE width, BYTE height );
	WORD GetBlockIndex( int x, int y );
	BYTE GetBlock( int x, int y );
	BYTE SetBlock( BYTE x, BYTE y, BYTE block );
	void CheckLines();
	void EmptyMap();
	BYTE * GetMap()
	{
		return pMap;
	}
	BYTE GetWidth()
	{
		return MapWidth;
	}
	BYTE GetHeight()
	{
		return MapHeight;
	}

// Member variables
protected:
	BYTE MapWidth, MapHeight;
	BYTE * pMap;
};

#endif // !defined(AFX_TMAP_H__CDCB6EE5_9DD6_11D3_B055_DA618E836B1D__INCLUDED_)
