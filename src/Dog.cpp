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

string Dog::getEarType() const {
  return this->earType;
}

<<<<<<< HEAD
double Dog::getHeight() const {
=======
string Dog::getHeight() {
>>>>>>> 7ea01a5... Changed type 'double's to 'string's in animal classes
  return this->height;
}

string Dog::getTailColour() const {
  return this->tailColour;
}
