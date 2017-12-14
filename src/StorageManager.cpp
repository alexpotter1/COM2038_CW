#include "../include/StorageManager.h"
#include <typeinfo>
using namespace std;

StorageManager::StorageManager() {
  this->dogMap = map<string, Animal>();
  this->catMap = map<string, Animal>();
  this->horseMap = map<string, Animal>();
}

bool StorageManager::addAnimalToStorage(Animal* animal) {
  string animalType = typeid(*animal).name();
  animalType.erase(0, 1);
  if (animalType == "Dog") {
    this->dogMap.insert({animal->getName(), *animal});
    return true;
  } else if (animalType == "Horse") {
    this->catMap.insert({animal->getName(), *animal});
    return true;
  } else if (animalType == "Horse") {
    this->horseMap.insert({animal->getName(), *animal});
    return true;
  } else {
    return false;
  }
}

bool StorageManager::addAnimalsToStorage(vector< Animal* >* animals) {
  vector<Animal*>* animalVec = animals;

  for(int i = 0; i < animalVec->size(); i++){
    if (!addAnimalToStorage(animalVec->at(i))) {
      return false;
    }
  }

  return true;
}

vector<Animal> StorageManager::getAnimalsAsVector() {
  vector<Animal> animalVector;
  for (map<string, Animal>::iterator it = this->dogMap.begin(); it != this->dogMap.end(); ++it) {
    animalVector.push_back(it->second);
  }
  for (map<string, Animal>::iterator it = this->horseMap.begin(); it != this->horseMap.end(); ++it) {
    animalVector.push_back(it->second);
  }
  for (map<string, Animal>::iterator it = this->horseMap.begin(); it != this->horseMap.end(); ++it) {
    animalVector.push_back(it->second);
  }

  return animalVector;
}

vector<Dog> StorageManager::getDogsAsVector() {
  vector<Dog> dogVector;
  for (map<string, Animal>::iterator it = this->dogMap.begin(); it != this->dogMap.end(); ++it) {
    Dog* second = dynamic_cast<Dog*>(&(it->second));
    dogVector.push_back(*second);
  }

  return dogVector;
}

vector<Cat> StorageManager::getCatsAsVector() {
  vector<Cat> catVector;
  for (map<string, Animal>::iterator it = this->catMap.begin(); it != this->catMap.end(); ++it) {
    Cat* second = dynamic_cast<Cat*>(&(it->second));
    catVector.push_back(*second);
  }

  return catVector;
}

vector<Horse> StorageManager::getHorsesAsVector() {
  vector<Horse> horseVector;
  for (map<string, Animal>::iterator it = this->horseMap.begin(); it != this->horseMap.end(); ++it) {
    Horse* second = dynamic_cast<Horse*>(&(it->second));
    horseVector.push_back(*second);
  }

  return horseVector;
}

vector<Animal>::const_iterator* StorageManager::getAnimals() {
  vector<Animal>::const_iterator* beginEndIterators = new vector<Animal>::const_iterator[2];
  vector<Animal> animals = this->getAnimalsAsVector();
  beginEndIterators[0] = animals.begin();
  beginEndIterators[1] = animals.end();

  return beginEndIterators;
}

vector<Dog>::const_iterator* StorageManager::getDogs() {
  vector<Dog>::const_iterator* beginEndIterators = new vector<Dog>::const_iterator[2];
  vector<Dog> dogs = this->getDogsAsVector();
  beginEndIterators[0] = dogs.begin();
  beginEndIterators[1] = dogs.end();

  return beginEndIterators;
}

vector<Cat>::const_iterator* StorageManager::getCats() {
  vector<Cat>::const_iterator* beginEndIterators = new vector<Cat>::const_iterator[2];
  vector<Cat> cats = this->getCatsAsVector();
  beginEndIterators[0] = cats.begin();
  beginEndIterators[1] = cats.end();

  return beginEndIterators;
}

vector<Horse>::const_iterator* StorageManager::getHorses() {
  vector<Horse>::const_iterator* beginEndIterators = new vector<Horse>::const_iterator[2];
  vector<Horse> horses = this->getHorsesAsVector();
  beginEndIterators[0] = horses.begin();
  beginEndIterators[1] = horses.end();

  return beginEndIterators;
}

unsigned int StorageManager::getAnimalCount() {
  return (unsigned int) (this->dogMap.size() + this->catMap.size() + this->horseMap.size());
}

unsigned int StorageManager::getDogCount() {
  return (unsigned int) this->dogMap.size();
}

unsigned int StorageManager::getCatCount() {
  return (unsigned int) this->catMap.size();
}

unsigned int StorageManager::getHorseCount() {
  return (unsigned int) this->horseMap.size();
}

Animal* StorageManager::search(string type, string name) {
  if (type == "d" || type == "a") {
    if (this->dogMap.count(name)) {
      return &(this->dogMap.find(name)->second);
    }
  }

  if (type == "c" || type == "a") {
    if (this->catMap.count(name)) {
      return &(this->catMap.find(name)->second);
    }
  }

  if (type == "h" || type == "a") {
    if (this->horseMap.count(name)) {
      return &(this->horseMap.find(name)->second);
    }
  }

  // If not correct type, or if name doesn't exist, return null
  // If using this function in another class, be careful to avoid null pointer dereferencing
  return NULL;
}
