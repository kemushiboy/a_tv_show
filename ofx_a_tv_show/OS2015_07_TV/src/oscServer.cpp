//
//  oscServer.cpp
//  OS2015_07_TV
//
//  Created by Tatsuya_Ishikawa on 2015/07/16.
//
//

#include "oscServer.h"

void oscServer::setup(){
    receiver.setup(3333);
    getOscMessage = false;
    while( receiver.hasWaitingMessages() ){
        ofxOscMessage m;
        receiver.getNextMessage( &m );
    }
}

void oscServer::update(){
    //現在順番待ちのOSCメッセージがあるか確認
    while( receiver.hasWaitingMessages() )
    {
        //次のメッセージを取得
        ofxOscMessage m;
        receiver.getNextMessage( &m );
        gender = m.getArgAsString(0);
        age = m.getArgAsInt32(1);
        filename = m.getArgAsString(2);
        
        getOscMessage = true;
        cout << "recieved osc message!"<< endl;
    }
}
    

void oscServer::draw(){
    
}