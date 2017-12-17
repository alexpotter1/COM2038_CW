#include "../include/Horse.h"
using namespace std;

/* Paramaterised constructor, constructing a horse object with the given attrbutes.
Accepts all the parameters and passes some of them to the Animal superclass */
Horse::Horse(string breed, string name, string colour, string dadName, string mumName,
         string earType, string height, string tailColour)
         : Animal(breed, name, colour, dadName, mumName)
         {
           this->earType = earType;
           this->height = height;
           this->tailColour = tailColour;
         }

string Horse::getEarType() const {
  return this->earType;
}

string Horse::getHeight() const {
  return this->height;
}

string Horse::getTailColour() const {
  return this->tailColour;
}
