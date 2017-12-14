#include "../include/Horse.h"
using namespace std;

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

<<<<<<< HEAD
double Horse::getHeight() const {
=======
string Horse::getHeight() {
>>>>>>> 7ea01a5... Changed type 'double's to 'string's in animal classes
  return this->height;
}

string Horse::getTailColour() const {
  return this->tailColour;
}
