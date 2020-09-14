#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>
#include "./model/Instruction.h"
#include "./model/MoveInstruction.h"
#include "./model/Identifier.h"
#include "./model/Label.h"
#include "./model/Variable.h"


using namespace std;

class Program {
  public:
    Program();
    ~Program();
    int launch();

  private:
    Instruction* rootInstruction;
};

#endif
