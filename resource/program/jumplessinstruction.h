#ifndef JUMPLESSINSTRUCTION_H
#define JUMPLESSINSTRUCTION_H

#include <QString>
#include "jumpinstruction.h"
#include "program.h"
#include "labeloperand.h"

class JumpLessInstruction : public JumpInstruction {
public:
    JumpLessInstruction(Program*);
    ~JumpLessInstruction();

protected:
    bool jump(int);
};

#endif // JUMPLESSINSTRUCTION_H
