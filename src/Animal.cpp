#include "../include/Animal.h"
using namespace std;

Animal::Animal(string breed, string name, string colour, string dadName, string mumName) {
  this->breed = breed;
  this->name = name;
  this->colour = colour;
  this->dadName = dadName;
  this->mumName = mumName;
}

string Animal::getBreed() {
  return this->breed;
}

string Animal::getName() {
  return this->name;
}

string Animal::getColour() {
  return this->colour;
}

string Animal::getDadName() {
  return this->dadName;
}

string Animal::getMumName() {
  return this->mumName;
}
