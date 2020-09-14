#ifndef VALUEOPERAND_H
#define VALUEOPERAND_H

#include "operand.h"

class ValueOperand : public Operand {
public:
    virtual ~ValueOperand() = default;
    virtual int getValue() = 0;
    virtual QString getStringValue() = 0;

protected:
    ValueOperand();

};

#endif // VALUEOPERAND_H
