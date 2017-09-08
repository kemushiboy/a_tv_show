#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(30);
    viewCam = false;
    camera.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    camera.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    if(viewCam)
    camera.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
       case '1':
       // camera.saveImage();
            viewCam = !viewCam;
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
