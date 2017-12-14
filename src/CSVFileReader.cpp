#include "CSVFileReader.h"
#include "Dog.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

CSVFileReader::CSVFileReader() {}

//For now make it only for Dog.
void CSVFileReader::getAnimalVectsFromFile(ifstream* filePtr){
	//Dog *dogPtr = new Dog();
	if(filePtr->is_open()){		
		cout << "For debbug: File is open" << endl;
		string line;
		while(getline(*filePtr, line)){
			cout << "For debbug: Another line" << endl;
			vector<string>* attributesPtr = getAttributes(&line);
			
			cout << attributesPtr->at(0) << endl;
			cout << attributesPtr->at(1) << endl;
			cout << attributesPtr->at(2) << endl;
			cout << attributesPtr->at(3) << endl;
			cout << attributesPtr->at(4) << endl;
			cout << attributesPtr->at(5) << endl;
			cout << attributesPtr->at(6) << endl;
			cout << attributesPtr->at(7) << endl;
			
			//Dog *dogPtr = new Dog(attributesPtr->at(0), attributesPtr->at(1), );
			Dog *dogPtr = new Dog("breed", "name", "colour", "dad name", "mum name", "ear type", "height", "tail colour");
			cout << dogPtr->getEarType();
			delete attributesPtr;
		}
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
