#include "CSVFileReader.h"
#include <iostream>

using namespace std;

CSVFileReader::CSVFileReader() {}

void CSVFileReader::instantiateAnimals(ifstream** files){
	for(int i = 0; i < sizeof(files); i++){
		cout << "Hello" << endl;
	}
}
