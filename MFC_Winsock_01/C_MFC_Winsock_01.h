// MFC_Winsock_01.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// C_MFC_Winsock_01_App:
// See MFC_Winsock_01.cpp for the implementation of this class
//

class C_MFC_Winsock_01_App : public CWinApp
{
public:
	C_MFC_Winsock_01_App();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern C_MFC_Winsock_01_App theApp;