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
	string getBreed();
	string getName();
	string getColour();
	string getDadName();
	string getMumName();
};
