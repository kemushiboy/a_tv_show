//
//  oscServer.h
//  OS2015_07_TV
//
//  Created by Tatsuya_Ishikawa on 2015/07/16.
//
//
#include "ofxOsc.h"
#include "ofMain.h"

#ifndef __OS2015_07_TV__oscServer__
#define __OS2015_07_TV__oscServer__

class oscServer : public ofBaseApp{
public:
    
    void setup();
    void update();
    void draw();
    
    ofxOscReceiver  receiver;
    string gender;
    int age;
    string filename;
    bool getOscMessage;
};



#endif /* defined(__OS2015_07_TV__oscServer__) */
