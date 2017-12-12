#include <iostream>
#include <fstream>
#include <sstream>
#include "CSVFileReader.h"

int main(){
	ifstream dogsFile("Dogs.csv");
	ifstream** files;
	files[0] = &dogsFile;
	CSVFileReader csvFileReader;
	csvFileReader.instantiateAnimals(files);
}
