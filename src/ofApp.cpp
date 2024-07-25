#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  light.setPosition(0.0f, 0.0f, 0.0f);
  light.setPointLight();
  light.enable();

  ofSetDepthTest(true);
  ofEnableSmoothing();

  //
  ofEnableNormalizedTexCoords();

  mercuryImg.load("image/mercury.png");
  marsImg.load("image/mars.png");
  jupiterImg.load("image/jupiter.png");
  venusImg.load("image/venus.png");
  earthImg.load("image/earth.png");
  saturnImg.load("image/saturn.png");
  uranusImg.load("image/uranus.png");
  neptuneImg.load("image/neptune.png");
}

//--------------------------------------------------------------
void ofApp::update() {
  mercury = Planet(0.39, 40, ofGetElapsedTimef() * 2.5);
  venus = Planet(0.95, 70, ofGetElapsedTimef() * 2);
  earth = Planet(1, 100, ofGetElapsedTimef() * 1.5);
  mars = Planet(0.54, 150, ofGetElapsedTimef());
  jupiter = Planet(11, 500, ofGetElapsedTimef() * 0.3);
  saturn = Planet(9.1, 1000, ofGetElapsedTimef() * 0.5);
  uranus = Planet(3.8, 1900, ofGetElapsedTimef() * 0.7);
  neptune = Planet(3.9, 3000, ofGetElapsedTimef() * 0.8);
}

//--------------------------------------------------------------
void ofApp::draw() {
  cam.begin();

  mercury.draw();
  venus.draw();
  earth.draw();

  marsImg.bind();
  mars.draw();
  marsImg.unbind();

  jupiterImg.bind();
  jupiter.draw();
  jupiterImg.unbind();

  saturn.draw();
  uranus.draw();
  neptune.draw();

  ofSetColor(255);
  ofDrawSphere(0, 0, 100);

  cam.end();
}

//--------------------------------------------------------------
void ofApp::exit() {}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
