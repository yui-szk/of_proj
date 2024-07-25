#pragma once

#include "ofMain.h"

class Planet {
 public:
  Planet() : planetR(0), rotateR(0), theta(0), color(ofColor::white) {}
  Planet(float _planetR, float _rotateR, float _theta, ofColor _color)
      : planetR(_planetR), rotateR(_rotateR), theta(_theta), color(_color) {}

  float planetR, rotateR, theta;
  ofColor color;

  void update();
  void draw();
};
