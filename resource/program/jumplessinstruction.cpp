#include "jumplessinstruction.h"

JumpLessInstruction::JumpLessInstruction(Program* p) : JumpInstruction (p, "JumpLessInstruction") {}

JumpLessInstruction::~JumpLessInstruction() {}

bool JumpLessInstruction::jump(int compare) {
    return compare < 0;
}
