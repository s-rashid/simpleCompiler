#ifndef JUMPMOREINSTRUCTION_H
#define JUMPMOREINSTRUCTION_H

#include <QString>
#include "jumpinstruction.h"
#include "program.h"
#include "labeloperand.h"

class JumpMoreInstruction : public JumpInstruction {
public:
    JumpMoreInstruction(Program*);
    ~JumpMoreInstruction();
    int run();
};

#endif // JUMPMOREINSTRUCTION_H
