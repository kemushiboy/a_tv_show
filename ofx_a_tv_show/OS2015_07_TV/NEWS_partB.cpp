//
//  NEWS_partB.cpp
//  OS2015_07_TV
//
//  Created by Tatsuya_Ishikawa on 2015/07/17.
//
//

#include "NEWS_partB.h"

void NEWS_partB::setup(){
    if(!careful.isLoaded()){
   for(int i=0; i<14; i++){
       gender_age[0][i].loadSound("gender_age/male_" + ofToString(i+1) + ".wav");
       gender_age[1][i].loadSound("gender_age/female_" + ofToString(i+1) + ".wav");
       gender_age[0][i].setLoop(FALSE);
       gender_age[1][i].setLoop(FALSE);
   }
    careful.loadSound("gender_age/careful.wav");
        title.loadImage("title.png");
    }
   
    facePicture.loadImage("/Users/Ishikawa/Dropbox/faceAPI/pictures/" + filename);
    
    if(0 <= age && age <=7)
        iAge = 0;
    else if(8 <= age && age <=12)
        iAge = 1;
    else if(13 <= age && age <= 17)
        iAge = 2;
    else if(18 <= age && age <= 22)
        iAge = 3;
    else if(23 <= age && age <= 27)
        iAge = 4;
    else if(28 <= age && age <=32)
        iAge = 5;
    else if(33 <= age && age <= 37)
        iAge = 6;
    else if(38 <= age && age <= 42)
        iAge = 7;
    else if(43 <= age && age <= 47)
        iAge = 8;
    else if(48 <= age && age <= 52)
        iAge = 9;
    else if(53 <= age && age <= 57)
        iAge = 10;
    else if(58 <= age && age <= 62)
        iAge = 11;
    else if(63 <= age && age <= 67)
        iAge = 12;
    else if(68 <= age)
        iAge = 13;
    else
        iAge = 3;
    
    if(gender == "female")
        iGender = 1;
    else
        iGender = 0;
    
    gender_age[iGender][iAge].play();
     changeScene = 2;
    gender_ageIsPlayed = false;
    carefulIsPlayed = false;
}

void NEWS_partB::update(){
    if(gender_age[iGender][iAge].getIsPlaying()==false && gender_ageIsPlayed==false){
        gender_ageIsPlayed = true;
        careful.play();
    }
    if(gender_ageIsPlayed == true && careful.getIsPlaying()==false){
        changeScene = 3;
    }
}

void NEWS_partB::draw(){
    facePicture.draw( (ofGetWidth() - (ofGetHeight()/facePicture.getHeight())*facePicture.getWidth())/2 , 0, (ofGetHeight()/facePicture.getHeight())*facePicture.getWidth(), ofGetHeight());
    title.draw(0,0);
}

void NEWS_partB::stopVideo(){
    
}