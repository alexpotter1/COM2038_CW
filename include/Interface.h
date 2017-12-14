#include <string>
#include "StorageManager.h"
using namespace std;

class Interface {
public:
	string printAll();
	string search();
private:
	StorageManager storageManager;
};
