#include <string>
#include <iomanip>
#include "StorageManager.h"
using namespace std;

class Interface {
public:
	Interface();
	string printAll();
	string search();
	string ltrim(string s, const char* t);
	string rtrim(string s, const char* t);
	string trim(string s, const char* t);
private:
	StorageManager storageManager;
};
