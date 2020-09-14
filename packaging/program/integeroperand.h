#ifndef INTEGEROPERAND_H
#define INTEGEROPERAND_H

#include <QString>
#include "variableoperand.h"
#include "integervariable.h"

class IntegerOperand : public VariableOperand {
public:
    IntegerOperand(IntegerVariable*);
    int getValue();
    QString getStringValue();
    Variable* getIdentifier();
    void write(QJsonObject&);

protected:
    Variable* var;
};

#endif // INTEGEROPERAND_H
