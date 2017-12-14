#include <map>
#include <vector>
#include <iterator>
#include <iostream>
#include "Cat.h"
#include "Dog.h"
#include "Horse.h"
using namespace std;

class StorageManager {
private:
  map<string, Animal> dogMap;
  map<string, Animal> catMap;
  map<string, Animal> horseMap;
  vector<Animal> getAnimalsAsVector();
  vector<Dog> getDogsAsVector();
  vector<Cat> getCatsAsVector();
  vector<Horse> getHorsesAsVector();
public:
  StorageManager();
  ~StorageManager() {};
  bool addAnimalToStorage(Animal animal);
  vector<Animal>::const_iterator* getAnimals();
  vector<Dog>::const_iterator* getDogs();
  vector<Cat>::const_iterator* getCats();
  vector<Horse>::const_iterator* getHorses();
  unsigned int getAnimalCount();
  unsigned int getDogCount();
  unsigned int getCatCount();
  unsigned int getHorseCount();
};
