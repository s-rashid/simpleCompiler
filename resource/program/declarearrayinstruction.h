#ifndef DECLAREINTEGERARRAYINSTRUCTION_H
#define DECLAREINTEGERARRAYINSTRUCTION_H

#include <QString>
#include "instruction.h"
#include "arrayvariable.h"
#include "variableoperand.h"
#include "identifierinuseexception.h"
#include "redeclaredvariableexception.h"

class DeclareArrayInstruction : public Instruction {
public:
    DeclareArrayInstruction(Program*);
    ~DeclareArrayInstruction();
    int run(UserDisplayPrompt*);
    void setLabel(Label*);

private:
    ValidOperandTypes* getOperandTypes(int);
    void preCompile(ProgramContext*, QList<QString>);
};

#endif // DECLAREINTEGERARRAYINSTRUCTION_H
