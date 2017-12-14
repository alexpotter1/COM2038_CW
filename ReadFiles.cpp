#include "Dog.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

//Need to make methods and probably at least one class of methods.
int main(){
	Dog *d = new Dog();
	vector<Dog*> vec;
	d->setName("Ignas");
	cout << d->getName() << endl;
	vec.push_back(d);
	cout << vec[0]->getName() << endl;
	
	ifstream infile("Dogs.csv");
	string line;
	string fileContent;
	string attribute;
	if(infile.is_open()){
			while(getline(infile, line)){
				//I think I will use a vector instead. So that I wouldnt have to specify the size of the data structure.
				string attributes[8];
				int commaIndex;
				int i = 0;
				//Never gets to the end of line.
				while(line != "\0"){
					commaIndex = line.find(",");
					if(line == ","){
					attributes[i] = "";
					i++;
					attributes[i] = "";
					//I need to not use erase, but instead to use find(from certain index, to another index)
					line.erase(0,1);
					}
					else if(commaIndex == 0){
						attributes[i] = "";
						line.erase(0,1);
					}
					else{
						//need to use substr here instead
						for(int f = 0; f< commaIndex; f++){
							attributes[i] += line[f];
						}
						line.erase(0,commaIndex + 1);
					}
					i++;
				}
				for (int d = 0; d < i; d++){
					cout << "attributes[" << d << "]:" << attributes[d] << 	endl;
				}
			}
	}
}
