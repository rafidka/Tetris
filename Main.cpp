/*
	filename : Main.cpp
	Defines the entry point for the application.

	By : Rafid Khalid

	created on : Thursday, November 18, 1999
	last modified on : Tuesday, December 7, 1999
--------------------------------------------------------------------*/

// Main header file
#include "Main.h"
#include "Resource.h"
#include <winuser.h>

BYTE Figures[] = { 0, 0, 0, 0, // figure 1
				 0, 1, 0, 0,
				 0, 1, 1, 1,
				 0, 0, 0, 0,

				 0, 0, 0, 0,
				 0, 1, 1, 0,
				 0, 1, 0, 0,
				 0, 1, 0, 0,

				 0, 0, 0, 0,
				 1, 1, 1, 0,
				 0, 0, 1, 0,
				 0, 0, 0, 0,

				 0, 0, 1, 0,
				 0, 0, 1, 0,
				 0, 1, 1, 0,
				 0, 0, 0, 0,

				 0, 0, 0, 0, // figure 2
				 0, 0, 2, 0,
				 2, 2, 2, 0,
				 0, 0, 0, 0,

				 0, 2, 0, 0,
				 0, 2, 0, 0,
				 0, 2, 2, 0,
				 0, 0, 0, 0,

				 0, 0, 0, 0,
				 0, 2, 2, 2,
				 0, 2, 0, 0,
				 0, 0, 0, 0,

				 0, 0, 0, 0,
				 0, 2, 2, 0,
				 0, 0, 2, 0,
				 0, 0, 2, 0,

				 0, 0, 0, 0, // figure 3
				 0, 3, 3, 0,
				 0, 3, 3, 0,
				 0, 0, 0, 0,

				 0, 0, 0, 0,
				 0, 3, 3, 0,
				 0, 3, 3, 0,
				 0, 0, 0, 0,

				 0, 0, 0, 0,
				 0, 3, 3, 0,
				 0, 3, 3, 0,
				 0, 0, 0, 0,

				 0, 0, 0, 0,
				 0, 3, 3, 0,
				 0, 3, 3, 0,
				 0, 0, 0, 0,

				 0, 0, 0, 0, // figure 4
				 4, 4, 4, 4,
				 0, 0, 0, 0,
				 0, 0, 0, 0,

				 0, 4, 0, 0,
				 0, 4, 0, 0,
				 0, 4, 0, 0,
				 0, 4, 0, 0,

				 0, 0, 0, 0,
				 4, 4, 4, 4,
				 0, 0, 0, 0,
				 0, 0, 0, 0,

				 0, 4, 0, 0,
				 0, 4, 0, 0,
				 0, 4, 0, 0,
				 0, 4, 0, 0,

				 0, 0, 0, 0, // figure 5
				 5, 5, 0, 0,
				 0, 5, 5, 0,
				 0, 0, 0, 0,

				 0, 0, 5, 0,
				 0, 5, 5, 0,
				 0, 5, 0, 0,
				 0, 0, 0, 0,

				 0, 0, 0, 0,
				 5, 5, 0, 0,
				 0, 5, 5, 0,
				 0, 0, 0, 0,

				 0, 0, 5, 0,
				 0, 5, 5, 0,
				 0, 5, 0, 0,
				 0, 0, 0, 0,

				 0, 0, 0, 0, // figure 6
				 0, 6, 6, 0,
				 6, 6, 0, 0,
				 0, 0, 0, 0,

				 0, 6, 0, 0,
				 0, 6, 6, 0,
				 0, 0, 6, 0,
				 0, 0, 0, 0,

				 0, 6, 0, 0,
				 0, 6, 6, 0,
				 0, 0, 6, 0,
				 0, 0, 0, 0,

				 0, 6, 0, 0,
				 0, 6, 6, 0,
				 0, 0, 6, 0,
				 0, 0, 0, 0,

				 0, 0, 0, 0, // figure 7
				 0, 0, 7, 0,
				 0, 7, 7, 7,
				 0, 0, 0, 0,

				 0, 0, 0, 0,
				 0, 0, 7, 0,
				 0, 0, 7, 7,
				 0, 0, 7, 0,

				 0, 0, 0, 0,
				 0, 0, 0, 0,
				 0, 7, 7, 7,
				 0, 0, 7, 0,

				 0, 0, 0, 0,
				 0, 0, 7, 0,
				 0, 7, 7, 0,
				 0, 0, 7, 0 };

TWindow gwMainWindow;
GSurface gsBack;
GSprite gspBack;
GPlane gpNextFigure;
//GFontEx gfFont;
GText gtScoreText;
DWORD dwScore = 0;
HMENU hMenu = NULL;

class b
{
public:
	b();
	virtual ~b();
protected:
	int a( b p );
};

b::b()
{
}

b::~b()
{
	return;
}

int b::a( b p )
{
	return 0;
}

int pascal WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
				   LPSTR lpCmdLine, int nCmdShow )
{

	dwScore = 0;
	int bpp = 16;
	srand( (unsigned int)timeGetTime() );

	GApplication::hWindowIcon = LoadIcon( hInstance, (PSTR)IDI_ICON );
	GApplication::hWindowCursor = LoadCursor( NULL, IDC_ARROW );
	// Initializes application
	GApplication::Initialize( hInstance );
	// Creates and shows window
	if( !gwMainWindow.Create( 640, 480, bpp, "Tetris",
		WS_OVERLAPPEDWINDOW ) )
	{
		MessageBox( NULL, "Failed to create window", "error",
			MB_OK | MB_ICONSTOP );
		GApplication::EndApplication();
		return 0;
	}
	b * psprite = new b[2];
	delete[] psprite;
	hMenu = LoadMenu( hInstance, MAKEINTRESOURCE(IDR_MAINMENU) );
	SetMenu( gwMainWindow.GetHandle(), hMenu );
//	gwMainWindow.ShowFullScreen();
	gwMainWindow.ShowWindow();
	// Creates and sets the palette
//	GPalette gpPalette( "back.bmp" );
//	gwMainWindow.SetPalette( &gpPalette );
//	GApplication::SetDefaultPalette( &gpPalette );

	// Loads the font
//	gfFont.Load( "font.bmp", bpp );
	// Initializes score text
//	gtScoreText.SetFont( &gfFont );
	gtScoreText.SetText( "0", TRUE, ALIGN_CENTER );
	gtScoreText.Put( 549, 98 );
	// Creates surfaces
	gsBack.Create( 640, 480, 1, 1, bpp );
	gsBack.Load( "back.bmp" );
	// Initializes sprites
	gspBack.SetImage( &gsBack );
	// Attach sprites
	gwMainWindow.MainView << gspBack;
	gwMainWindow.MainView << gtScoreText;
	
	TPlayer player( 10, 18, "blocks.bmp", 20, 20, 7, 1, bpp );
	gwMainWindow.MainView << player;

	do{
	} while( GApplication::Run( NULL ) );

	DestroyMenu( hMenu );
	GApplication::EndApplication();
	return 0;
}
