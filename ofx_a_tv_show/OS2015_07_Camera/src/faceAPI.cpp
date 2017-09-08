//
//  faceAPI.cpp
//  OS2015_07
//
//  Created by Tatsuya_Ishikawa on 2015/07/14.
//
//

#include "faceAPI.h"
void faceAPI::face_detect(string filename){
    string comand = "ruby /Users/student/Dropbox/faceAPI/faceAPI_detectAndSimilar.rb " + filename;
    system(comand.c_str());
}