#include "../include/StorageManager.h"
#include <iostream>

int main() {
  Dog dog("1", "2", "3", "4", "5", "6", 7.0, "8");
  Cat cat("1", "2", "3", "4", "5", "6", 7.1, "8");
  StorageManager sman;
  sman.addAnimalToStorage(dog);
  sman.addAnimalToStorage(cat);
}
