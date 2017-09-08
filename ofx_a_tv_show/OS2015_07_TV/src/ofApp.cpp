#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(30);
    
    baseScene * sceneA = new TVshow();
    scenes.push_back(sceneA);
    baseScene * sceneB = new NEWS_partA();
    scenes.push_back(sceneB);
    baseScene * sceneC = new NEWS_partB();
    scenes.push_back(sceneC);
    baseScene * sceneD = new NEWS_partC();
    scenes.push_back(sceneD);
    
    currentScene = 0;
    scenes[currentScene]->setup();
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if(scenes[currentScene]->changeScene != currentScene){
        scenes[currentScene]->stopVideo();
        currentScene = scenes[currentScene]->changeScene;
        scenes[currentScene]->setup();
    }
    
    scenes[currentScene]->update();
    
    scenes[2]->gender = scenes[0]->gender;
    scenes[2]->age = scenes[0]->age;
    scenes[2]->filename = scenes[0]->filename;

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofTranslate(0, (1200-1080)/2);
    ofBackground(0);
    scenes[currentScene]->draw();
    
   
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
     
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
   //  scenes[currentScene]->stopVideo();
  //  currentScene = 1;
   // scenes[currentScene]->setup();
    scenes[0]->mouseP = true;
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
 //   scenes[currentScene]->stopVideo();
 //   currentScene = 0;
 //   scenes[currentScene]->setup();

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
