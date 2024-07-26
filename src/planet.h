#pragma once

#include "ofMain.h"

class Planet {
 public:
  Planet() : planetR(0), rotateR(0), theta(0), texture() {}
  Planet(float _planetR, float _rotateR, float _theta, ofImage _texture)
      : planetR(_planetR),
        rotateR(_rotateR),
        theta(_theta),
        texture(_texture) {}

  float planetR, rotateR, theta;
  ofImage texture;

  void update();
  void draw();
};
