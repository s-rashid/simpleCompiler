#include "validoperandtypes.h"

ValidOperandTypes::ValidOperandTypes() {
    invalidateAll();
}

void ValidOperandTypes::invalidateAll() {
    labelOperand = false;
    variableOperand = false;
    arrayOperand = false;
    literalIntOperand = false;
    literalStringOperand = false;
}

void ValidOperandTypes::validateLabelOperand() {
    invalidateAll();
    labelOperand = true;
}

void ValidOperandTypes::validateValueOperand() {
    invalidateAll();
    variableOperand = true;
    arrayOperand = true;
    literalIntOperand = true;
    literalStringOperand = true;
}

void ValidOperandTypes::validateVariableOperand() {
    invalidateAll();
    variableOperand = true;
    arrayOperand = true;
}

void ValidOperandTypes::validateVariableDeclarationOperand() {
    invalidateAll();
    variableOperand = true;
}

void ValidOperandTypes::validateIntegerOperand() {
    invalidateAll();
    variableOperand = true;
    arrayOperand = true;
    literalIntOperand = true;
}

void ValidOperandTypes::validateArrayOperand() {
    invalidateAll();
    arrayOperand = true;
}

bool ValidOperandTypes::isLabelOperandValid() {
    return labelOperand;
}

bool ValidOperandTypes::isVariableOperandValid() {
    return variableOperand;
}

bool ValidOperandTypes::isArrayOperandValid() {
    return arrayOperand;
}

void ValidOperandTypes::setVariableOperandValidity(bool isValid) {
    variableOperand = isValid;
}

void ValidOperandTypes::setArrayOperandValidity(bool isValid) {
    arrayOperand = isValid;
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
