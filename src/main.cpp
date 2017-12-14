#include "../include/CSVFileReader.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
using namespace std;

int main() {
	ifstream dogsFile("../csv/Dogs.csv");
	CSVFileReader csvFileReader;
	
	csvFileReader.getAnimalVectsFromFile(&dogsFile);
}
