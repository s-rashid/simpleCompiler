#include "operandfactory.h"

OperandFactory::OperandFactory(ValidOperandTypes* t) {
    types = t;
}

OperandFactory::~OperandFactory() {
    delete types;
}

Operand* OperandFactory::createOperand(Program* program, QString operandStr) {
    QRegExp onlyNumbersRegExp("^\\d+$");
    QRegExp doesNotStartWithSpecialCharRegExp("^[^\\d$:\"]+.*$");
    if (types->isLiteralStringOperandValid() && operandStr.startsWith("\"") && operandStr.endsWith("\"")) {
        return new LiteralStringOperand(operandStr);

    } else if (types->isLiteralIntOperandValid() && onlyNumbersRegExp.exactMatch(operandStr)) {
        return new LiteralIntegerOperand(operandStr);

    } else if (types->isIntegerOperandValid() && doesNotStartWithSpecialCharRegExp.exactMatch(operandStr)) {
        Identifier* iden = program->getIdentifier(operandStr);
        if (iden == nullptr) {
            throw UndeclaredVariableException(operandStr);
        }
        IntegerVariable* var = dynamic_cast<IntegerVariable*>(iden);
        if (var == nullptr) {
            throw UnsupportedOperandException(operandStr);
        }
        return new IntegerOperand(var);

    } else if (types->isLabelOperandValid() && doesNotStartWithSpecialCharRegExp.exactMatch(operandStr)) {
        Identifier* iden = program->getIdentifier(operandStr);
        if (iden == nullptr) {
            throw UndeclaredVariableException(operandStr);
        }
        Label* label = dynamic_cast<Label*>(iden);
        if (label == nullptr) {
            throw UnsupportedOperandException(operandStr);
        }
        return new LabelOperand(label);
    }
    throw UnsupportedOperandException(operandStr);
}
