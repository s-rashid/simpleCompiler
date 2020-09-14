#include "moveinstruction.h"

MoveInstruction::MoveInstruction(Program* p) : Instruction (p, "MoveInstruction", 2) {}

MoveInstruction::~MoveInstruction() {}

int MoveInstruction::run(UserDisplayPrompt*) {
    int value = dynamic_cast<ValueOperand*>(operands[0])->getValue();
    Variable* iden = dynamic_cast<VariableOperand*>(operands[1])->getIdentifier();

    iden->setValue(value);

    return 0;
}

ValidOperandTypes* MoveInstruction::getOperandTypes(int operandIndex) {
    ValidOperandTypes* types = new ValidOperandTypes;
    if (operandIndex == 0) {
        types->validateIntegerOperand();
    } else if (operandIndex == 1) {
        types->validateVariableOperand();
    }
    return types;
}
