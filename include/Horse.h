#include <string>
#include "Animal.h"

using namespace std;

class Horse : public Animal {
private:
  string earType;
  double height;
  string tailColour;
public:
  Horse(string breed, string name, string colour, string dadName, string mumName,
           string earType, double height, string tailColour)
           : Animal(breed, name, colour, dadName, mumName)
           {
             this->earType = earType;
             this->height = height;
             this->tailColour = tailColour;
           }
  ~Horse();
  string getEarType();
  double getHeight();
  string getTailColour();
};
