#include <iostream>

#include "readintegerinstruction.h"

ReadIntegerInstruction::ReadIntegerInstruction(Program* p) : Instruction (p, "ReadIntegerInstruction", 1) {}

ReadIntegerInstruction::~ReadIntegerInstruction() {}

int ReadIntegerInstruction::run(UserDisplayPrompt* prompt) {
    Variable* iden = dynamic_cast<VariableOperand*>(operands[0])->getIdentifier();

    int i = -1;
    if (prompt->displayInputPrompt(i) == 0) {
        iden->setValue(i);
        return 0;
    }
    return 2;
}

ValidOperandTypes* ReadIntegerInstruction::getOperandTypes(int operandIndex) {
    ValidOperandTypes* types = new ValidOperandTypes;
    if (operandIndex == 0) {
        types->validateVariableOperand();
    }
    return types;
}
