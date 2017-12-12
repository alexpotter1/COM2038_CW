#include <iostream>
#include <fstream>
#include "CSVFileReader.h"

int main(){
	ifstream dogsFile("Dogs.csv");
	ifstream files[1];
	files[0] = dogsFile;
	CSVFileReader csvFileReader();
	csvFileReader.instantiateAnimals(dogsFile);
}
