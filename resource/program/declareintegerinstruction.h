#ifndef DECLAREINTEGERINSTRUCTION_H
#define DECLAREINTEGERINSTRUCTION_H

#include <QString>
#include "instruction.h"
#include "integervariable.h"
#include "variableoperand.h"
#include "identifierinuseexception.h"
#include "redeclaredvariableexception.h"

class DeclareIntegerInstruction : public Instruction {
public:
    DeclareIntegerInstruction(Program*);
    ~DeclareIntegerInstruction();
    int run(UserDisplayPrompt*);
    void setLabel(Label*);

private:
    ValidOperandTypes* getOperandTypes(int);
    void preCompile(ProgramContext*, QList<QString> operandStrs);
};

#endif // DECLAREINTEGERINSTRUCTION_H
