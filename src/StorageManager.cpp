#include "../include/StorageManager.h"
#include <typeinfo>
using namespace std;

StorageManager::StorageManager() {
  this->dogMap = map<string, Dog>();
  this->catMap = map<string, Cat>();
  this->horseMap = map<string, Horse>();
}

StorageManager::~StorageManager() {
}

bool StorageManager::addDogsToStorage(vector< Dog* >* dogs) {

  for(int i = 0; i < dogs->size(); i++){
    Dog* dog = dogs->at(i);
    this->dogMap.insert({dog->getName(), *dog});
  }

  return true;
}

bool StorageManager::addCatsToStorage(vector< Cat* >* cats) {

  for(int i = 0; i < cats->size(); i++){
    Cat* cat = cats->at(i);
    this->catMap.insert({cat->getName(), *cat});
  }

  return true;
}

bool StorageManager::addHorsesToStorage(vector< Horse* >* horses) {

  for(int i = 0; i < horses->size(); i++){
    Horse* horse = horses->at(i);
    this->horseMap.insert({horse->getName(), *horse});
  }

  return true;
}

vector<Dog> StorageManager::getDogsAsVector() {

  vector<Dog> dogVector = *(new vector<Dog>());
  dogVector.reserve(this->getDogCount());

  for (map<string, Dog>::iterator it = this->dogMap.begin(); it != this->dogMap.end(); ++it) {
      dogVector.push_back(it->second);
  }

  return dogVector;
}

vector<Cat> StorageManager::getCatsAsVector() {
  vector<Cat> catVector = *(new vector<Cat>());

  for (map<string, Cat>::iterator it = this->catMap.begin(); it != this->catMap.end(); ++it) {
    catVector.push_back(it->second);
  }

  return catVector;
}

vector<Horse> StorageManager::getHorsesAsVector() {
  vector<Horse> horseVector = *(new vector<Horse>());

  for (map<string, Horse>::iterator it = this->horseMap.begin(); it != this->horseMap.end(); ++it) {
    horseVector.push_back(it->second);
  }

  return horseVector;
}

AnimalIterator<Dog>* StorageManager::getDogs() {
  AnimalIterator<Dog>* animalIter = new AnimalIterator<Dog>;
  animalIter->iter_begin = this->getDogsAsVector().begin();
  animalIter->iter_end = this->getDogsAsVector().end();
  return animalIter;
}

AnimalIterator<Cat>* StorageManager::getCats() {
  AnimalIterator<Cat>* animalIter = new AnimalIterator<Cat>;
  animalIter->iter_begin = this->getCatsAsVector().begin();
  animalIter->iter_end = this->getCatsAsVector().end();
  return animalIter;
}

AnimalIterator<Horse>* StorageManager::getHorses() {
  AnimalIterator<Horse>* animalIter = new AnimalIterator<Horse>;
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
