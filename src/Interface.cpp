#include "../include/Interface.h"
#include <iostream>
#include <typeinfo>
#include <sstream>
#include <locale>

Interface::Interface(StorageManager& smanager) {
	this->storageManager = smanager;
}

string Interface::printAll() {

	cout << "There are " << this->storageManager.getDogCount() << " dog(s), " << this->storageManager.getCatCount()  << " cat(s) and " << this->storageManager.getHorseCount() << " horse(s) in the inventory, which are:" << endl << endl;

	string nameTitle = "Name";
	string groupTitle =  "Group";
	string breedTitle = "Breed";
	string colourTitle = "Colour";
	string earTitle = "Ear Type";
	string heightTitle = "Height";
	string tailTitle = "Tail Colour";
	string dadTitle = "Dad";
	string mumTitle = "Mom";

	cout << left;
	cout << setw(8) << nameTitle;
	cout << setw(8) << groupTitle;
	cout << setw(8) << breedTitle;
	cout << setw(8) << colourTitle;
	//cout << setw(8) << earTitle;
	//cout << setw(8) << heightTitle;
	//cout << setw(8) << tailTitle;
	cout << setw(8) << dadTitle;
	cout << setw(8) << mumTitle << endl;



	cout << "---------------------------------------------------------------------------------" << endl;

	auto it = this->storageManager.getDogs()->iter_begin;
	for(int i = 0; i < this->storageManager.getDogCount(); i++) {

		const Dog dog = dynamic_cast<const Dog&>(*it);

		string groupType =  typeid(dog).name();
		string name = dog.getName();
		string group = groupType.erase(0,1);
		string breed = dog.getBreed();
		string colour = dog.getColour();
		string earType = dog.getEarType();
		string height = dog.getHeight();
		string tailColour = dog.getTailColour();
		string dadName = dog.getDadName();
		string mumName = dog.getMumName();

		cout << left;
		cout << setw(8) << name;
		cout << setw(8) << group;
		cout << setw(8) << breed;
		cout << setw(8) << colour;
		cout << setw(8) << earType;
		cout << setw(8) << height;
		cout << setw(8) << tailColour;
		cout << setw(8) << dadName;
		cout << setw(8) << mumName << endl;

		it++;
	}

	cout << endl;

	auto it1 = this->storageManager.getCats()->iter_begin;
	for(int i = 0; i < this->storageManager.getCatCount(); i++) {

		string groupType =  typeid(*it1).name();
		string name = it1->getName();
		string group = groupType.erase(0,1);
		string breed = it1->getBreed();
		string colour = it1->getColour();
		//string earType = it->getEarType();
		//string height = it->getHeight();
		//string tailColour = it->getTailColour();
		string dadName = it1->getDadName();
		string mumName = it1->getMumName();

		cout << left;
		cout << setw(8) << name;
		cout << setw(8) << group;
		cout << setw(8) << breed;
		cout << setw(8) << colour;
		//cout << setw(8) << earType;
		//cout << setw(8) << height;
		//cout << setw(8) << tailColour;
		cout << setw(8) << dadName;
		cout << setw(8) << mumName << endl;

		it1++;
	}

	cout << endl;

	auto it2 = this->storageManager.getHorses()->iter_begin;
	for(int i = 0; i < this->storageManager.getHorseCount(); i++) {

		string groupType =  typeid(*it2).name();
		string name = it2->getName();
		string group = groupType.erase(0,1);
		string breed = it2->getBreed();
		string colour = it2->getColour();
		//string earType = it->getEarType();
		//string height = it->getHeight();
		//string tailColour = it->getTailColour();
		string dadName = it2->getDadName();
		string mumName = it2->getMumName();

		cout << left;
		cout << setw(8) << name;
		cout << setw(8) << group;
		cout << setw(8) << breed;
		cout << setw(8) << colour;
		//cout << setw(8) << earType;
		//cout << setw(8) << height;
		//cout << setw(8) << tailColour;
		cout << setw(8) << dadName;
		cout << setw(8) << mumName << endl;

		it2++;
	}

	cout << endl;

	return "";

}

/*string Interface::search() {
	//TODO Sends input string to storage manager, if returned null, no animal with the search. Otherwise print out
	//The paternal tree.

	//Take the input from the user and split into 2 strings returning 2 strings with no whitespace and lowercase

	string userInput;
	string userInputToLower;
	cout << "Enter the first letter of the animal group and the name of the specified one to find its paternal tree: ";
	cin >> userInput;

	locale loc;
	for(string::size_type i=0; i<userInput.length(); ++i) {
		userInputToLower = tolower(userInput[i], loc);
	}

	string userInputToLowerNoWhiteSpace = trim(userInputToLower);

	stringstream ss(userInputToLowerNoWhiteSpace);
	int i = 0;
	string item;
	string outputToSM[2];
	while (getline(ss, item, ' ')) {
		outputToSM[i] = item;
		i++;
	}

	this->storageManager.search(outputToSM[0], outputToSM[1]);

	return "";
}*/

void Interface::getInput() {
	string userInput;
	string userInputToLower;
	cout << "Enter the first letter of the animal group and the name of the specified one to find its paternal tree: ";
	cin >> userInput;

	locale loc;
	for(string::size_type i=0; i<userInput.length(); ++i) {
		userInputToLower = tolower(userInput[i], loc);
	}

	string userInputToLowerNoWhiteSpace = trim(userInputToLower);

	stringstream ss(userInputToLowerNoWhiteSpace);
	int i = 0;
	string item;
	string outputToSM[2];
	while (getline(ss, item, ' ')) {
		outputToSM[i] = item;
		i++;
	}

	cout << outputToSM[0];
	cout << outputToSM[1];
	//getPaternalTree(outputToSM[0], outputToSM[1]);

}

void Interface::getPaternalTree(string type, string name) {
	if(storageManager.search(type, name) != NULL) {
			paternalTree[counter] = storageManager.search(type, name)->getName();
			counter++;
			getPaternalTree(type, storageManager.search(type, name)->getDadName());
	} else if(counter == 0){
		counter = -1;
		cout << paternalTree[0] << " <-- [END]" << endl;
	} else if(counter == 1) {
		counter = -1;
		cout << paternalTree[0] << " <-- " << paternalTree[1] << " <-- [END]" << endl;
	} else if(counter == 2) {
		counter = -1;
		cout << paternalTree[0] << " <-- " << paternalTree[1] << " <-- " << paternalTree[2] << " <-- [END]" << endl;
	} else {
		if(type == "d") {
			cout << name << " was not found in the inventory within the \e[1mdogs\e[0m" << endl;
		} else if(type == "c") {
			cout << name << " was not found in the inventory within the \e[1mcats\e[0m" << endl;
		} else if(type == "h") {
			cout << name << " was not found in the inventory within the \e[1mhorses\e[0m" << endl;
		} else {
			cout << name << " was not found in the inventory within the selected inventory" << endl;
		}
	}

}

string Interface::ltrim(string s, const char* t) {
	return s.erase(0, s.find_first_not_of(t));
}

string Interface::rtrim(string s, const char* t) {
	return s.erase(s.find_last_not_of(t) + 1);
}

string Interface::trim(string s, const char* t) {
	return ltrim(rtrim(s, t), t);
}
