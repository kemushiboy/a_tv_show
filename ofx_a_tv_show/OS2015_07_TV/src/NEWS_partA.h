//
//  NEWS_partA.h
//  OS2015_07_TV
//
//  Created by Tatsuya_Ishikawa on 2015/07/16.
//
//
#include "ofMain.h"
#include "baseScene.h"
#ifndef __OS2015_07_TV__NEWS_partA__
#define __OS2015_07_TV__NEWS_partA__

class NEWS_partA : public baseScene {
public:
    void setup();
    void update();
    void draw();
    
    ofVideoPlayer news;
    void stopVideo();
};





#endif /* defined(__OS2015_07_TV__NEWS_partA__) */
