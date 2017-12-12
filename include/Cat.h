#include <string>
#include "Animal.h"

using namespace std;

class Cat : public Animal {
private:
  string earType;
  double height;
  string tailColour;
public:
  Cat(string earType, double height, string tailColour);
  ~Cat();
  string getEarType();
  double getHeight();
  string getTailColour();
};
