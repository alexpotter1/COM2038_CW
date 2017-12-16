#include "CSVFileReader.h"
#include <stdexcept>

using namespace std;

/*Constructor for the class which is used to read files to store the information into objects. 
The objects are then saved in memory. The class provides methods to retrieve vectors of 
pointers to these objects.*/
CSVFileReader::CSVFileReader() {}

/*Reads a file which is pointed to by a pointer. Then the function creates a pointer to the 
vector which stores pointers to Dog objects. The Dog objects have been created using attributes 
which have been read from the file. The function returns the pointer to the vector of pointers to 
Dog objects.*/
vector<Dog*>* CSVFileReader::getDogs(ifstream* filePtr){
	vector<Dog*>* dogVectsPtr = new vector<Dog*>();
	if(filePtr->is_open()){
		string line;
		while(getline(*filePtr, line)){
			Dog *dogPtr = getDog(&line);
			dogVectsPtr->push_back(dogPtr);
		}
	}
	else{
		throw runtime_error("Error reading file.");
	}
	return dogVectsPtr;
}

/*Reads a file which is pointed to by a pointer. Then the function creates a pointer to the 
vector which stores pointers to Cat objects. The Cat objects have been created using attributes 
which have been read from the file. The function returns the pointer to the vector of pointers to 
Cat objects.*/
vector<Cat*>* CSVFileReader::getCats(ifstream* filePtr){
	vector<Cat*>* catVectsPtr = new vector<Cat*>();
	if(filePtr->is_open()){
		string line;
		while(getline(*filePtr, line)){
			Cat *catPtr = getCat(&line);
			catVectsPtr->push_back(catPtr);
		}
	}
	else{
		throw runtime_error("Error reading file.");
	}
	return catVectsPtr;
}

/*Reads a file which is pointed to by a pointer. Then the function creates a pointer to the 
vector which stores pointers to Horse objects. The Horse objects have been created using attributes 
which have been read from the file. The function returns the pointer to the vector of pointers to 
Horse objects.*/
vector<Horse*>* CSVFileReader::getHorses(ifstream* filePtr){
	vector<Horse*>* horseVectsPtr = new vector<Horse*>();
	if(filePtr->is_open()){
		string line;
		while(getline(*filePtr, line)){
			Horse *horsePtr = getHorse(&line);
			horseVectsPtr->push_back(horsePtr);
		}
	}
	else{
		throw runtime_error("Error reading file.");
	}
	return horseVectsPtr;
}

/*Reads a string pointed to by a pointer. Calls getAttributes function on a string pointer to
tokenise the sting into attributes. Then the function populates the Dog object attributes 
using the attributes from the string. Then the function returns the pointer to the Dog
object.*/
Dog* CSVFileReader::getDog(string* linePtr){
	vector<string>* attributesPtr = getAttributes(linePtr);
	Dog *dogPtr = new Dog(attributesPtr->at(0),attributesPtr->at(1),attributesPtr->at(2),attributesPtr->at(6),attributesPtr->at(7),attributesPtr->at(3),attributesPtr->at(4),attributesPtr->at(5));
	delete attributesPtr;
	return dogPtr;
}

/*Reads a string pointed to by a pointer. Calls getAttributes function on a string pointer to
tokenise the sting into attributes. Then the function populates the Cat object attributes 
using the attributes from the string. Then the function returns the pointer to the Cat
object.*/
Cat* CSVFileReader::getCat(string* linePtr){
	vector<string>* attributesPtr = getAttributes(linePtr);
	Cat *catPtr = new Cat(attributesPtr->at(0),attributesPtr->at(1),attributesPtr->at(2),attributesPtr->at(6),attributesPtr->at(7),attributesPtr->at(3),attributesPtr->at(4),attributesPtr->at(5));
	delete attributesPtr;
	return catPtr;
}

/*Reads a string pointed to by a pointer. Calls getAttributes function on a string pointer to
tokenise the sting into attributes. The function populates the Horse object attributes 
using the attributes from the string. Then the function returns the pointer to the Horse
object.*/
Horse* CSVFileReader::getHorse(string* linePtr){
	vector<string>* attributesPtr = getAttributes(linePtr);
	Horse *horsePtr = new Horse(attributesPtr->at(0),attributesPtr->at(1),attributesPtr->at(2),attributesPtr->at(6),attributesPtr->at(7),attributesPtr->at(3),attributesPtr->at(4),attributesPtr->at(5));
	delete attributesPtr;
	return horsePtr;
}

/*Reads a string pointed to by a pointer. The function splits the line by a comma delimeter 
into sub-strings and returns the sub-strings.*/
vector<string>* CSVFileReader::getAttributes(string* linePtr){
	int commaIndex;
	vector<string>* attributesPtr = new vector<string>();
	while(*linePtr != "\0"){
		commaIndex = linePtr->find(",");
		if(*linePtr == ","){
			attributesPtr->push_back("");
			attributesPtr->push_back("");
			linePtr->erase(0,1);
		}
		else if(commaIndex == 0){
			attributesPtr->push_back("");
			linePtr->erase(0,1);
		}

		else{
			attributesPtr->push_back("");
			if(commaIndex > -1){
				for(int f = 0; f < commaIndex; f++){
				attributesPtr->at(attributesPtr->size()-1) += linePtr->at(f);
				}
				linePtr->erase(0, commaIndex + 1);
			}
			else{
				for(unsigned f = 0; f < linePtr->size(); f++){
				attributesPtr->at(attributesPtr->size()-1) += linePtr->at(f);
				}
				linePtr->erase(0, linePtr->size());
			}
		}
	}
	return attributesPtr;
}
