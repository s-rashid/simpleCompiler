#include "jumpinstruction.h"

JumpInstruction::JumpInstruction(Program* p) : Instruction (p, "JumpInstruction", 1) {}

JumpInstruction::JumpInstruction(Program* p, QString n) : Instruction (p, n, 1) {}

JumpInstruction::~JumpInstruction() {}

int JumpInstruction::run(UserDisplayPrompt*) {
    if (jump(this->program->getLastCompare())) {
        Label* label = dynamic_cast<LabelOperand*>(this->operands[0])->getIdentifier();
        this->program->jumpTo(label);
    }
    return 0;
}

bool JumpInstruction::jump(int) {
    return true;
}

ValidOperandTypes* JumpInstruction::getOperandTypes(int operandIndex) {
    ValidOperandTypes* types = new ValidOperandTypes;
    if (operandIndex == 0) {
        types->validateLabelOperand();
    }
    return types;
}
