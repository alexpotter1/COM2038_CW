#include "CSVFileReader.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
// Dog, Animal: Derived, Base
template<class Derived, class Base>
vector<Base*> transformToBase(vector<Derived*> &derivedVec) {
  class vector<Base*> baseVec;
  typename vector<Derived*>::iterator iter;
  Base* base;

  for (iter = derivedVec.begin(); iter != derivedVec.end(); ++iter) {
    base = dynamic_cast<Base*>(*iter);
    if (base) {
      baseVec.push_back(base);
    }
  }

  return baseVec;
}

int main() {
	ifstream dogsFile("../csv/Dogs.csv");
	ifstream catsFile("../csv/Cats.csv");
	ifstream horsesFile("../csv/Horses.csv");
	CSVFileReader csvFileReader;
	vector<Dog*>* dogVectsPtr = csvFileReader.getDogs(&dogsFile);
	vector<Cat*>* catVectsPtr = csvFileReader.getCats(&catsFile);
	vector<Horse*>* horseVectsPtr = csvFileReader.getHorses(&horsesFile);
	for(unsigned int i = 0; i < dogVectsPtr-> size(); i++){
		Dog* dogPtr = dogVectsPtr->at(i);
		cout << dogPtr->getName() << endl;
	}
	cout << "" << endl;
	for(unsigned int i = 0; i < catVectsPtr-> size(); i++){
		Cat* catPtr = catVectsPtr->at(i);
		cout << catPtr->getName() << endl;
	}
	cout << "" << endl;
	for(unsigned int i = 0; i < horseVectsPtr-> size(); i++){
		Horse* horsePtr = horseVectsPtr->at(i);
		cout << horsePtr->getName() << endl;
	}

  vector<Animal*> animalVects1 = transformToBase<Dog, Animal>(*dogVectsPtr);
  vector<Animal*> animalVects2 = transformToBase<Cat, Animal>(*catVectsPtr);
  vector<Animal*> animalVects3 = transformToBase<Horse, Animal>(*horseVectsPtr);

  animalVects1.insert(animalVects1.end(), animalVects2.begin(), animalVects2.end());
  animalVects1.insert(animalVects1.end(), animalVects3.begin(), animalVects3.end());

  StorageManager storageManager;
  if (storageManager.addAnimalsToStorage(&animalVects1)) {
    cout << "loaded animals to storage" << endl;
  }

  cout << "Dogs: " << storageManager.getDogCount() << endl;
  cout << "Cats: " << storageManager.getCatCount() << endl;
  cout << "Horses: " << storageManager.getHorseCount() << endl;
}
