/*
	filename : TPlayer.h
	Interface for the TPlayer class.

	By : Rafid Khalid

	created on : Thursday, November 19, 1999
	last modified on : Thursday, November 25, 1999
--------------------------------------------------------------------*/

#if !defined(AFX_TPLAYER_H__C6496BA2_9E02_11D3_B055_F9C0388B651E__INCLUDED_)
#define AFX_TPLAYER_H__C6496BA2_9E02_11D3_B055_F9C0388B651E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class TPlayer : public GView
{
// Construction/Destruction
public:
	TPlayer( BYTE mapwidth, BYTE mapheight,
		const char * blocksfilename, unsigned int width,
		unsigned int height, unsigned int nxblocks,
		unsigned int nyblocks, unsigned char bpp = 0 );
	virtual ~TPlayer();

// member functions
public:
	void Initialize();
	void Destroy();
	void Create( BYTE mapwidth, BYTE mapheight,
		const char * blocksfilename, unsigned int width,
		unsigned int height, unsigned int nxblocks,
		unsigned int nyblocks, unsigned char bpp = 0 );
	void Put( int x = -10000, int y = -10000 );
	void SetKeys( BYTE left = VK_LEFT, BYTE right = VK_RIGHT,
		BYTE up = VK_UP, BYTE down = VK_DOWN );
	void LoadBackground( const char * filename );

// member variables
protected:
	GSurface gsBack;
	GSprite gspBack;
	TMap * pMap;
	TFigure * pFigure;
};

#endif // !defined(AFX_TPLAYER_H__C6496BA2_9E02_11D3_B055_F9C0388B651E__INCLUDED_)
