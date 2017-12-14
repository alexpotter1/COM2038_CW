#include "Interface.h"
#include <iostream>

string Interface::printAll() {
	//Some way of getting number of rows in each file
	//Some way of getting number of files (vector pointer
	storageManager.getNumberOfRows()

	cout << "There are " << storageManager.getNumerOfRows() << " " << storageManagerP -> breed

	for( int i = 0; i < numberOfFiles; i++ ) {
		for( int j = 0; j < numberOfRows; j++) {
			string name = storageManagerP -> object.name() -> Name
			string group = storageManagerP -> Group
			string breed = storageManagerP -> Breed 
			string colour = storageManagerP -> Colour
			string earType = storageManagerP -> EarType
			string height = storageManagerP -> Height
			string tailColour = storageManagerP -> TailColour
			string dad = storageManagerP -> Dad
			string mom = storageManagerP -> Mom

			cout << left;
			cout << setw(8) << name << "";
			cout << setw(8) << group << "";
			cout << setw(8) << breed << "";
			cout << setw(8) << colour << "";
			cout << setw(8) << height << "";
			cout << setw(8) << tailColour << "";
			cout << setw(8) << dad << "";
			cout << setw(8) << mom << "";
		}	
	}
//NEW CODE

	cout << "There are " << << " dog(s), " << << " cat(s) and " << " horse(s) in the inventory, which are:" << endl << endl;

	cout << 

	it = storageManager.getAnimals();
	
	for(auto it = storageManager.getAnimals[0]; it != storageManager.getAnimals[1]; ++it {

		string name = it->getName();
		string group = it->
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
