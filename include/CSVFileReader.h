#include <fstream>
#include <vector>
using namespace std;

class CSVFileReader {
public:
	CSVFileReader();
	void getAnimalVectsFromFile(ifstream* files);
private:
	vector<string>* getAttributes(string* linePtr);
};
