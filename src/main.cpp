#include "../include/CSVFileReader.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream dogsFile("../csv/Dogs.csv");
	CSVFileReader csvFileReader;
	csvFileReader.getAnimalVectsFromFile(&dogsFile);

	/*
	string line = ",bella,,,44cm,brown,,";
	string* linePtr = &line;
	vector<string>* attributes = csvFileReader.getAttributes(linePtr);
	for(int i = 0; i < attributes->size(); i++){
		cout << "Attribute:" << attributes->at(i) << endl;
	}
	*/
}
