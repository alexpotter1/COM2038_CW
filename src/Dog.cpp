#include "../include/Dog.h"
using namespace std;

Dog::Dog(string breed, string name, string colour, string dadName, string mumName,
         string earType, string height, string tailColour)
         : Animal(breed, name, colour, dadName, mumName)
         {
           this->earType = earType;
           this->height = height;
           this->tailColour = tailColour;
         }

string Dog::getEarType() {
  return this->earType;
}

string Dog::getHeight() {
  return this->height;
}

string Dog::getTailColour() {
  return this->tailColour;
}
