//
//  NEWS_partB.h
//  OS2015_07_TV
//
//  Created by Tatsuya_Ishikawa on 2015/07/17.
//
//

#include "ofMain.h"
#include "baseScene.h"
#ifndef __OS2015_07_TV__NEWS_partB__
#define __OS2015_07_TV__NEWS_partB__

class NEWS_partB : public baseScene {
public:
    void setup();
    void update();
    void draw();
    
    ofSoundPlayer gender_age[2][14];
    ofSoundPlayer careful;
    void stopVideo();
    bool gender_ageIsPlayed;
    bool carefulIsPlayed;
    ofImage facePicture;
    ofImage title;
    
    int iAge;
    int iGender;
};

#endif /* defined(__OS2015_07_TV__NEWS_partB__) */
