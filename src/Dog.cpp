#include "../include/Dog.h"
using namespace std;

Dog::Dog(string earType, double height, string tailColour) {
  this->earType = earType;
  this->height = height;
  this->tailColour = tailColour;
}

string Dog::getEarType() {
  return this->earType;
}

double Dog::getHeight() {
  return this->height;
}

string Dog::getTailColour() {
  return this->tailColour;
}
