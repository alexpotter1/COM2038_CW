#include "../include/Interface.h"
#include <iostream>
#include <typeinfo>
#include <sstream>
#include <locale>
#include <algorithm>

/* Paramaterised constructor which takes a parameter of a StorageManager reference.
Initializes a storageManager object and counter to 0, upon construction of an interface object. */
Interface::Interface(StorageManager& smanager) {
	this->storageManager = smanager;
	counter = 0;
}

/* Prints the entire contents of each of the animal type inventories, displaying them to the terminal in a
formatted output with fixed width and left alignment. */
void Interface::printAll() {

	// Dynamically assign the number of animals in each of the animal inventories, by getting the number of animals in each inventory.
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



	cout << "--------------------------------------------------------------------------------------------------" << endl;

	// Gets an const iterator object pointer which points to the start of the dog vector data structure.
	auto it = this->storageManager.getDogs()->iter_begin;

	// Loops through the iterator and returns dog objects
	for(unsigned int i = 0; i < this->storageManager.getDogCount(); i++) {

		// Ensure that the animals are casted to subtypes rather than supertypes.
		const Dog dog = dynamic_cast<const Dog&>(*it);

		string groupType = typeid(dog).name();
		string name = dog.getName();
		string group = groupType.erase(0,1);
		string breed = dog.getBreed();
		string colour = dog.getColour();
		string earType = dog.getEarType();
		string height = dog.getHeight();
		string tailColour = dog.getTailColour();
		string dadName;
		// Set dadName to dogs dad name otherwise set to N/A if no dad name.
		if(dog.getDadName().empty()) {
			dadName = "N/A";
		} else {
			dadName = dog.getDadName();
		}
		string mumName;
		// Set mumName to dogs mums name otherwise set to N/A if no mum name.
		if(dog.getMumName().empty()) {
			mumName = "N/A";
		} else {
			mumName = dog.getMumName();
		}

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

	// Gets an const iterator object pointer which points to the start of the cat vector data structure.
	auto it1 = this->storageManager.getCats()->iter_begin;

	// Loops through the iterator and returns cat objects
	for(unsigned int i = 0; i < this->storageManager.getCatCount(); i++) {

		// Ensure that the animals are casted to subtypes rather than supertypes.
		const Cat cat = dynamic_cast<const Cat&>(*it1);

		string groupType = typeid(cat).name();
		string name = cat.getName();
		string group = groupType.erase(0,1);
		string breed = cat.getBreed();
		string colour = cat.getColour();
		string earType = cat.getEarType();
		string height = cat.getHeight();
		string tailColour = cat.getTailColour();
		string dadName;
		// Set dadName to cats dad name otherwise set to N/A if no dad name.
		if(cat.getDadName().empty()) {
			dadName = "N/A";
		} else {
			dadName = cat.getDadName();
		}
		string mumName;
		// Set mumName to cats dad name otherwise set to N/A if no dad name.
		if(cat.getMumName().empty()) {
			mumName = "N/A";
		} else {
			mumName = cat.getMumName();
		}

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

	// Gets an const iterator object pointer which points to the start of the horse vector data structure.
	auto it2 = this->storageManager.getHorses()->iter_begin;

	// Loops through the iterator and returns horse objects
	for(unsigned int i = 0; i < this->storageManager.getHorseCount(); i++) {

		// Ensure that the animals are casted to subtypes rather than supertypes.
		const Horse horse = dynamic_cast<const Horse&>(*it2);

		string groupType = typeid(horse).name();
		string name = horse.getName();
		string group = groupType.erase(0,1);
		string breed = horse.getBreed();
		string colour = horse.getColour();
		string earType = horse.getEarType();
		string height = horse.getHeight();
		string tailColour = horse.getTailColour();
		string dadName;
		// Set dadName to horses dad name otherwise set to N/A if no dad name.
		if(horse.getDadName().empty()) {
			dadName = "N/A";
		} else {
			dadName = horse.getDadName();
		}
		string mumName;
		// Set dadName to horses dad name otherwise set to N/A if no dad name.
		if(horse.getMumName().empty()) {
			mumName = "N/A";
		} else {
			mumName = horse.getMumName();
		}

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

}

/* Gets the user input for the inventory search. Transforms string to lowercase, removes whitespace
and splits by ' ' delimeter. Normalizing user input to an expected format. */
void Interface::getInput() {
	string userInput;
	string userInputToLower;
	cout << "Enter the first letter of the animal group and the name of the specified one to find its paternal tree: ";

	//Gets user input
	getline(cin, userInput);

	//Transforms userInput to all lowercase
	transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

	//Removes whitespace before and after entered string
	string userInputToLowerNoWhiteSpace = trim(userInput);

	//Splits string using space as a delimeter
	stringstream ss(userInputToLowerNoWhiteSpace);
	int i = 0;
	string item;
	string outputToSM[2];
	while (getline(ss, item, ' ')) {
		outputToSM[i] = item;
		i++;
	}

	// Calls the private getPaternalTree() method, with the string parameters.
	getPaternalTree(outputToSM[0], outputToSM[1]);

}

/* Handles the paternal tree search. Calls the storageManager.search() method with
the parameters of the animal group and the animals name. This then returns an animal
object which can be used to get the animal objects name and its fathers name. As the
animal type will be the same as the initially searched one, we can recursively call
this method with the new dad name to find its paternal tree. This can repeat until
no dad is found and it equals null. A counter is incremented and used to when handling
the stage of the paternal tree as the max paternal tree length is 3.*/
void Interface::getPaternalTree(string type, string name) {

	// Initialize result to the animal pointer, of the animal with the given type and name.
	Animal* result = storageManager.search(type, name);

	/* If the animal pointer is not null, recursively call this method until dad the result is null,
	at which point we have reached the end of the paternal tree. Else display one of the not found messages */
	if(result != NULL) {

			if(type == "a" && counter == 0) {
			string groupType = typeid(*result).name();
			string group = groupType.erase(0,1);
			cout << name << " is found in the " << group << " inventory." << endl;

			}
			paternalTree[counter] = result->getName();
			counter++;
			getPaternalTree(type, result->getDadName());
	// Called if there was no father found for the input animal so output results accordingly.
	} else if(counter == 1){
		counter = 0;
		cout << "Paternal tree of " << paternalTree[0] << ":" << endl;
		cout << paternalTree[0] << " <-- [END]" << endl;
	// Called if there was only one father found and output results accordingly.
	} else if(counter == 2) {
		counter = 0;
		cout << "Paternal tree of " << paternalTree[0] << ":" << endl;
		cout << paternalTree[0] << " <-- " << paternalTree[1] << " <-- [END]" << endl;
	// Called it there was 2 fathers found and output results accordingly.
	} else if(counter == 3) {
		counter = 0;
		cout << "Paternal tree of " << paternalTree[0] << ":" << endl;
		cout << paternalTree[0] << " <-- " << paternalTree[1] << " <-- " << paternalTree[2] << " <-- [END]" << endl;
	// If storageManager search() result equals null, display one of the following not found messages.
	} else {
		//If animal type was 'd' but name was not found, output the following:
		if(type == "d") {
			cout << name << " was not found in the inventory within the \e[1mdogs\e[0m!" << endl;
		//If animal type was 'c' but name was not found, output the following:
		} else if(type == "c") {
			cout << name << " was not found in the inventory within the \e[1mcats\e[0m!" << endl;
		//If animal type was 'h' but name was not found, output the following:
		} else if(type == "h") {
			cout << name << " was not found in the inventory within the \e[1mhorses\e[0m!" << endl;
	  //If animal type was 'a' and name wasn't found or animal type was unrecognised, output the following:
		} else {
			cout << name << " was not found in any inventory!" << endl;
		}
	}

}

// Trim the input string s to remove whitespace on the left of the string.
string Interface::ltrim(string s, const char* t) {
	return s.erase(0, s.find_first_not_of(t));
}

// Trim the input string s to remove whitespace on the right of the string.
string Interface::rtrim(string s, const char* t) {
	return s.erase(s.find_last_not_of(t) + 1);
}

// Trim the input string s to remove whitespace on the left and right of the string.
string Interface::trim(string s, const char* t) {
	return ltrim(rtrim(s, t), t);
}
