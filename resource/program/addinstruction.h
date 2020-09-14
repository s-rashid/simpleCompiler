#ifndef ADDINSTRUCTION_H
#define ADDINSTRUCTION_H

#include <QString>
#include "instruction.h"
#include "variable.h"
#include "valueoperand.h"
#include "variableoperand.h"

class AddInstruction : public Instruction {
public:
    AddInstruction(Program*);
    ~AddInstruction();
    int run(UserDisplayPrompt*);

private:
    ValidOperandTypes* getOperandTypes(int);
};

#endif // ADDINSTRUCTION_H
