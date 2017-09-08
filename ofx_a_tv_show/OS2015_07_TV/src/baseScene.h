//
//  baseScene.h
//  OS2015_07_TV
//
//  Created by Tatsuya_Ishikawa on 2015/07/16.
//
//
#include "ofMain.h"
#ifndef OS2015_07_TV_baseScene_h
#define OS2015_07_TV_baseScene_h

class baseScene {
public:
    
    virtual void setup(){};
    virtual void update(){};
    virtual void draw(){};
    int changeScene;
    virtual void stopVideo(){};
    bool mouseP;
    
    string gender;
    int age;
    string filename;
};


#endif
