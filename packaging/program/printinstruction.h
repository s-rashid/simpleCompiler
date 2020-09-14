#ifndef PRINTINSTRUCTION_H
#define PRINTINSTRUCTION_H

#include <QString>
#include "instruction.h"
#include "valueoperand.h"

class PrintInstruction : public Instruction {
public:
    PrintInstruction(Program*);
    ~PrintInstruction();
    int run();

private:
    ValidOperandTypes* getOperandTypes();
};

#endif
