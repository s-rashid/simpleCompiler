#include <iostream>

#include "compareinstruction.h"

CompareInstruction::CompareInstruction(Program* p) : Instruction (p, "CompareInstruction", 2) {}

int CompareInstruction::run(UserDisplayPrompt*) {
    int firstValue = dynamic_cast<ValueOperand*>(this->operands[0])->getValue();
    int secondValue = dynamic_cast<ValueOperand*>(this->operands[1])->getValue();
    int compareValue = firstValue - secondValue;
    std::cout << "Comparing " << firstValue << " to " << secondValue << " returning " << compareValue << std::endl;
    this->program->setLastCompare(compareValue);
    return 0;
}

ValidOperandTypes* CompareInstruction::getOperandTypes(int operandIndex) {
    ValidOperandTypes* types = new ValidOperandTypes;
    if (operandIndex < 2) {
        types->validateIntegerOperand();
    }
    return types;
}

