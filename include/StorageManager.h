#include <map>
#include <vector>
#include <iostream>
using namespace std;

class StorageManager {
private:
  map dogMap;
  map catMap;
  map horseMap;
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
