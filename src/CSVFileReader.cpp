#include "CSVFileReader.h"
#include <stdexcept>

using namespace std;

CSVFileReader::CSVFileReader() {}

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
		runtime_error("Error reading file.");		
	}
	return dogVectsPtr;
}

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
		runtime_error("Error reading file.");		
	}
	return catVectsPtr;
}

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
		runtime_error("Error reading file.");		
	}
	return horseVectsPtr;
}

Dog* CSVFileReader::getDog(string* linePtr){
	vector<string>* attributesPtr = getAttributes(linePtr);
	Dog *dogPtr = new Dog(attributesPtr->at(0),attributesPtr->at(1),attributesPtr->at(2),attributesPtr->at(6),attributesPtr->at(7),attributesPtr->at(3),attributesPtr->at(4),attributesPtr->at(5));
	delete attributesPtr;
	return dogPtr;
}

Cat* CSVFileReader::getCat(string* linePtr){
	vector<string>* attributesPtr = getAttributes(linePtr);
	Cat *catPtr = new Cat(attributesPtr->at(0),attributesPtr->at(1),attributesPtr->at(2),attributesPtr->at(6),attributesPtr->at(7),attributesPtr->at(3),attributesPtr->at(4),attributesPtr->at(5));
	delete attributesPtr;
	return catPtr;
}

Horse* CSVFileReader::getHorse(string* linePtr){
	vector<string>* attributesPtr = getAttributes(linePtr);
	Horse *horsePtr = new Horse(attributesPtr->at(0),attributesPtr->at(1),attributesPtr->at(2),attributesPtr->at(6),attributesPtr->at(7),attributesPtr->at(3),attributesPtr->at(4),attributesPtr->at(5));
	delete attributesPtr;
	return horsePtr;
}

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
