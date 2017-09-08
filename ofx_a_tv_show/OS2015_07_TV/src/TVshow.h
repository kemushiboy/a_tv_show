//
//  TVshow.h
//  OS2015_07_TV
//
//  Created by Tatsuya_Ishikawa on 2015/07/16.
//
//
#include "ofMain.h"
#include "baseScene.h"
#include "oscServer.h"

#ifndef __OS2015_07_TV__TVshow__
#define __OS2015_07_TV__TVshow__

class TVshow : public baseScene {
public:
    void setup();
    void update();
    void draw();
    
    ofVideoPlayer programmedVideo;
    oscServer * osc;
    
    void stopVideo();
        
};


#endif /* defined(__OS2015_07_TV__TVshow__) */
