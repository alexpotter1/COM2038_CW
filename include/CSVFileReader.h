#include <fstream>
#include <vector>
#include "StorageManager.h"
using namespace std;

//template<class Derived, class Base>
class CSVFileReader {
public:
	CSVFileReader();
	vector<Dog*>* getDogs(ifstream* files);
	vector<Cat*>* getCats(ifstream* files);
	vector<Horse*>* getHorses(ifstream* files);
	template<class Derived, class Base>
	vector<Base*> transformToBase(vector<Derived*> &derivedVec);
	

private:
	Dog* getDog(string* linePtr);
	Cat* getCat(string* linePtr);
	Horse* getHorse(string* linePtr);
	vector<string>* getAttributes(string* linePtr);
};

template<class Derived, class Base>
vector<Base*> CSVFileReader::transformToBase(vector<Derived*> &derivedVec) {
  class vector<Base*> baseVec;
  typename vector<Derived*>::iterator iter;
  Base* base;

  for (iter = derivedVec.begin(); iter != derivedVec.end(); ++iter) {
    base = dynamic_cast<Base*>(*iter);
    if (base) {
      baseVec.push_back(base);
    }
  }

  return baseVec;
}
