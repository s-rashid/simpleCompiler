#ifndef ENDINSTRUCTION_H
#define ENDINSTRUCTION_H

#include <QString>
#include "instruction.h"

class EndInstruction : public Instruction {
public:
    EndInstruction(Program*);
    ~EndInstruction();
    int run();

private:
    ValidOperandTypes* getOperandTypes();
};

#endif // ENDINSTRUCTION_H
