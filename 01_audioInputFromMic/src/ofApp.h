#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

public:

    void setup();
    void update();
    void draw();
    void drawSamples(vector<float> samples);
    
    void audioIn(float * input, int bufferSize, int nChannels);
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofSoundStream soundStream;
    vector<float> samplesChannelL;
    vector<float> samplesChannelR;

};
