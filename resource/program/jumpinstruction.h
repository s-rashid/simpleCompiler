#ifndef JUMPINSTRUCTION_H
#define JUMPINSTRUCTION_H

#include <QString>
#include "instruction.h"
#include "program.h"
#include "labeloperand.h"
#include "basicoperandfactory.h"

class JumpInstruction : public Instruction {
public:
    JumpInstruction(Program*);
    virtual ~JumpInstruction();
    int run(UserDisplayPrompt*);

protected:
    JumpInstruction(Program*, QString);
    virtual bool jump(int);

private:
    ValidOperandTypes* getOperandTypes(int);
};

#endif // JUMPINSTRUCTION_H
