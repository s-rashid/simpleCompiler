#ifndef OPERANDFACTORY_H
#define OPERANDFACTORY_H

class Program;

#include <QString>
#include "program.h"
#include "programcontext.h"
#include "operand.h"
#include "validoperandtypes.h"
#include "arrayoperand.h"
#include "literalintegeroperand.h"
#include "literalstringoperand.h"
#include "labeloperand.h"
#include "unsupportedoperandexception.h"
#include "undeclaredvariableexception.h"

class OperandFactory {
public:
    OperandFactory();
    OperandFactory(ValidOperandTypes*);
    ~OperandFactory();
    void setValidOperandTypes(ValidOperandTypes*);
    Operand* createOperand(ProgramContext*, QString);

private:
    ValidOperandTypes* types;
};

#endif // OPERANDFACTORY_H
