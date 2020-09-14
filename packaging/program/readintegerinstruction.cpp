#include <iostream>

#include "readintegerinstruction.h"

ReadIntegerInstruction::ReadIntegerInstruction(Program* p) : Instruction (p, "ReadIntegerInstruction", 1) {}

ReadIntegerInstruction::~ReadIntegerInstruction() {}

int ReadIntegerInstruction::run() {
    Variable* iden = dynamic_cast<VariableOperand*>(operands[0])->getIdentifier();

    // TODO get input from user
    std::cout << "Faking out getting input from user..." << std::endl;
    int i = 3;
    iden->setValue(i);

    return 0;
}

ValidOperandTypes* ReadIntegerInstruction::getOperandTypes() {
    ValidOperandTypes* types = new ValidOperandTypes;
    types->validateVariableOperand();
    return types;
}
