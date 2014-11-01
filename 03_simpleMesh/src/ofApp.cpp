#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofLoadImage(meshTexture, "texture.jpg");
    
    //--------------------------------------------------------------
    ofMesh customMesh;
    customMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
    customMesh.addVertex(ofVec3f(-100, -100));
    customMesh.addVertex(ofVec3f(-100, 100));
    customMesh.addVertex(ofVec3f(100, -100));
    customMesh.addVertex(ofVec3f(100, 100));
    
    customMesh.addTexCoord(ofVec2f(0, 0));
    customMesh.addTexCoord(ofVec2f(0, 1));
    customMesh.addTexCoord(ofVec2f(1, 0));
    customMesh.addTexCoord(ofVec2f(1, 1));
    
    //--------------------------------------------------------------
    ofSpherePrimitive sphere(100, 20);
    ofCylinderPrimitive cylinder(100, 200, 20, 20);
    
    //--------------------------------------------------------------
    model.loadModel("head.dae");
    
    //--------------------------------------------------------------
    meshIndex = 0;
    meshes.push_back(customMesh);
    meshes.push_back(sphere.getMesh());
    meshes.push_back(cylinder.getMesh());
    meshes.push_back(model.getMesh(0));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofEnableDepthTest();
    
    float dist = 400;
    camera.setDistance(dist);
    camera.begin();
    
    ofPushStyle();
    
    ofMesh & mesh = meshes[meshIndex];
    
    ofEnableNormalizedTexCoords();
    meshTexture.bind();

    ofSetColor(ofColor::white);
    mesh.drawFaces();
    
    ofDisableNormalizedTexCoords();
    meshTexture.unbind();
    
    ofSetColor(ofColor::black);
    mesh.drawWireframe();
    
    ofPopStyle();
    
    camera.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_LEFT) {
        meshIndex -= 1;
        if(meshIndex < 0) {
            meshIndex = meshes.size() - 1;
        }
    } else if(key == OF_KEY_RIGHT) {
        meshIndex += 1;
        if(meshIndex > meshes.size() - 1) {
            meshIndex = 0;
        }
    }
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