#include "../include/StorageManager.h"
#include <typeinfo>
using namespace std;

StorageManager::StorageManager() {
  this->dogMap = map<string, Dog>();
  this->catMap = map<string, Cat>();
  this->horseMap = map<string, Horse>();
}

bool StorageManager::addAnimalToStorage(const Animal& animal) {
  string animalType(typeid(animal).name()+1, typeid(animal).name().end());
  if (animalType == "Dog") {
    this->dogMap.insert({animal.getName(), animal});
    return true;
  } else if (animalType == "Cat") {
    this->catMap.insert({animal.getName(), animal});
    return true;
  } else if (animalType == "Horse") {
    this->horseMap.insert({animal.getName(), animal});
    return true;
  } else {
    return false;
  }
}
