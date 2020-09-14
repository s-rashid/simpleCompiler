#ifndef MOVEINSTRUCTION_H
#define MOVEINSTRUCTION_H

#include <QString>
#include "instruction.h"
#include "variable.h"
#include "valueoperand.h"
#include "variableoperand.h"

class MoveInstruction : public Instruction {
public:
    MoveInstruction(Program*);
    ~MoveInstruction();
    int run(UserDisplayPrompt*);

private:
    ValidOperandTypes* getOperandTypes(int);
};

#endif // MOVEINSTRUCTION_H
