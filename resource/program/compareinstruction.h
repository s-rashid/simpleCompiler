#ifndef COMPAREINSTRUCTION_H
#define COMPAREINSTRUCTION_H

#include <QString>
#include "instruction.h"
#include "valueoperand.h"

class CompareInstruction : public Instruction {
public:
    CompareInstruction(Program*);
    int run(UserDisplayPrompt*);

private:
    ValidOperandTypes* getOperandTypes(int);
};

#endif // COMPAREINSTRUCTION_H
