#pragma once

#include "ofMain.h"

class Planet {
 public:
  Planet() : planetR(0), rotateR(0), theta(0) {}
  Planet(float _planetR, float _rotateR, float _theta)
      : planetR(_planetR), rotateR(_rotateR), theta(_theta) {}

  float planetR, rotateR, theta;

  void update();
  void draw();
};
