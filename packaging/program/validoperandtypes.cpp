#include "validoperandtypes.h"

ValidOperandTypes::ValidOperandTypes() {
    invalidateAll();
}

void ValidOperandTypes::invalidateAll() {
    labelOperand = false;
    integerOperand = false;
    literalIntOperand = false;
    literalStringOperand = false;
}

void ValidOperandTypes::validateLabelOperand() {
    invalidateAll();
    labelOperand = true;
}

void ValidOperandTypes::validateValueOperand() {
    invalidateAll();
    integerOperand = true;
    literalIntOperand = true;
    literalStringOperand = true;
}

void ValidOperandTypes::validateVariableOperand() {
    invalidateAll();
    integerOperand = true;
}

void ValidOperandTypes::validateIntegerOperand() {
    invalidateAll();
    integerOperand = true;
    literalIntOperand = true;
}

bool ValidOperandTypes::isLabelOperandValid() {
    return labelOperand;
}

bool ValidOperandTypes::isIntegerOperandValid() {
    return integerOperand;
}

void ValidOperandTypes::setIntegerOperandValidity(bool isValid) {
    integerOperand = isValid;
}

bool ValidOperandTypes::isLiteralIntOperandValid() {
    return literalIntOperand;
}

void ValidOperandTypes::setLiteralIntOperandValidity(bool isValid) {
    literalIntOperand = isValid;
}

bool ValidOperandTypes::isLiteralStringOperandValid() {
    return literalStringOperand;
}

void ValidOperandTypes::setLiteralStringOperandValidity(bool isValid) {
    literalStringOperand = isValid;
}
