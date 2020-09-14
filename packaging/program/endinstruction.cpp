#include <iostream>
#include <iomanip>

#include "endinstruction.h"

EndInstruction::EndInstruction(Program* p) : Instruction (p, "EndInstruction", 0) {}

EndInstruction::~EndInstruction() {}

int EndInstruction::run() {
    return 1;
}

ValidOperandTypes* EndInstruction::getOperandTypes() {
    return nullptr;
}
