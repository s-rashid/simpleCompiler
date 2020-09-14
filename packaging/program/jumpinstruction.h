#ifndef JUMPINSTRUCTION_H
#define JUMPINSTRUCTION_H

#include <QString>
#include "instruction.h"
#include "program.h"
#include "labeloperand.h"
#include "operandfactory.h"

class JumpInstruction : public Instruction {
public:
    JumpInstruction(Program*);
    virtual ~JumpInstruction();
    virtual int run();

protected:
    JumpInstruction(Program*, QString);

private:
    ValidOperandTypes* getOperandTypes();
};

#endif // JUMPINSTRUCTION_H
