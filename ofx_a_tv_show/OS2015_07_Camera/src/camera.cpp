//
//  ofCamera.cpp
//  OS2015_07
//
//  Created by Tatsuya_Ishikawa on 2015/07/14.
//
//

#include "faceAPI.h"
#include "camera.h"

void camera::setup(){
    videoGrabber.setDeviceID(0);
    videoGrabber.initGrabber(640, 480);
     tracker.setup();
    isFirstDetect = true;
    
    sound.loadSound("se-033a.mp3");
    counter=countFrames;
    bShowVideo = false;
}

void camera::update(){
    videoGrabber.update();
    tracker.update(ofxCv::toCv(videoGrabber));
    counter ++;
    if(tracker.getFound()){
        // if(isFirstDetect){
        if(counter >= countFrames){
            camera::saveImage();
            //////sound.play();
            //isFirstDetect = false;
            counter = 0;
        }
    }
    else{
        //isFirstDetect = true;
    }
}

void camera::draw(){
    if(bShowVideo)
    videoGrabber.draw(0,0);
}

void camera::saveImage(){
    unsigned char *pix= videoGrabber.getPixels();
    img.setFromPixels(pix, 640, 480, OF_IMAGE_COLOR);
    PictureName = ofGetTimestampString() + "_0";
  //  img.saveImage(PictureName + ".jpg");
   img.saveImage("/Users/student/Dropbox/faceAPI/pictures/" +PictureName + ".jpg");
    cout << "captured!" << endl;
    faceAPI faceAPI;
    faceAPI.face_detect(PictureName);
    
}

ofVideoGrabber camera::*getVideoGrabberRef(){
    return &camera::videoGrabber;
}