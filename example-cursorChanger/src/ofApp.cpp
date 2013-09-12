#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key)
	{
	case 'a':
		ofxWinCursor(WIN_CURSOR_APPSTARTING);
		break;
	case 'z':
		ofxWinCursor(WIN_CURSOR_UPARROW);
		break;
	case 'e':
		ofxWinCursor(WIN_CURSOR_CROSS);
		break;
	case 'r':
		ofxWinCursor(WIN_CURSOR_HAND);
		break;
	case 't':
		ofxWinCursor(WIN_CURSOR_HELP);
		break;
	case 'y':
		ofxWinCursor(WIN_CURSOR_IBEAM);
		break;
	case 'u':
		ofxWinCursor(WIN_CURSOR_NO);
		break;
	default:
		break;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
