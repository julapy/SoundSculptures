#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofLoadImage(meshTexture, "texture.jpg");
    
    //--------------------------------------------------------------
    ofMesh customMesh;
    customMesh.setMode(OF_PRIMITIVE_TRIANGLES);
    
    customMesh.addVertex(ofVec3f(-100, -100));
    customMesh.addVertex(ofVec3f(-100, 100));
    customMesh.addVertex(ofVec3f(100, -100));
    customMesh.addVertex(ofVec3f(100, 100));
    
    customMesh.addTexCoord(ofVec2f(0, 0));
    customMesh.addTexCoord(ofVec2f(0, 1));
    customMesh.addTexCoord(ofVec2f(1, 0));
    customMesh.addTexCoord(ofVec2f(1, 1));
    
    customMesh.addIndex(0);
    customMesh.addIndex(3);
    customMesh.addIndex(1);
    
    customMesh.addIndex(0);
    customMesh.addIndex(2);
    customMesh.addIndex(3);
    
    //--------------------------------------------------------------
    ofSpherePrimitive sphere(100, 20, OF_PRIMITIVE_TRIANGLES);
    
    //--------------------------------------------------------------
    model.loadModel("head.dae");
    
    //--------------------------------------------------------------
    meshIndex = 0;
    meshes.push_back(customMesh);
    meshes.push_back(sphere.getMesh());
    meshes.push_back(model.getMesh(0));
    
    //--------------------------------------------------------------
    gui.setup("gui");
    gui.add(meshIndex.setup("meshIndex", 0, 0, meshes.size()-1));
    gui.add(bUseTexture.setup("bUseTexture", false));
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
    
    ofMesh & mesh = meshes[meshIndex];
    
    if(bUseTexture == true) {
        ofEnableNormalizedTexCoords();
        meshTexture.bind();
    }

    ofSetColor(ofColor::white);
    mesh.drawFaces();
    
    if(bUseTexture == true) {
        meshTexture.unbind();
        ofDisableNormalizedTexCoords();
    }
    
    ofSetColor(ofColor::black);
    mesh.drawWireframe();
    
    camera.end();
    
    ofDisableDepthTest();
    ofSetColor(ofColor::white);
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_LEFT) {
        meshIndex = meshIndex - 1;
        if(meshIndex < 0) {
            meshIndex = meshes.size() - 1;
        }
    } else if(key == OF_KEY_RIGHT) {
        meshIndex = meshIndex + 1;
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