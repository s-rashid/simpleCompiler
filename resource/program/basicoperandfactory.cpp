#include "basicoperandfactory.h"

Operand* BasicOperandFactory::createOperand(QString type){
    if (QString::compare(type, "VariableOperand") == 0) {
        return new VariableOperand();
    } else if (QString::compare(type, "LabelOperand") == 0){
        return new LabelOperand();
    } else if (QString::compare(type, "LiteralIntegerOperand") == 0){
        return new LiteralIntegerOperand();
    } else if (QString::compare(type, "LiteralStringOperand") == 0){
        return new LiteralStringOperand();
    } else if (QString::compare(type, "ArrayOperand") == 0){
        return new ArrayOperand();
    }
    return nullptr;
}
