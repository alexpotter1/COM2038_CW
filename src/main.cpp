#include "../include/CSVFileReader.h"
#include "../include/Interface.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
// Dog, Animal: Derived, Base

int main() {
	ifstream dogsFile("csv/Dogs.csv");
	ifstream catsFile("csv/Cats.csv");
	ifstream horsesFile("csv/Horses.csv");
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

  vector<Animal*> animalVects1 = csvFileReader.transformToBase<Dog, Animal>(*dogVectsPtr);
  vector<Animal*> animalVects2 = csvFileReader.transformToBase<Cat, Animal>(*catVectsPtr);
  vector<Animal*> animalVects3 = csvFileReader.transformToBase<Horse, Animal>(*horseVectsPtr);

  animalVects1.insert(animalVects1.end(), animalVects2.begin(), animalVects2.end());
  animalVects1.insert(animalVects1.end(), animalVects3.begin(), animalVects3.end());

  StorageManager storageManager;
  if (storageManager.addAnimalsToStorage(&animalVects1)) {
    cout << "loaded animals to storage" << endl;
  }

  cout << "Dogs: " << storageManager.getDogCount() << endl;
  cout << "Cats: " << storageManager.getCatCount() << endl;
  cout << "Horses: " << storageManager.getHorseCount() << endl;

  auto it = storageManager.getDogs()->iter_begin;
  for (int i = 0; i < storageManager.getDogCount(); i++) {
    cout << "name: " << it->getName() << endl;
    it++;
  }

	Interface interface(storageManager);
	interface.printAll();

}
