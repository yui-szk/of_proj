#include "planet.h"

// void Planet::setup() { jupiterImg.load("image/jupiter.png"); }
void Planet::update() {}
void Planet::draw() {
  float x, z;
  float earthR = 10;
  float sunR = 100;

  x = cos(theta) * (rotateR + sunR);
  z = sin(theta) * (rotateR + sunR);

  // ofPushMatrix();
  // ofTranslate(x, 0, z);
  // ofRotateDeg(deg);

  ofSetColor(255);
  texture.bind();
  ofDrawSphere(x, 0, z, planetR * earthR);
  texture.unbind();

  // deg += 1;
  // ofPopMatrix();
}
