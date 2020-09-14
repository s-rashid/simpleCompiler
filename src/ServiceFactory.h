#ifndef SERVICEFACTORY_H
#define SERVICEFACTORY_H

#include "./program/Compiler.h"
#include "./program/ScapesCompiler.h"

using namespace std;

class ServiceFactory {
  public:
    static Compiler* getCompilerInstance();

};

#endif
