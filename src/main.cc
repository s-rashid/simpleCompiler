

#include <iostream>

#include "ServiceFactory.h"
#include "./program/Compiler.h"
#include "./program/Program.h"

using namespace std;

int main() {
  // TODO this produces a memory leak; move to a field
  Compiler* compiler = ServiceFactory::getCompilerInstance();
  Program program = compiler->compile("test");

  delete compiler;

  return program.launch();
}
