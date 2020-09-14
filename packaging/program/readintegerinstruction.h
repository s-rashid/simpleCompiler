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
    int run();

private:
    int getNumArgs();
    ValidOperandTypes* getOperandTypes();
};

#endif // READINTEGERINSTRUCTION_H
