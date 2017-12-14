#include "CSVFileReader.h"
#include <iostream>
#include <stdlib.h>
#include <stdexcept>

using namespace std;

CSVFileReader::CSVFileReader() {}

//For now make it only for Dog.
vector<Dog*>* CSVFileReader::getAnimalVectsFromFile(ifstream* filePtr){
	if(filePtr->is_open()){		
		cout << "For debbug: File is open" << endl;
		string line;
		vector<Dog*>* dogVectsPtr = new vector<Dog*>();
		while(getline(*filePtr, line)){
			cout << "For debbug: Another line" << endl;
			vector<string>* attributesPtr = getAttributes(&line);
			Dog *dogPtr = new Dog(attributesPtr->at(0),attributesPtr->at(1),attributesPtr->at(2),attributesPtr->at(6),attributesPtr->at(7),attributesPtr->at(3),attributesPtr->at(4),attributesPtr->at(5));
			dogVectsPtr->push_back(dogPtr);
			delete attributesPtr;
		}
		return dogVectsPtr;
	}
	else{
		runtime_error("Error reading file.");		
	}
}

//can't use sstream because when there is "husky,," at the end, it will ignore the last null attribute.
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
				for(int f = 0; f < linePtr->size(); f++){
				attributesPtr->at(attributesPtr->size()-1) += linePtr->at(f);
				}
				linePtr->erase(0, linePtr->size());
			}
		}
	}
	return attributesPtr;
}
