#include <string>
#include "Animal.h"

using namespace std;

class Cat : public Animal {
private:
  string earType;
  double height;
  string tailColour;
public:
  Cat(string breed, string name, string colour, string dadName, string mumName,
           string earType, double height, string tailColour);
  ~Cat() {};
  string getEarType() const;
  double getHeight() const;
  string getTailColour() const;
};
