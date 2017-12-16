#include "../include/Interface.h"
#include <iostream>
#include <typeinfo>
#include <sstream>
#include <locale>
#include <algorithm>

Interface::Interface(StorageManager& smanager) {
	this->storageManager = smanager;
	counter = 0;
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
	cout << setw(11) << nameTitle;
	cout << setw(11) << groupTitle;
	cout << setw(11) << breedTitle;
	cout << setw(11) << colourTitle;
	cout << setw(11) << earTitle;
	cout << setw(11) << heightTitle;
	cout << setw(14) << tailTitle;
	cout << setw(11) << dadTitle;
	cout << setw(11) << mumTitle << endl;



	cout << "----------------------------------------------------------------------------------------------" << endl;

	auto it = this->storageManager.getDogs()->iter_begin;
	for(int i = 0; i < this->storageManager.getDogCount(); i++) {

		const Dog dog = dynamic_cast<const Dog&>(*it);

		string groupType = typeid(dog).name();
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
		cout << setw(11) << name;
		cout << setw(11) << group;
		cout << setw(11) << breed;
		cout << setw(11) << colour;
		cout << setw(11) << earType;
		cout << setw(11) << height;
		cout << setw(14) << tailColour;
		cout << setw(11) << dadName;
		cout << setw(11) << mumName << endl;

		it++;
	}

	cout << endl;

	auto it1 = this->storageManager.getCats()->iter_begin;
	for(int i = 0; i < this->storageManager.getCatCount(); i++) {

		const Cat cat = dynamic_cast<const Cat&>(*it1);

		string groupType = typeid(cat).name();
		string name = cat.getName();
		string group = groupType.erase(0,1);
		string breed = cat.getBreed();
		string colour = cat.getColour();
		string earType = cat.getEarType();
		string height = cat.getHeight();
		string tailColour = cat.getTailColour();
		string dadName = cat.getDadName();
		string mumName = cat.getMumName();

		cout << left;
		cout << setw(11) << name;
		cout << setw(11) << group;
		cout << setw(11) << breed;
		cout << setw(11) << colour;
		cout << setw(11) << earType;
		cout << setw(11) << height;
		cout << setw(14) << tailColour;
		cout << setw(11) << dadName;
		cout << setw(11) << mumName << endl;

		it1++;
	}

	cout << endl;

	auto it2 = this->storageManager.getHorses()->iter_begin;
	for(int i = 0; i < this->storageManager.getHorseCount(); i++) {

		const Horse horse = dynamic_cast<const Horse&>(*it2);

		string groupType = typeid(horse).name();
		string name = horse.getName();
		string group = groupType.erase(0,1);
		string breed = horse.getBreed();
		string colour = horse.getColour();
		string earType = horse.getEarType();
		string height = horse.getHeight();
		string tailColour = horse.getTailColour();
		string dadName = horse.getDadName();
		string mumName = horse.getMumName();

		cout << left;
		cout << setw(11) << name;
		cout << setw(11) << group;
		cout << setw(11) << breed;
		cout << setw(11) << colour;
		cout << setw(11) << earType;
		cout << setw(11) << height;
		cout << setw(14) << tailColour;
		cout << setw(11) << dadName;
		cout << setw(11) << mumName << endl;

		it2++;
	}

	cout << endl;

	return "";

}

void Interface::getInput() {
	string userInput;
	string userInputToLower;
	cout << "Enter the first letter of the animal group and the name of the specified one to find its paternal tree: ";

	getline(cin, userInput);

	transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

	string userInputToLowerNoWhiteSpace = trim(userInput);

	stringstream ss(userInputToLowerNoWhiteSpace);
	int i = 0;
	string item;
	string outputToSM[2];
	while (getline(ss, item, ' ')) {
		outputToSM[i] = item;
		i++;
	}

	getPaternalTree(outputToSM[0], outputToSM[1]);

}

void Interface::getPaternalTree(string type, string name) {

	Animal* result = storageManager.search(type, name);

	if(result != NULL) {

			if(type == "a" && counter == 0) {
			string groupType = typeid(*result).name();
			string group = groupType.erase(0,1);
			cout << name << " is found in the " << group << " inventory." << endl;

			}
			paternalTree[counter] = result->getName();
			counter++;
			getPaternalTree(type, result->getDadName());
	} else if(counter == 1){
		counter = 0;
		cout << "Paternal tree of " << paternalTree[0] << ":" << endl;
		cout << paternalTree[0] << " <-- [END]" << endl;
	} else if(counter == 2) {
		counter = 0;
		cout << "Paternal tree of " << paternalTree[0] << ":" << endl;
		cout << paternalTree[0] << " <-- " << paternalTree[1] << " <-- [END]" << endl;
	} else if(counter == 3) {
		counter = 0;
		cout << "Paternal tree of " << paternalTree[0] << ":" << endl;
		cout << paternalTree[0] << " <-- " << paternalTree[1] << " <-- " << paternalTree[2] << " <-- [END]" << endl;
	} else {
		if(type == "d") {
			cout << name << " was not found in the inventory within the \e[1mdogs\e[0m!" << endl;
		} else if(type == "c") {
			cout << name << " was not found in the inventory within the \e[1mcats\e[0m!" << endl;
		} else if(type == "h") {
			cout << name << " was not found in the inventory within the \e[1mhorses\e[0m!" << endl;
		} else {
			cout << name << " was not found in any inventory!" << endl;
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
