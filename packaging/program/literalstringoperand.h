#ifndef LITERALSTRINGOPERAND_H
#define LITERALSTRINGOPERAND_H

#include <QString>
#include "valueoperand.h"

class LiteralStringOperand : public ValueOperand {
public:
    LiteralStringOperand(QString);
    virtual int getValue();
    virtual QString getStringValue();
    void write(QJsonObject&);

protected:
    QString value;

};

#endif // LITERALSTRINGOPERAND_H
