#include "../include/Animal.h"
using namespace std;

Animal::Animal(string breed, string name, string colour, string dadName, string mumName) {
  this->breed = breed;
  this->name = name;
  this->colour = colour;
  this->dadName = dadName;
  this->mumName = mumName;
}

string Animal::getBreed() const {
  return this->breed;
}

string Animal::getName() const {
  return this->name;
}

string Animal::getColour() const {
  return this->colour;
}

string Animal::getDadName() const {
  return this->dadName;
}

string Animal::getMumName() const {
  return this->mumName;
}
