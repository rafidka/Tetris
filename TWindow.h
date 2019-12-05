/*
	filename : TWindow.h
	Interface for the TWindow class.

	By : Rafid Khalid

	created on : Wednesday, November 24, 1999
	last modified on : Wednesday, November 24, 1999
--------------------------------------------------------------------*/

#if !defined(AFX_TWINDOW_H__135712EB_A285_11D3_B055_E25C2EE15B0F__INCLUDED_)
#define AFX_TWINDOW_H__135712EB_A285_11D3_B055_E25C2EE15B0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class TWindow : public GWindow  
{
// Message handling
public:
	virtual LRESULT WndProc( UINT message, WPARAM wparam, LPARAM lparam );
};

LRESULT CALLBACK AboutDlgProc( HWND hwnd, UINT message, WPARAM wparam,
							  LPARAM lparam );

#endif // !defined(AFX_TWINDOW_H__135712EB_A285_11D3_B055_E25C2EE15B0F__INCLUDED_)
