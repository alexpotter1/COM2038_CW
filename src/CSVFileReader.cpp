#include "CSVFileReader.h"
#include "Dog.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

CSVFileReader::CSVFileReader() {}

//For now make it only for Dog.
void CSVFileReader::getAnimalVectsFromFile(ifstream* filePtr){
	Dog *dogPtr = new Dog();
	//vector<Dog*> dogVectsPtr = ();
	if(filePtr->is_open()){		
		cout << "For debbug: File is open" << endl;
		//while(getline(infile, line)){
			
		//}
		
	}
}

//can't use sstream because when there is "husky,," at the end, it will ignore the last null attribute.
vector<string>* CSVFileReader::getAttributes(string* linePtr){
	int commaIndex;
	vector<string>* attributesPtr = (vector<string>*)malloc(sizeof(vector<string>));
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
			for(int f = 0; f < commaIndex; f++){
				attributesPtr->at(attributesPtr->size()-1) += linePtr->at(f);
			}
			linePtr->erase(0, commaIndex + 1);
		}
	}
	return attributesPtr;
}
