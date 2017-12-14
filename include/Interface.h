#include <string>
#include <iomanip>
#include "StorageManager.h"
using namespace std;

class Interface {
public:
	Interface();
	string printAll();
	string search();
private:
	StorageManager storageManager;
};
