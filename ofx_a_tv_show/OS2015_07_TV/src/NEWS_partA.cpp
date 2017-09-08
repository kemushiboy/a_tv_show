//
//  NEWS_partA.cpp
//  OS2015_07_TV
//
//  Created by Tatsuya_Ishikawa on 2015/07/16.
//
//

#include "NEWS_partA.h"
void NEWS_partA::setup(){
    
    if(!news.isLoaded()){
    news.loadMovie("news_start.mp4");
    news.setLoopState(OF_LOOP_NONE);
    }
     news.play();
    changeScene = 1;
}

void NEWS_partA::update(){
   news.update();
    if(news.getIsMovieDone()){
        changeScene = 2;
      //  NEWS_partA::stopVideo();
    }
}

void NEWS_partA::draw(){
   news.draw(0,0);
}

void NEWS_partA::stopVideo(){
    news.stop();
    news.setFrame(1);
    
}