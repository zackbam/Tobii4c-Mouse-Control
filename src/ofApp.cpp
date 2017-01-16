#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	myTobii.setup();
	X = 0;
	Y = 0;
	counter = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	if (myTobii.success) {
		X = 0.97*X + 0.03*myTobii.eventParams.X;
		Y = 0.97*Y + 0.03*myTobii.eventParams.Y;
	}
		SetCursorPos(X , Y);
		//printf("%f\n", ofGetFrameRate());
		if (counter++ > (int)ofGetFrameRate()*5) {
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			counter = 0;
		}
}

//--------------------------------------------------------------
void ofApp::draw(){

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