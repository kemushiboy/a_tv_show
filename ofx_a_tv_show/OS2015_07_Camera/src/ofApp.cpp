#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(30);
    
    
    
//    bool result = response.open("sample.json");
//    if(!result){
//        cout<<"failed to get JSON data!"<<endl;
//    }else{
//        cout<<response.getRawString() << endl;
//    }
    
    camera.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    camera.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    camera.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
       case '1':
       // camera.saveImage();
        camera.bShowVideo = !camera.bShowVideo;
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
