#include "jumpmoreinstruction.h"

JumpMoreInstruction::JumpMoreInstruction(Program* p) : JumpInstruction (p, "JumpMoreInstruction") {}

JumpMoreInstruction::~JumpMoreInstruction() {}

int JumpMoreInstruction::run() {
    if (this->program->getLastCompare() > 0) {
        int line = dynamic_cast<LabelOperand*>(this->operands[0])->getValue();
        this->program->setCurrentLine(line);
    }
    return 0;
}
