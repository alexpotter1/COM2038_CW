#include <string>

using namespace std;

class Dog : public Animal {
private:
  string earType;
  double height;
  string tailColour;
public:
  Dog(string earType, double height, string tailColour);
  ~Dog();
  string getEarType();
  double getHeight();
  string getTailColour();
};
