/**
 * ofxWinUtils
 * Usefull Windows Utils implementation for openFrameworks
 * https://github.com/LeoColomb/ofxWinUtils
 *
 * Copyright (c) 2013 Leo Colombaro
 * MIT License
 */

#include "ofxWinUtils.h"

#ifndef TARGET_WIN32
void ofxWinError() { ofLogWarning("ofxWinUtils") << "this addon support only win"; };
#else

//------------------------------------------------------------------------------
ofColor ofxWinColorDialog() {
	ofColor colorResult;

	CHOOSECOLOR cc;
	static COLORREF acrCustClr[16];
	HBRUSH hbrush;
	static DWORD rgbCurrent;

	ZeroMemory(&cc, sizeof(cc));
	cc.lStructSize = sizeof(cc);
	cc.hwndOwner = GetForegroundWindow();
	cc.lpCustColors = (LPDWORD) acrCustClr;
	cc.rgbResult = rgbCurrent;
	cc.Flags = CC_FULLOPEN | CC_RGBINIT;
	if (ChooseColor(&cc) == TRUE) {
		hbrush = CreateSolidBrush(cc.rgbResult);
		rgbCurrent = cc.rgbResult; 
	}

	colorResult.b = (rgbCurrent >> 16) & 0xff;
	colorResult.g = (rgbCurrent >> 8) & 0xff;
	colorResult.r = rgbCurrent & 0xff;
	return colorResult;
}

#endif
