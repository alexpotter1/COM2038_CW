#include <string>
#include "Animal.h"

using namespace std;

class Horse : public Animal {
private:
  string earType;
  double height;
  string tailColour;
public:
  Horse(string earType, double height, string tailColour);
  ~Horse();
  string getEarType();
  double getHeight();
  string getTailColour();
};
