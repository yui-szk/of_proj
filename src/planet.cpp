#include "planet.h"

void Planet::update() {}
void Planet::draw() {
  float x, z;
  float earthR = 10;
  float sunR = 100;

  x = cos(theta) * (rotateR + sunR);
  z = sin(theta) * (rotateR + sunR);

  ofSetColor(255);
  ofDrawSphere(x, 0, z, planetR * earthR);
}
