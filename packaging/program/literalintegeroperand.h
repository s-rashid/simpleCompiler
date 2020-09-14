#ifndef LITERALINTEGEROPERAND_H
#define LITERALINTEGEROPERAND_H

#include <QString>
#include "valueoperand.h"

class LiteralIntegerOperand : public ValueOperand {
public:
    LiteralIntegerOperand(QString);
    virtual int getValue();
    virtual QString getStringValue();
    void write(QJsonObject&);

protected:
    int value;

};

#endif // LITERALINTEGEROPERAND_H
