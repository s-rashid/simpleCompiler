#ifndef OPERANDFACTORY_H
#define OPERANDFACTORY_H

class Program;

#include <QString>
#include "program.h"
#include "operand.h"
#include "validoperandtypes.h"
#include "integeroperand.h"
#include "literalintegeroperand.h"
#include "literalstringoperand.h"
#include "labeloperand.h"
#include "unsupportedoperandexception.h"
#include "undeclaredvariableexception.h"

class OperandFactory {
public:
    OperandFactory(ValidOperandTypes*);
    ~OperandFactory();
    Operand* createOperand(Program*, QString);

private:
    ValidOperandTypes* types;
};

#endif // OPERANDFACTORY_H
