#include <map>
#include <vector>
#include <iterator>
#include <iostream>
#include "Cat.h"
#include "Dog.h"
#include "Horse.h"
using namespace std;

template<class T>
struct AnimalIterator {
  typename vector<T>::const_iterator iter_begin;
  typename vector<T>::const_iterator iter_end;
};

class StorageManager {
private:
  map<string, Animal> dogMap;
  map<string, Animal> catMap;
  map<string, Animal> horseMap;
  vector<Animal> getAnimalsAsVector();
  vector<Animal> getDogsAsVector();
  vector<Cat> getCatsAsVector();
  vector<Horse> getHorsesAsVector();

public:
  StorageManager();
  ~StorageManager();
  bool addAnimalToStorage(Animal* animal);
  bool addAnimalsToStorage(vector< Animal* >* animals);
  vector<Animal>::const_iterator* getAnimals();
  AnimalIterator<Animal>* getDogs();
  vector<Cat>::const_iterator* getCats();
  vector<Horse>::const_iterator* getHorses();
  unsigned int getAnimalCount();
  unsigned int getDogCount();
  unsigned int getCatCount();
  unsigned int getHorseCount();
  Animal* search(string type, string name);
};
