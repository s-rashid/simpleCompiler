#ifndef COMPAREINSTRUCTION_H
#define COMPAREINSTRUCTION_H

#include <QString>
#include "instruction.h"
#include "valueoperand.h"

class CompareInstruction : public Instruction {
public:
    CompareInstruction(Program*);
    int run();

private:
    int getNumArgs();
    ValidOperandTypes* getOperandTypes();
};

#endif // COMPAREINSTRUCTION_H
