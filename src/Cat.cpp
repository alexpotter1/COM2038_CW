#include "../include/Cat.h"
using namespace std;

Cat::Cat(string breed, string name, string colour, string dadName, string mumName,
         string earType, string height, string tailColour)
         : Animal(breed, name, colour, dadName, mumName)
         {
           this->earType = earType;
           this->height = height;
           this->tailColour = tailColour;
         }

string Cat::getEarType() {
  return this->earType;
}

string Cat::getHeight() {
  return this->height;
}

string Cat::getTailColour() {
  return this->tailColour;
}
