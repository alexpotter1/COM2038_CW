#include "../include/StorageManager.h"
#include <typeinfo>
using namespace std;

StorageManager::StorageManager() {
  this->dogMap = map<string, Dog>();
  this->catMap = map<string, Cat>();
  this->horseMap = map<string, Horse>();
}

bool StorageManager::addAnimalToStorage(const Animal& animal) {
  cout << typeid(animal).name() << endl;
  return true;
}
