#pragma once
#include <string>

using namespace std;

class Animal {
private:
	string breed;
	string name;
	string colour;
	string dadName;
	string mumName;

public:
	Animal(string breed, string name, string colour, string dadName, string mumName);
	virtual ~Animal() = default;
	string getBreed() const;
	string getName() const;
	string getColour() const;
	string getDadName() const;
	string getMumName() const;
	virtual string getTailColour() const { return NULL; };
	virtual string getHeight() const { return NULL; };
	virtual string getEarType() const { return NULL; };
};
