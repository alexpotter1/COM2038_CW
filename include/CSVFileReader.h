#include <fstream>
#include <vector>
#include "StorageManager.h"
using namespace std;

/*Constructor for the class which is used to read files to store the information into objects. 
The objects are then saved in memory. The class provides methods to retrieve vectors of 
pointers to these objects.*/
class CSVFileReader {
public:
	/*Constructor for the CSVFileReader class.*/
	CSVFileReader();
	/*Reads a file which is pointed to by a pointer. Then the function creates a pointer to the 
	vector which stores pointers to Dog objects. The Dog objects have been created using attributes 
	which have been read from the file. The function returns the pointer to the vector of pointers to 
	Dog objects.*/
	vector<Dog*>* getDogs(ifstream* files);
	/*Reads a file which is pointed to by a pointer. Then the function creates a pointer to the 
	vector which stores pointers to Cat objects. The Cat objects have been created using attributes 
	which have been read from the file. The function returns the pointer to the vector of pointers to 
	Cat objects.*/
	vector<Cat*>* getCats(ifstream* files);
	/*Reads a file which is pointed to by a pointer. Then the function creates a pointer to the 
	vector which stores pointers to Horse objects. The Horse objects have been created using attributes 
	which have been read from the file. The function returns the pointer to the vector of pointers to 
	Horse objects.*/
	vector<Horse*>* getHorses(ifstream* files);
	/*Template function which is used to dynamically cast an instance of a class derived from the 
	Animal class to an intance of the Animal class.*/
	template<class Derived, class Base>
	vector<Base*> transformToBase(vector<Derived*> &derivedVec);
	

private:
	/*Reads a string pointed to by a pointer. Calls getAttributes function on a string pointer to
	tokenise the sting into attributes. Then the function populates the Dog object attributes 
	using the attributes from the string. Then the function returns the pointer to the Dog
	object.*/
	Dog* getDog(string* linePtr);
	/*Reads a string pointed to by a pointer. Calls getAttributes function on a string pointer to
	tokenise the sting into attributes. Then the function populates the Cat object attributes 
	using the attributes from the string. Then the function returns the pointer to the Cat
	object.*/
	Cat* getCat(string* linePtr);
	/*Reads a string pointed to by a pointer. Calls getAttributes function on a string pointer to
	tokenise the sting into attributes. The function populates the Horse object attributes 
	using the attributes from the string. Then the function returns the pointer to the Horse
	object.*/
	Horse* getHorse(string* linePtr);
	
	vector<string>* getAttributes(string* linePtr);
};

/*Definition of the transformToBase function.*/
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
