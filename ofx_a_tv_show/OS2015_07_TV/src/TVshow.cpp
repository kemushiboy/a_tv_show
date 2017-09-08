//
//  TVshow.cpp
//  OS2015_07_TV
//
//  Created by Tatsuya_Ishikawa on 2015/07/16.
//
//

#include "TVshow.h"

void TVshow::setup(){
     if(!programmedVideo.isLoaded()){
     programmedVideo.loadMovie("video.mp4");
     osc = new oscServer;
     }
     programmedVideo.play();
    osc->setup();
    osc->getOscMessage = false;
    mouseP = false;
    changeScene=0;
}

void TVshow::update(){
    programmedVideo.update();
    osc->update();
    
    if(osc->getOscMessage==true || mouseP==true){
        changeScene = 1;
        gender = osc->gender;
        age = osc->age;
        filename = osc->filename;
    }
    
    
  }

void TVshow::draw(){
     programmedVideo.draw(0,0,1920,1080);
}

void TVshow::stopVideo(){
  //  programmedVideo.setFrame(1);
    programmedVideo.stop();
     }