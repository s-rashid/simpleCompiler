#ifndef ENDINSTRUCTION_H
#define ENDINSTRUCTION_H

#include <QString>
#include "instruction.h"

class EndInstruction : public Instruction {
public:
    EndInstruction(Program*);
    ~EndInstruction();
    int run(UserDisplayPrompt*);

private:
    ValidOperandTypes* getOperandTypes(int);
};

#endif // ENDINSTRUCTION_H
