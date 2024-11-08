#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "ofxGui.h"
#include "planet.h"

class ofApp : public ofBaseApp {
  ofEasyCam cam;
  ofLight light;

 public:
  void setup() override;
  void update() override;
  void draw() override;
  void exit() override;

  void keyPressed(int key) override;
  void keyReleased(int key) override;
  void mouseMoved(int x, int y) override;
  void mouseDragged(int x, int y, int button) override;
  void mousePressed(int x, int y, int button) override;
  void mouseReleased(int x, int y, int button) override;
  void mouseScrolled(int x, int y, float scrollX, float scrollY) override;
  void mouseEntered(int x, int y) override;
  void mouseExited(int x, int y) override;
  void windowResized(int w, int h) override;
  void dragEvent(ofDragInfo dragInfo) override;
  void gotMessage(ofMessage msg) override;

  void lightCon();

  ofxPanel gui;
  ofxFloatSlider speed;
  ofxButton lightBtn;

  ofxAssimpModelLoader space;

  ofMaterial sun;
  ofMaterial stars;

  ofImage sunImg;
  ofImage mercuryImg;
  ofImage venusImg;
  ofImage earthImg;
  ofImage marsImg;
  ofImage jupiterImg;
  ofImage saturnImg;
  ofImage uranusImg;
  ofImage neptuneImg;
  ofImage spaceImg;

  Planet mercury;
  Planet venus;
  Planet earth;
  Planet mars;
  Planet jupiter;
  Planet saturn;
  Planet uranus;
  Planet neptune;
};
