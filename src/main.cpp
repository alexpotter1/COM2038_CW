#include "../include/CSVFileReader.h"
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

	/*Need to test that Dog, Cat and Horse objects can be added to storage manager*/
/* Need to test this
  cout << "Dogs: " << sm.getDogCount() << endl;
  cout << "Cats: " << sm.getCatCount() << endl;
  cout << "Horses: " << sm.getHorseCount() << endl;
*/
}
