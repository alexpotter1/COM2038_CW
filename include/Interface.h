#include <string>
using namespace std;

class Interface {
public:
	string printAll();
	string search();
private:
	StorageManager storageManager;
};
