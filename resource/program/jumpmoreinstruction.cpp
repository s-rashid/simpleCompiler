#include "jumpmoreinstruction.h"

JumpMoreInstruction::JumpMoreInstruction(Program* p) : JumpInstruction (p, "JumpMoreInstruction") {}

JumpMoreInstruction::~JumpMoreInstruction() {}

bool JumpMoreInstruction::jump(int compare) {
    return compare > 0;
}
