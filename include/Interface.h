#include <string>
#include <iomanip>
#include "StorageManager.h"
using namespace std;

class Interface {
public:
	Interface(StorageManager& smanager);
	string printAll();
	string search();
	string ltrim(string s, const char* t = " \t\n\r\f\v");
	string rtrim(string s, const char* t = " \t\n\r\f\v");
	string trim(string s, const char* t = " \t\n\r\f\v");
private:
	StorageManager storageManager;
};
