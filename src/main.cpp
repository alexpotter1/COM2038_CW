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

  StorageManager storageManager;
  if (storageManager.addDogsToStorage(dogVectsPtr)) {
  }
	if (storageManager.addCatsToStorage(catVectsPtr)) {
	}
	if (storageManager.addHorsesToStorage(horseVectsPtr)) {
	}


  vector<Dog>::const_iterator it = storageManager.getDogs()->iter_begin;
  for (unsigned int i = 0; i < storageManager.getDogCount(); i++) {

		const Dog dog = dynamic_cast<const Dog&>(*it);

    it++;
  }

	Interface interface(storageManager);
	interface.printAll();
	interface.getInput();
}
