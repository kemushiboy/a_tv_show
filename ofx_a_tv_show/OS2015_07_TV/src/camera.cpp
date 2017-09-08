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
    videoGrabber.initGrabber(1920, 1080);
    
}

void camera::update(){
    videoGrabber.update();

}

void camera::draw(){
   // videoGrabber.draw(0,0);
}

void camera::saveImage(){
    unsigned char *pix= videoGrabber.getPixels();
    img.setFromPixels(pix, 1920, 1080, OF_IMAGE_COLOR);
    PictureName = ofGetTimestampString() + "_0";
  //  img.saveImage(PictureName + ".jpg");
   img.saveImage("/Users/Ishikawa/" +PictureName + ".jpg");
    cout << "captured!" << endl;
    faceAPI faceAPI;
    faceAPI.face_detect(PictureName);
    
}