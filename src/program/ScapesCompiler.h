#ifndef SCAPESCOMPLIER_H
#define SCAPESCOMPLIER_H

#include <string>
#include "Compiler.h"
#include "Program.h"

using namespace std;

class ScapesCompiler : public Compiler{
  public:
    Program compile(string);

};

#endif
