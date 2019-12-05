/*
	filename : TScore.h
	Interface for the TScore class.

	By : Rafid Khalid

	created on : Thursday, November 25, 1999
	last modified on : Thursday, November 25, 1999
--------------------------------------------------------------------*/

// TScore.h: interface for the TScore class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TSCORE_H__F05ABAC2_A352_11D3_B055_B1448253587A__INCLUDED_)
#define AFX_TSCORE_H__F05ABAC2_A352_11D3_B055_B1448253587A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\..\GAME CLASS LIB\INCLUDE\Gsprite.hpp"

class TScore : public GSprite  
{
public:
	TScore();
	virtual ~TScore();

};

#endif // !defined(AFX_TSCORE_H__F05ABAC2_A352_11D3_B055_B1448253587A__INCLUDED_)
