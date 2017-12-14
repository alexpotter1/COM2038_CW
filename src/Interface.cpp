#include "Interface.h"
#include <iostream>
#include <typeinfo>

string Interface::printAll() {

	cout << "There are " << << " dog(s), " << << " cat(s) and " << " horse(s) in the inventory, which are:" << endl << endl;

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

	cout << "---------------------------------------------------------------------------------" << end;

	it = storageManager.getAnimals();
	
	for(auto it = storageManager.getAnimals[0]; it != storageManager.getAnimals[1]; ++it {

		string groupType =  typeid(it).name();
		string name = it->getName();
		string group = groupType.erase(0,1);
		string breed = it->getBreed();
		string colour = it->getColour();
		string earType = it->getEarType();
		double height = it->getHeight();
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
	}

}

string Interface::search() {
	//TODO Sends input string to storage manager, if returned null, no animal with the search. Otherwise print out
	//The paternal tree.

	//Take the input from the user and split into 2 strings returning 2 strings with no whitespace and lowercase
}
