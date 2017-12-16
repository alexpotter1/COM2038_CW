#include "../include/Interface.h"
#include <iostream>
#include <typeinfo>
#include <sstream>
#include <locale>

Interface::Interface() {
	this->storageManager = StorageManager();
}

string Interface::printAll() {

	cout << "There are " << this->storageManager.getDogCount() << " dog(s), " << this->storageManager.getCatCount()  << " cat(s) and " << this->storageManager.getHorseCount() << " horse(s) in the inventory, which are:" << endl << endl;

	cout << left;
	cout << setw(8) << "\e[4mName\e[0m";
	cout << setw(8) << "\e[4mGroup\e[0m";
	cout << setw(8) << "\e[4mBreed\e[0m";
	cout << setw(8) << "\e[4mColour\e[0m";
	cout << setw(8) << "\e[4mEar Type\e[0m";
	cout << setw(8) << "\e[4mHeight\e[0m";
	cout << setw(8) << "\e[4mTail Colour\e[0m";
	cout << setw(8) << "\e[4mDad\e[0m";
	cout << setw(8) << "\e[4mMom\e[0m" << endl;

	cout << "---------------------------------------------------------------------------------" << endl;

	auto it = this->storageManager.getAnimals()->iter_begin;
	for(int i = 0; i < this->storageManager.getAnimalCount(); i++) {

		string groupType =  typeid(it).name();
		string name = it->getName();
		string group = groupType.erase(0,1);
		string breed = it->getBreed();
		string colour = it->getColour();
		string earType = it->getEarType();
		string height = it->getHeight();
		string tailColour = it->getTailColour();
		string dadName = it->getDadName();
		string mumName = it->getMumName();

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

	return "";

}

string Interface::search() {
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
