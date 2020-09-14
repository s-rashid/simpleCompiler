#include "addinstruction.h"

AddInstruction::AddInstruction(Program* p) : Instruction (p, "AddInstruction", 2) {}

AddInstruction::~AddInstruction() {}

int AddInstruction::run(UserDisplayPrompt*) {
    int value = dynamic_cast<ValueOperand*>(operands[0])->getValue();
    Variable* iden = dynamic_cast<VariableOperand*>(operands[1])->getIdentifier();

    int newValue = iden->getValue() + value;
    iden->setValue(newValue);

    return 0;
}

ValidOperandTypes* AddInstruction::getOperandTypes(int operandIndex) {
    ValidOperandTypes* types = new ValidOperandTypes;
    if (operandIndex == 0) {
        types->validateValueOperand();
    } else if (operandIndex == 1) {
        types->validateVariableOperand();
    }
    return types;
}

