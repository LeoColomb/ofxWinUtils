// ********
// ofxWinUtils
// Usefull Windows Utils implementation for openFrameworks
// https://github.com/LeoColomb/ofxWinUtils
//
// Copyright (c) 2013 Leo Colombaro
// MIT License
// ********

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

//------------------------------------------------------------------------------
void ofxWinCursor(LPCTSTR cursorName) {
	HCURSOR hNewCurs;
	hNewCurs = LoadCursor(NULL, cursorName);
	SetClassLong(GetForegroundWindow(), GCL_HCURSOR, (LONG) hNewCurs);
}

//------------------------------------------------------------------------------
ofxWinTaskbarProgress::ofxWinTaskbarProgress() {
	m_pITaskBarList = NULL;
	m_bFailed = false;
}

ofxWinTaskbarProgress::~ofxWinTaskbarProgress() {
	if (m_pITaskBarList) {
		m_pITaskBarList->Release();
		CoUninitialize();
	}
}

void ofxWinTaskbarProgress::SetProgressState(HWND hwnd, TBPFLAG flag) {
	if (setup())
		m_pITaskBarList->SetProgressState(hwnd, flag);
}

void ofxWinTaskbarProgress::SetProgressValue(HWND hwnd, ULONGLONG ullCompleted, ULONGLONG ullTotal) {
	if (setup())
		m_pITaskBarList->SetProgressValue(hwnd, ullCompleted, ullTotal);
}

bool ofxWinTaskbarProgress::setup() {
	if (m_pITaskBarList)
		return true;

	if (m_bFailed)
		return false;

	CoInitialize(NULL);
	CoCreateInstance(CLSID_TaskbarList,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_ITaskbarList,
		(void **) &m_pITaskBarList);

	if (m_pITaskBarList)
		return true;

	m_bFailed = true;
	CoUninitialize();
	return false;
}

#endif
