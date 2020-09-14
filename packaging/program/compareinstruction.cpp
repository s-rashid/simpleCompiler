#include <iostream>

#include "compareinstruction.h"

CompareInstruction::CompareInstruction(Program* p) : Instruction (p, "CompareInstruction", 2) {}

int CompareInstruction::run() {
    int firstValue = dynamic_cast<ValueOperand*>(this->operands[0])->getValue();
    int secondValue = dynamic_cast<ValueOperand*>(this->operands[1])->getValue();
    int compareValue = firstValue - secondValue;
    std::cout << "Comparing " << firstValue << " to " << secondValue << " returning " << compareValue << std::endl;
    this->program->setLastCompare(compareValue);
    return 0;
}

ValidOperandTypes* CompareInstruction::getOperandTypes() {
    ValidOperandTypes* types = new ValidOperandTypes;
    types->validateIntegerOperand();
    return types;
}
