//
//  NEWS_partC.cpp
//  OS2015_07_TV
//
//  Created by Tatsuya_Ishikawa on 2015/07/17.
//
//

#include "NEWS_partC.h"

void NEWS_partC::setup(){
    
    if(!news.isLoaded()){
        news.loadMovie("news_end.mp4");
        news.setLoopState(OF_LOOP_NONE);
    }
    news.play();
    changeScene = 3;
}

void NEWS_partC::update(){
    news.update();
    if(news.getIsMovieDone()){
        changeScene = 0;
        //  NEWS_partA::stopVideo();
    }
}

void NEWS_partC::draw(){
    news.draw(0,0);
}

void NEWS_partC::stopVideo(){
    news.stop();
    news.setFrame(1);
    
}