#include <string>
#include "Animal.h"

using namespace std;

class Cat : public Animal {
private:
  string earType;
  string height;
  string tailColour;
public:
  Cat(string breed, string name, string colour, string dadName, string mumName,
           string earType, string height, string tailColour);
  ~Cat() {};
  string getEarType() const;
  string getHeight() const;
  string getTailColour() const;
};
