#ifndef JUMPEQUALINSTRUCTION_H
#define JUMPEQUALINSTRUCTION_H

#include <QString>
#include "jumpinstruction.h"
#include "program.h"
#include "labeloperand.h"

class JumpEqualInstruction : public JumpInstruction {
public:
    JumpEqualInstruction(Program*);
    ~JumpEqualInstruction();

protected:
    bool jump(int);
};

#endif // JUMPEQUALINSTRUCTION_H
