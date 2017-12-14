#include <string>
#include "Animal.h"

using namespace std;

class Horse : public Animal {
private:
  string earType;
  string height;
  string tailColour;
public:
  Horse(string breed, string name, string colour, string dadName, string mumName,
           string earType, string height, string tailColour);
  ~Horse() {};
  string getEarType();
  string getHeight();
  string getTailColour();
};
