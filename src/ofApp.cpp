#include "ofApp.h"

float timeCount = 0;

float deg = 0;

ofColor sunColor;

//--------------------------------------------------------------
void ofApp::lightCon() {
  ofColor sunBlightColor(255, 240, 200);
  ofColor sunDarkColor(0, 0, 0);

  if (light.getIsEnabled()) {
    light.disable();
    sunColor = sunDarkColor;
  } else {
    light.enable();
    sunColor = sunBlightColor;
  }
}

void ofApp::setup() {
  cam.setVFlip(true);

  light.setPosition(0.0f, 0.0f, 0.0f);
  light.setPointLight();
  light.enable();

  ofSetDepthTest(true);
  ofEnableSmoothing();

  //
  ofEnableNormalizedTexCoords();

  sunImg.load("image/sun.png");
  mercuryImg.load("image/mercury.png");
  marsImg.load("image/mars.png");
  jupiterImg.load("image/jupiter.png");
  venusImg.load("image/venus.png");
  earthImg.load("image/earth.png");
  saturnImg.load("image/saturn.png");
  uranusImg.load("image/uranus.png");
  neptuneImg.load("image/neptune.png");

  stars.setEmissiveColor(255);

  lightBtn.addListener(this, &ofApp::lightCon);

  gui.setup();
  gui.add(speed.setup("speed", 0.01, 0, 0.2));
  gui.add(lightBtn.setup("light"));
}

//--------------------------------------------------------------
void ofApp::update() {
  sun.setEmissiveColor(sunColor);

  mercury = Planet(0.39, 40, timeCount * 1.606);
  venus = Planet(0.95, 70, timeCount * 1.176);
  earth = Planet(1, 100, timeCount);
  mars = Planet(0.54, 150, timeCount * 0.810);
  jupiter = Planet(11, 500, timeCount * 0.439);
  saturn = Planet(9.1, 1000, timeCount * 0.324);
  uranus = Planet(3.9, 1900, timeCount * 0.228);
  neptune = Planet(3.8, 3000, timeCount * 0.182);

  timeCount += speed;
  deg += 0.1;
}

//--------------------------------------------------------------
void ofApp::draw() {
  cam.begin();
  ofEnableDepthTest();

  mercuryImg.bind();
  mercury.draw();
  mercuryImg.unbind();

  venusImg.bind();
  venus.draw();
  venusImg.unbind();

  earthImg.bind();
  earth.draw();
  earthImg.unbind();

  marsImg.bind();
  mars.draw();
  marsImg.unbind();

  jupiterImg.bind();
  jupiter.draw();
  jupiterImg.unbind();

  saturnImg.bind();
  saturn.draw();
  saturnImg.unbind();

  uranusImg.bind();
  uranus.draw();
  uranusImg.unbind();

  neptuneImg.bind();
  neptune.draw();
  neptuneImg.unbind();

  sun.begin();
  sunImg.bind();
  ofSetColor(255);
  ofDrawSphere(0, 0, 100);
  sunImg.unbind();
  sun.end();

  // stars.begin();
  // jupiterImg.bind();
  // ofDrawSphere(0, 0, 10000);
  // jupiterImg.unbind();
  // stars.end();

  ofDisableDepthTest();
  cam.end();

  glDisable(GL_LIGHTING);
  glDisable(GL_DEPTH_TEST);
  gui.draw();
  glEnable(GL_LIGHTING);
  glEnable(GL_DEPTH_TEST);
}

//--------------------------------------------------------------
void ofApp::exit() {}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
  if (key == 's') {
    speed = 0;
  }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
  if (key == 's') {
    speed = 0.01;
  }
}

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

// TODO: 土星に輪（Noise）を追加
// TODO: 周囲に星空の背景（球）
// TODO: 自転させる
// TODO: 衛星の追加
// TODO: 各惑星にカメラがフォーカスできるようにする
// TODO: 軌跡の追加
// TODO: 物理演算を追加して、シミュレーション化