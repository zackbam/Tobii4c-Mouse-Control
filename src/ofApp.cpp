#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	myTobii.setup();
	gaze.x = 0;
	gaze.y = 0;
	counter = 0;
	selected = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	if (myTobii.success) {
		previous = gaze;
		gaze.x = 0.95*gaze.x + 0.05*myTobii.eventParams.X;
		gaze.y = 0.95*gaze.y + 0.05*myTobii.eventParams.Y;
	}
	SetCursorPos(gaze.x, gaze.y);
	if (ofDist(previous.x, previous.y, gaze.x, gaze.y) < 5) {
		if (counter++ > 120) {
			switch (selected) {
			case 0:
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
				break;
			case 1:
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			case 2:
				mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
			}

			if (gaze.x > ofGetWindowPositionX() && gaze.x<ofGetWindowPositionX() + ofGetWidth() && gaze.y>ofGetWindowPositionY() && gaze.y < ofGetWindowPositionY() + ofGetHeight()) {
				if (gaze.x < ofGetWindowPositionX() + ofGetWidth() / 3)
					selected = 0;
				else if (gaze.x < ofGetWindowPositionX() + ofGetWidth() / 3 * 2)
					selected = 1;
				else
					selected = 2;
				//printf("%d\n", selected);
			}
			counter = 0;
		}
	}
	else
		counter = 0;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofRectangle r1(ofPoint(0, 0), ofPoint(ofGetWidth() / 3, ofGetHeight()));
	ofRectangle r2(ofPoint(ofGetWidth() / 3, 0), ofPoint(ofGetWidth() / 3*2, ofGetHeight()));
	ofRectangle r3(ofPoint(ofGetWidth() / 3 * 2,0), ofPoint(ofGetWidth(), ofGetHeight()));
	ofLine(ofPoint(ofGetWidth() / 3, 0), ofPoint(ofGetWidth() / 3, ofGetHeight()));
	ofLine(ofPoint(ofGetWidth() / 3*2, 0), ofPoint(ofGetWidth() / 3*2, ofGetHeight()));
	ofSetColor(80);
	switch (selected)
	{
	case 0:
		ofDrawRectangle(r1);
		break;
	case 1:
		ofDrawRectangle(r2);
		break;
	case 2:
		ofDrawRectangle(r3);
		break;
	}
	string temp1 = "single click";
	string temp2 = "double click";
	string temp3 = "right click";
	ofSetColor(0);
	ofDrawBitmapString(temp1, 5, ofGetHeight()/2);
	ofDrawBitmapString(temp2, ofGetWidth()*0.38, ofGetHeight() / 2);
	ofDrawBitmapString(temp3, ofGetWidth()*0.71, ofGetHeight() / 2);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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