#pragma once
#include <map>
#include <vector>
#include <iterator>
#include <iostream>
#include "Cat.h"
#include "Dog.h"
#include "Horse.h"
using namespace std;

/* Nicer wrapper around the iterator begin and end pointers */
template<class T>
struct AnimalIterator {
  typename vector<T>::const_iterator iter_begin;
  typename vector<T>::const_iterator iter_end;
};

class StorageManager {
private:
  map<string, Dog> dogMap;
  map<string, Cat> catMap;
  map<string, Horse> horseMap;

  /* These functions will only need to be called by StorageManager internally,
     as no other class should be aware of the specifics of the internal structures of this class. */
  vector<Dog> getDogsAsVector();
  vector<Cat> getCatsAsVector();
  vector<Horse> getHorsesAsVector();

public:
  StorageManager();
  ~StorageManager();
  bool addDogsToStorage(vector<Dog*>* dogs);
  bool addCatsToStorage(vector<Cat*>* cats);
  bool addHorsesToStorage(vector<Horse*>* horses);
  AnimalIterator<Dog>* getDogs();
  AnimalIterator<Cat>* getCats();
  AnimalIterator<Horse>* getHorses();
  unsigned int getAnimalCount();
  unsigned int getDogCount();
  unsigned int getCatCount();
  unsigned int getHorseCount();
  Animal* search(string type, string name);
};
