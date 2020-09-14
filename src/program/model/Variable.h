#ifndef VARIABLE_H
#define VARIABLE_H

#include "Identifier.h"

using namespace std;

#define VARIABLE_TAG "var"

class Variable : public Identifier {
  public:
    Variable(string);
    Variable(string, int*);
    Variable(string, int);
    ~Variable();
    void setValue(int*);
    int getValue();
    void print();

  protected:
    int* value;
};

#endif
