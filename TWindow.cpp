/*
	filename : TWindow.cpp
	Implementation of the TWindow class.

	By : Rafid Khalid

	created on : Wednesday, November 24, 1999
	last modified on : Wednesday, November 24, 1999
--------------------------------------------------------------------*/

#include "Main.h"
#include "Resource.h"

//*******************************************************************
// function : WndProc
// The widnow procedure of the window.
// parameters : message = message of the standard window proc.
//              wparam = wparam of the standard window proc.
//              lparam = lparam of the standard window proc.
// return value : result of window proc.
// created on : Wednesday, November 24, 1999
//*******************************************************************
LRESULT TWindow::WndProc( UINT message, WPARAM wparam, LPARAM lparam )
{
	switch( message )
	{
	case WM_COMMAND:
		switch( LOWORD(wparam) )
		{
		case ID_GAME_EXIT:
			PostQuitMessage(0);
			break;

		case ID_HELP_ABOUT:
			DialogBox( GApplication::hInstance, (PSTR)IDD_ABOUTDIALOG,
				hWnd, (DLGPROC)AboutDlgProc );
			break;
		}
		return 0;

	case WM_KEYDOWN:
		if( !AutoChangeMode ) break;
		if( (TCHAR)wparam != VK_F4 ) break;
			if( WindowType == FULLSCREEN )
			{
				ShowWindow();
				SetMenu( hWnd, hMenu );
			}
			else
			{
				ShowFullScreen();
				SetMenu( hWnd, NULL );
			}
		return DefWindowProc( hWnd, message, wparam, lparam );
	}

	return GWindow::WndProc( message, wparam, lparam );
}

//*******************************************************************
// function : AboutDlgProc
// Message handler for about dialog.
// parameters : standard dialog procedure parameters.
// return value : If the message is WM_INITDIALOG the return value is
//                TRUE, otherwise FALSE.
// created on : Wednesday, November 24, 1999
//*******************************************************************
LRESULT CALLBACK AboutDlgProc( HWND hwnd, UINT message, WPARAM wparam,
							  LPARAM lparam )
{
	switch( message )
	{
	case WM_INITDIALOG:
		return TRUE;

	case WM_COMMAND:
		if (LOWORD(wparam) == IDOK || LOWORD(wparam) == IDCANCEL) 
		{
			EndDialog( hwnd, LOWORD(wparam) );
			return TRUE;
		}
		break;
	}

	return FALSE;
}