#ifndef COMPLIER_H
#define COMPLIER_H

#include <string>
#include "Program.h"

using namespace std;

class Compiler {
  public:
    virtual ~Compiler() = default;
    virtual Program compile(string) = 0;
};

#endif
