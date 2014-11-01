#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    int channelsOut = 0;        // number of requested output channels (i.e. 2 for stereo).
    int channelsIn = 2;         // number of requested input channels.
    int sampleRate = 44100;     // requested sample rate (44100 is typical).
    int bufferSize = 256;       // requested buffer size (256 is typical).
    int numOfBuffers = 4;       // number of buffers to queue, less buffers will be more responsive, but less stable.

    soundStream.setup(this, channelsOut, channelsIn, sampleRate, bufferSize, numOfBuffers);
    
    samplesChannelL.assign(bufferSize, 0.0);
    samplesChannelR.assign(bufferSize, 0.0);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //
}

//--------------------------------------------------------------
void ofApp::draw(){

    // split the screen into two rectangles, top and bottom.
    // these rectangle objects will be used to draw the audio samples
    // for the left and right channels.
    
    ofRectangle rectTop(0, 0, ofGetWidth(), ofGetHeight() * 0.5);
    ofRectangle rectBot(0, ofGetHeight() * 0.5, ofGetWidth(), ofGetHeight() * 0.5);
    
    ofPushStyle();
    
    ofSetColor(ofColor::paleGreen);
    ofRect(rectTop);
    
    ofSetColor(ofColor::paleVioletRed);
    ofRect(rectBot);
    
    ofNoFill();
    ofSetLineWidth(4);
    ofSetColor(ofColor::white);
    
    ofRect(rectTop);
    ofRect(rectBot);
    
    ofLine(rectTop.x,
           rectTop.y + rectTop.height * 0.5,
           rectTop.x + rectTop.width,
           rectTop.y + rectTop.height * 0.5);
    
    ofLine(rectBot.x,
           rectBot.y + rectBot.height * 0.5,
           rectBot.x + rectBot.width,
           rectBot.y + rectBot.height * 0.5);
    
    ofSetColor(ofColor::black);
    ofDrawBitmapString("LEFT CHANNEL", 10, 20);
    ofDrawBitmapString("RIGHT CHANNEL", 10, ofGetHeight() * 0.5 + 20);
    
    ofPopStyle();
    
    //----------------------------------------------------------
    ofPushMatrix();
    ofTranslate(0, ofGetHeight() * 0.25);
    drawSamples(samplesChannelL);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(0, ofGetHeight() * 0.75);
    drawSamples(samplesChannelR);
    ofPopMatrix();
}

void ofApp::drawSamples(vector<float> samples) {
    
    int sampleWidth = ofGetWidth() / samples.size();
    int sampleHeight = ofGetHeight() / 4;
    int numOfSamples = samples.size();
    
    for(int i=0; i<numOfSamples; i++) {
        int x = ofMap(i, 0, numOfSamples-1, 0, ofGetWidth()-sampleWidth);
        int y = 0;
        int w = sampleWidth;
        int h = samples[i] * sampleHeight;
        
        ofRect(x, y, w, h);
    }
}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels) {

    for(int i = 0; i<bufferSize; i++) {
        samplesChannelL[i] = input[i * 2 + 0];
        samplesChannelR[i] = input[i * 2 + 1];
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}