#ifndef VARIABLEOPERAND_H
#define VARIABLEOPERAND_H

#include <QString>
#include "valueoperand.h"
#include "variable.h"

class VariableOperand : public ValueOperand {
public:
    VariableOperand();
    VariableOperand(Variable*);
    virtual ~VariableOperand() = default;
    virtual int getValue();
    QString getStringValue();
    virtual Variable* getIdentifier();
    virtual void read(const QJsonObject&, ProgramContext*);
    virtual void write(QJsonObject&);

protected:
    Variable* var;

};

#endif // VARIABLEOPERAND_H
