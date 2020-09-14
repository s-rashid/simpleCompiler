#include "jumpinstruction.h"

JumpInstruction::JumpInstruction(Program* p) : Instruction (p, "JumpInstruction", 1) {}

JumpInstruction::JumpInstruction(Program* p, QString n) : Instruction (p, n, 1) {}

JumpInstruction::~JumpInstruction() {}

int JumpInstruction::run() {
    int line = dynamic_cast<LabelOperand*>(this->operands[0])->getValue();
    this->program->setCurrentLine(line);
    return 0;
}

ValidOperandTypes* JumpInstruction::getOperandTypes() {
    ValidOperandTypes* types = new ValidOperandTypes;
    types->validateLabelOperand();
    return types;
}
