#include "../include/StorageManager.h"
#include <typeinfo>
using namespace std;

StorageManager::StorageManager() {
  this->dogMap = map<string, Animal>();
  this->catMap = map<string, Animal>();
  this->horseMap = map<string, Animal>();
}

StorageManager::~StorageManager() {
}

bool StorageManager::addAnimalToStorage(Animal* animal) {
  string animalType = typeid(*animal).name();
  animalType.erase(0, 1);
  if (animalType == "Dog") {
    this->dogMap.insert({animal->getName(), *animal});
    return true;
  } else if (animalType == "Cat") {
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

  for(int i = 0; i < animals->size(); i++){
    if (!addAnimalToStorage(animals->at(i))) {
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

vector<Animal> StorageManager::getDogsAsVector() {

  vector<Animal> dogVector = *(new vector<Animal>());
  dogVector.reserve(this->getDogCount());

  for (map<string, Animal>::iterator it = this->dogMap.begin(); it != this->dogMap.end(); ++it) {
    Animal* animal = &(it->second);
    if (animal) {
      dogVector.push_back(*animal);
    }
  }

  return dogVector;
}

vector<Cat> StorageManager::getCatsAsVector() {
  vector<Cat> catVector = *(new vector<Cat>());

  for (map<string, Animal>::iterator it = this->catMap.begin(); it != this->catMap.end(); ++it) {
    Cat* second = dynamic_cast<Cat*>(&(it->second));
    catVector.push_back(*second);
  }

  return catVector;
}

vector<Horse> StorageManager::getHorsesAsVector() {
  vector<Horse> horseVector = *(new vector<Horse>());

  for (map<string, Animal>::iterator it = this->horseMap.begin(); it != this->horseMap.end(); ++it) {
    Horse* second = dynamic_cast<Horse*>(&(it->second));
    horseVector.push_back(*second);
  }

  return horseVector;
}

AnimalIterator<Animal>* StorageManager::getAnimals() {
  AnimalIterator<Animal>* animalIter = new AnimalIterator<Animal>;
  animalIter->iter_begin = this->getAnimalsAsVector().begin();
  animalIter->iter_end = this->getAnimalsAsVector().end();
  return animalIter;
}

AnimalIterator<Animal>* StorageManager::getDogs() {
  AnimalIterator<Animal>* animalIter = new AnimalIterator<Animal>;
  animalIter->iter_begin = this->getDogsAsVector().begin();
  animalIter->iter_end = this->getDogsAsVector().end();
  return animalIter;
}

AnimalIterator<Animal>* StorageManager::getCats() {
  AnimalIterator<Animal>* animalIter = new AnimalIterator<Animal>;
  animalIter->iter_begin = this->getCatsAsVector().begin();
  animalIter->iter_end = this->getCatsAsVector().end();
  return animalIter;
}

AnimalIterator<Animal>* StorageManager::getHorses() {
  AnimalIterator<Animal>* animalIter = new AnimalIterator<Animal>;
  animalIter->iter_begin = this->getHorsesAsVector().begin();
  animalIter->iter_end = this->getHorsesAsVector().end();
  return animalIter;
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
