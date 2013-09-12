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
// http://msdn.microsoft.com/en-us/library/windows/desktop/ms646829.aspx
//------------------------------------------------------------------------------
ofColor ofxWinColorDialog();

#endif
#endif