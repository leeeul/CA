#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(580, 640);
    ofBackground(255);
    
    ca = Ca(gridSize);
    ca.stillMode(false);
}

//--------------------------------------------------------------
void ofApp::update(){    
    int frameGap = 1;
    if(ofGetFrameNum()%frameGap == 0){
//        rule = (int)(ofNoise(ofGetElapsedTimef())*256);
        cout<<"rule : "<<rule<<endl;
        ca.setRule(rule);//0~255
        ca.update();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ca.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key==OF_KEY_UP){
        rule++;
    }else if(key==OF_KEY_DOWN){
        rule--;
    }else if(key==' '){
        ofSaveScreen(ofGetTimestampString()+".png");
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}
