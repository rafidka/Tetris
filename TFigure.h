/*
	filename : TFigure.h
	Interface for the TFigure class. This class is responsible
	for making figures and put it on the map.

	By : Rafid Khalid

	created on : Thursday, November 18, 1999
	last modified on : Tuesday, December 7, 1999
--------------------------------------------------------------------*/

#if !defined(AFX_TFIGURE_H__CDCB6EE6_9DD6_11D3_B055_DA618E836B1D__INCLUDED_)
#define AFX_TFIGURE_H__CDCB6EE6_9DD6_11D3_B055_DA618E836B1D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class TFigure : public GPlane
{
// Constructions/Destruction
public:
	TFigure( TMap * pmap = NULL, BYTE * pfigure = NULL,
		BYTE figurewidth = 0, BYTE figureheight = 0 );
	virtual ~TFigure();

// Member functions
public:
	void Initialize();
	void Destroy();
	BOOL Create( BYTE * pfigure, BYTE width, BYTE height );
	void SetFigure();
	void SetMap( TMap * pmap );
	void MoveRight();
	void MoveLeft();
	BOOL MoveDown();
	void Rotate( BOOL bclockwise = TRUE );
	void SetKeys( BYTE left = VK_LEFT, BYTE right = VK_RIGHT,
		BYTE up = VK_UP, BYTE down = VK_DOWN );
	void LoadBlocksBitmap( const char * filename, unsigned int width,
		unsigned int height, unsigned int nxblocks = 1,
		unsigned int nyblocks = 1, unsigned char bpp = 0 );
	void CopyFigureToMap();
	virtual void Run( void * parg );

// Member variables
protected:
	GSurface gsBlocks;				// A surface containing the bitmaps
									// of the figures
	TMap * pMap;					// The owner map
	BYTE * pFigure;					// A pointer to a memory containing
									// the indexes of the blocks of
									// the figure
	int XPos, YPos,					// The position of the figure in
									// block unit
		FigureWidth, FigureHeight;	// The width and the height of the
									// the figure and block unit
	BYTE Keys[4];					// The keys that use to move
									// the figure
	DWORD PrevTime;					// This DWORD is used to make
									// a timer that run each 1 second
									// timeGetTime() - PrevTime > 1000
									// This timer will move the figure
									// down when it run
	DWORD RotatePrevTime;			// This DWORD is used to make
									// a timer that run each 250 ms
									// timeGetTime() - PrevTime > 250
									// This timer is used to check
									// if the player press rotate key
	int NextFigure;
};

#endif // !defined(AFX_TFIGURE_H__CDCB6EE6_9DD6_11D3_B055_DA618E836B1D__INCLUDED_)
