#ifndef BASICOPERANDFACTORY_H
#define BASICOPERANDFACTORY_H

class ArrayOperand;

#include <QString>
#include "literalintegeroperand.h"
#include "literalstringoperand.h"
#include "labeloperand.h"
#include "variableoperand.h"
#include "arrayoperand.h"

class BasicOperandFactory
{
public:
    Operand* createOperand(QString);
};

#endif // BASICOPERANDFACTORY_H
