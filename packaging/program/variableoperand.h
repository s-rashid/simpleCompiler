#ifndef VARIABLEOPERAND_H
#define VARIABLEOPERAND_H

#include <QString>
#include "valueoperand.h"
#include "variable.h"

class VariableOperand : public ValueOperand {
public:
    virtual ~VariableOperand() = default;
    virtual int getValue() = 0;
    QString getStringValue() = 0;
    virtual Variable* getIdentifier() = 0;

protected:
    VariableOperand();

};

#endif // VARIABLEOPERAND_H
