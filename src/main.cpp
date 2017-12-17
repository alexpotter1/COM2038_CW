#include "../include/CSVFileReader.h"
#include "../include/Interface.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	// Create streams that will be used by csvFileReader
	ifstream dogsFile("csv/Dogs.csv");
	ifstream catsFile("csv/Cats.csv");
	ifstream horsesFile("csv/Horses.csv");
	CSVFileReader csvFileReader;

	// Output from csvFileReader. All of the animals are now stored.
	vector<Dog*>* dogVectsPtr = csvFileReader.getDogs(&dogsFile);
	vector<Cat*>* catVectsPtr = csvFileReader.getCats(&catsFile);
	vector<Horse*>* horseVectsPtr = csvFileReader.getHorses(&horsesFile);

  StorageManager storageManager;
	//If adding dogs to storageManager fails, print an error.
  if (!storageManager.addDogsToStorage(dogVectsPtr)) {
		cout << "Failed to add dogs to storage." << endl;
  }
	//If adding cats to storageManager fails, print an error.
	if (!storageManager.addCatsToStorage(catVectsPtr)) {
		cout << "Failed to add cats to storage." << endl;
	}
	//If adding horses to storageManager fails, print an error.
	if (!storageManager.addHorsesToStorage(horseVectsPtr)) {
		cout << "Failed to add horses to storage." << endl;
	}

	Interface interface(storageManager);
	// Call the interface printAll() method to output information about all animals in the collection.
	interface.printAll();
	// Call the interface getInput() method to prompt the user for an input and search for the paternal tree.
	interface.getInput();

	return 0;
}
