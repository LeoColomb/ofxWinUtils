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
#include "ofBaseTypes.h"

// Dialogs
//------------------------------------------------------------------------------
ofColor ofxWinColorDialog();

// Cursor
//------------------------------------------------------------------------------
#define WIN_CURSOR_APPSTARTING IDC_APPSTARTING
#define WIN_CURSOR_ARROW IDC_ARROW
#define WIN_CURSOR_CROSS IDC_CROSS
#define WIN_CURSOR_HAND IDC_HAND
#define WIN_CURSOR_HELP IDC_HELP
#define WIN_CURSOR_IBEAM IDC_IBEAM
#define WIN_CURSOR_NO IDC_NO
#define WIN_CURSOR_SIZEALL IDC_SIZEALL
#define WIN_CURSOR_SIZENESW IDC_SIZENESW
#define WIN_CURSOR_SIZENS IDC_SIZENS
#define WIN_CURSOR_SIZENWSE IDC_SIZENWSE
#define WIN_CURSOR_SIZEWE IDC_SIZEWE
#define WIN_CURSOR_UPARROW IDC_UPARROW
#define WIN_CURSOR_WAIT IDC_WAIT
void ofxWinCursor(LPCTSTR name);

#endif
#endif