#include "../include/Horse.h"
using namespace std;

Horse::Horse(string earType, double height, string tailColour) {
  this->earType = earType;
  this->height = height;
  this->tailColour = tailColour;
}

string Horse::getEarType() {
  return this->earType;
}

double Horse::getHeight() {
  return this->height;
}

string Horse::getTailColour() {
  return this->tailColour;
}
