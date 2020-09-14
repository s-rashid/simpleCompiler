#ifndef DECLAREINTEGERINSTRUCTION_H
#define DECLAREINTEGERINSTRUCTION_H

#include <QString>
#include "instruction.h"
#include "integervariable.h"
#include "integeroperand.h"
#include "identifierinuseexception.h"

class DeclareIntegerInstruction : public Instruction {
public:
    DeclareIntegerInstruction(Program*);
    ~DeclareIntegerInstruction();
    int run();

private:
    ValidOperandTypes* getOperandTypes();
    void preCompile(QList<QString> operandStrs);
};

#endif // DECLAREINTEGERINSTRUCTION_H
