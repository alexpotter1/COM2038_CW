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
           string earType, double height, string tailColour);
  ~Horse() {};
  string getEarType() const;
  double getHeight() const;
  string getTailColour() const;
};
