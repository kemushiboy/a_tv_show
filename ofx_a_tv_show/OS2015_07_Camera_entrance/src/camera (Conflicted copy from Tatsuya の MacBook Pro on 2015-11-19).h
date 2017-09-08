//
//  camera.h
//  OS2015_07
//
//  Created by Tatsuya_Ishikawa on 2015/07/14.
//
//
#include "ofMain.h"
#include "ofxCv.h"
#include "ofxFaceTrackerThreaded.h"
#define countFrames 900


class camera : public ofBaseApp{
    public:
    void setup();
    void update();
    void draw();
    
    ofVideoGrabber videoGrabber;
    ofVideoGrabber& getVideoGrabberRef();
    ofImage img;
    void saveImage();
    string PictureName;
    ofxFaceTracker tracker;
    bool isFirstDetect;
    int counter;
    int detectCounter;
    
    ofSoundPlayer sound;
};