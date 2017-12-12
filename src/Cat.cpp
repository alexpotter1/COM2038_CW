#include "../include/Cat.h"
using namespace std;

Cat::Cat(string earType, double height, string tailColour) {
  this->earType = earType;
  this->height = height;
  this->tailColour = tailColour;
}

string Cat::getEarType() {
  return this->earType;
}

double Cat::getHeight() {
  return this->height;
}

string Cat::getTailColour() {
  return this->tailColour;
}
