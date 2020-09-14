#ifndef ARRAYOPERAND_H
#define ARRAYOPERAND_H

class BasicOperandFactory;

#include <QString>
#include "variableoperand.h"
#include "arrayvariable.h"
#include "basicoperandfactory.h"

class ArrayOperand : public VariableOperand {
public:
    ArrayOperand();
    ArrayOperand(ArrayVariable*, ValueOperand*);
    int getValue();
    Variable* getIdentifier();
    void read(const QJsonObject&, ProgramContext*);
    void write(QJsonObject&);

protected:
    ValueOperand* index;
};

#endif // ARRAYOPERAND_H
