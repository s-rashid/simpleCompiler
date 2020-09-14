#ifndef MOVEINSTRUCTION_H
#define MOVEINSTRUCTION_H

#include "Instruction.h"

using namespace std;

class MoveInstruction : public Instruction {
  public:
    MoveInstruction(string = "Unknown");
    void execute();
};

#endif
