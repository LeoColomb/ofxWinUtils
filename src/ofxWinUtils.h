// ********
// ofxWinUtils
// Usefull Windows Utils implementation for openFrameworks
// https://github.com/LeoColomb/ofxWinUtils
//
// Copyright (c) 2013 Leo Colombaro
// MIT License
// ********

#ifndef OFX_WIN_UTILS
#define OFX_WIN_UTILS

#pragma once
#include "ofMain.h"

#ifndef TARGET_WIN32
void ofxWinError();
#else

#include <winuser.h>
#include <commdlg.h>
#include <Shobjidl.h>
#include "ofBaseTypes.h"

// Dialogs
//------------------------------------------------------------------------------
ofColor ofxWinColorDialog();

// Cursor
//------------------------------------------------------------------------------
// Choose cursor here: http://msdn.microsoft.com/library/windows/desktop/ms648391.aspx
void ofxWinCursor(LPCTSTR name);

// Taskbar
//------------------------------------------------------------------------------
class ofxWinTaskbarProgress {
public:
	ofxWinTaskbarProgress();
	virtual ~ofxWinTaskbarProgress();

	void SetProgressState(HWND hwnd, TBPFLAG flag);
	void SetProgressValue(HWND hwnd, ULONGLONG ullCompleted, ULONGLONG ullTotal);

private:
	bool setup();
	ITaskbarList3* m_pITaskBarList;
	bool m_bFailed;
};


#endif
#endif
