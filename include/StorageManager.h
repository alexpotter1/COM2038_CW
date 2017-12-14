#include <map>
#include <vector>
#include <iostream>
#include "Cat.h"
#include "Dog.h"
#include "Horse.h"
using namespace std;

class StorageManager {
private:
  map<string, Dog> dogMap;
  map<string, Cat> catMap;
  map<string, Horse> horseMap;
  vector<Animal> getAnimalsAsVector();
  vector<Dog> getDogsAsVector();
  vector<Cat> getCatsAsVector();
  vector<Horse> getHorsesAsVector();
public:
  StorageManager();
  ~StorageManager();
  bool addAnimalToStorage(const Animal& animal);
  vector<Animal>::iterator getAnimals();
  vector<Dog>::iterator getDogs();
  vector<Cat>::iterator getCats();
  vector<Horse>::iterator getHorses();
};
