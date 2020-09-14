#include <iostream>
#include <iomanip>
using namespace std;

#include "Identifier.h"

int count = 0;
Identifier::Identifier(string n, string tag) {
  name = n;
  // generate random int
  varId = tag + ":" + to_string(count++);
}

Identifier::~Identifier() {

}

void Identifier::print() {
  cout << name << " - " << varId << endl;
}
