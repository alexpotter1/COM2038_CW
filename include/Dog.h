#include <string>
#include "Animal.h"

using namespace std;

class Dog : public Animal {
private:
  string earType;
  string height;
  string tailColour;
public:
  Dog(string breed, string name, string colour, string dadName, string mumName,
           string earType, string height, string tailColour)
           : Animal(breed, name, colour, dadName, mumName)
           {
             this->earType = earType;
             this->height = height;
             this->tailColour = tailColour;
           }
  ~Dog();
  string getEarType();
  string getHeight();
  string getTailColour();
};
