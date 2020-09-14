#include <iostream>
#include <iomanip>
using namespace std;

#include "Variable.h"

Variable::Variable(string n) : Identifier (n, VARIABLE_TAG) {
  value = NULL;
}

Variable::Variable(string n, int* v) : Identifier (n, VARIABLE_TAG) {
  value = v;
}

Variable::Variable(string n, int v) : Identifier (n, VARIABLE_TAG) {
  cout << "test" << to_string(v) << endl;
  value = &v;
}

Variable::~Variable() {
  delete value;
}

void Variable::setValue(int* v) {
  value = v;
}

int Variable::getValue() {
  return *value;
}

void Variable::print() {
  cout << name << " - " << varId << " = ";
  if (value == NULL) {
    cout << "NULL";
  } else {
    cout << to_string(*value);
  }
  cout << endl;
}
