#include "../include/Cat.h"
using namespace std;

/* Paramaterised constructor, constructing a cat object with the given attrbutes.
Accepts all the parameters and passes some of them to the Animal superclass */
Cat::Cat(string breed, string name, string colour, string dadName, string mumName,
         string earType, string height, string tailColour)
         : Animal(breed, name, colour, dadName, mumName)
         {
           this->earType = earType;
           this->height = height;
           this->tailColour = tailColour;
         }

string Cat::getEarType() const {
  return this->earType;
}

string Cat::getHeight() const {
  return this->height;
}

string Cat::getTailColour() const {
  return this->tailColour;
}
