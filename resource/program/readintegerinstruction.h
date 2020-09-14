#ifndef READINTEGERINSTRUCTION_H
#define READINTEGERINSTRUCTION_H

#include <QString>
#include "instruction.h"
#include "variable.h"
#include "variableoperand.h"

class ReadIntegerInstruction : public Instruction {
public:
    ReadIntegerInstruction(Program*);
    ~ReadIntegerInstruction();
    int run(UserDisplayPrompt*);

private:
    ValidOperandTypes* getOperandTypes(int);
};

#endif // READINTEGERINSTRUCTION_H
