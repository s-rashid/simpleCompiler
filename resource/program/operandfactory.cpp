#include "operandfactory.h"

OperandFactory::OperandFactory() {
    types = new ValidOperandTypes;
}

OperandFactory::OperandFactory(ValidOperandTypes* t) {
    types = t;
}

OperandFactory::~OperandFactory() {
    delete types;
}

void OperandFactory::setValidOperandTypes(ValidOperandTypes* t) {
    delete types;
    types = t;
}

Operand* OperandFactory::createOperand(ProgramContext* context, QString operandStr) {
    QRegExp onlyNumbersRegExp("^\\d+$");
    QRegExp doesNotStartWithSpecialCharRegExp("^[^\\d$:\"]+.*$");
    QRegExp arrayElemRegExp("^\\$[^\\d$:\"]+\\+[^$:\"]+$");
    if (types->isLiteralStringOperandValid() && operandStr.startsWith("\"") && operandStr.endsWith("\"")) {
        return new LiteralStringOperand(operandStr);

    } else if (types->isLiteralIntOperandValid() && onlyNumbersRegExp.exactMatch(operandStr)) {
        return new LiteralIntegerOperand(operandStr);

    } else if (types->isVariableOperandValid() && doesNotStartWithSpecialCharRegExp.exactMatch(operandStr)) {
        Identifier* iden = context->getIdentifier(operandStr);
        if (iden == nullptr) {
            throw UndeclaredVariableException(operandStr);
        }
        Variable* var = dynamic_cast<Variable*>(iden);
        if (var == nullptr) {
            throw UnsupportedOperandException(operandStr);
        }
        return new VariableOperand(var);

    } else if (types->isArrayOperandValid() && arrayElemRegExp.exactMatch(operandStr)) {
        QRegExp separator("[$+]");
        QStringList list = operandStr.split(separator);

        Identifier* iden = context->getIdentifier(list[1]);
        if (iden == nullptr) {
            throw UndeclaredVariableException(list[1]);
        }
        ArrayVariable* var = dynamic_cast<ArrayVariable*>(iden);
        if (var == nullptr) {
            throw UnsupportedOperandException(list[1]);
        }

        OperandFactory factory;
        ValidOperandTypes* integerTypes = new ValidOperandTypes;
        integerTypes->validateIntegerOperand();
        factory.setValidOperandTypes(integerTypes);
        ValueOperand* integerOperand = dynamic_cast<ValueOperand*>(factory.createOperand(context, list[2]));

        return new ArrayOperand(var, integerOperand);

    } else if (types->isLabelOperandValid() && doesNotStartWithSpecialCharRegExp.exactMatch(operandStr)) {
        Identifier* iden = context->getIdentifier(operandStr);
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
