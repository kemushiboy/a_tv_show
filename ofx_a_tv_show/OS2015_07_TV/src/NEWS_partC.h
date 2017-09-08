//
//  NEWS_partC.h
//  OS2015_07_TV
//
//  Created by Tatsuya_Ishikawa on 2015/07/17.
//
//
#include "ofMain.h"
#include "baseScene.h"
#ifndef __OS2015_07_TV__NEWS_partC__
#define __OS2015_07_TV__NEWS_partC__

class NEWS_partC : public baseScene {
public:
    void setup();
    void update();
    void draw();
    
    ofVideoPlayer news;
    void stopVideo();
};


#endif /* defined(__OS2015_07_TV__NEWS_partC__) */
