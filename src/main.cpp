#include "../include/CSVFileReader.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
using namespace std;

int main() {
	ifstream dogsFile("../csv/Dogs.csv");
	CSVFileReader csvFileReader;
	vector<Dog*>* dogVectsPtr = csvFileReader.getAnimalVectsFromFile(&dogsFile);
	for(int i = 0; i < dogVectsPtr-> size(); i++){
		Dog* dogPtr = dogVectsPtr->at(i);
		cout << dogPtr->getName() << endl;
	}
}
