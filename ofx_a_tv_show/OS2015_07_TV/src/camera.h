//
//  camera.h
//  OS2015_07
//
//  Created by Tatsuya_Ishikawa on 2015/07/14.
//
//
#include "ofMain.h"


class camera : public ofBaseApp{
    public:
    void setup();
    void update();
    void draw();
    
    ofVideoGrabber videoGrabber;
    ofImage img;
    void saveImage();
    string PictureName;
};