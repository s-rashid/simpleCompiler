#include "jumpequalinstruction.h"

JumpEqualInstruction::JumpEqualInstruction(Program* p) : JumpInstruction (p, "JumpEqualInstruction") {}

JumpEqualInstruction::~JumpEqualInstruction() {}

bool JumpEqualInstruction::jump(int compare) {
    return compare == 0;
}
