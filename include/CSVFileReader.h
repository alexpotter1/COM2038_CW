#include <fstream>
#include <vector>
#include "Dog.h"
#include "Cat.h"
#include "Horse.h"
using namespace std;

class CSVFileReader {
public:
	CSVFileReader();
	vector<Dog*>* getDogs(ifstream* files);
	vector<Cat*>* getCats(ifstream* files);
	vector<Horse*>* getHorses(ifstream* files);
private:
	Dog* getDog(string* linePtr);
	Cat* getCat(string* linePtr);
	Horse* getHorse(string* linePtr);
	vector<string>* getAttributes(string* linePtr);
};
