#include <fstream>
#include <vector>
#include "Dog.h"
using namespace std;

class CSVFileReader {
public:
	CSVFileReader();
	vector<Dog*>* getAnimalVectsFromFile(ifstream* files);
	vector<string>* getAttributes(string* linePtr);
};
