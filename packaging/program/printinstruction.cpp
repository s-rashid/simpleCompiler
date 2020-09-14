#include <iostream>
#include <iomanip>
using namespace std;

#include "printinstruction.h"

PrintInstruction::PrintInstruction(Program* p) : Instruction (p, "PrintInstruction", 1) {}

PrintInstruction::~PrintInstruction() {}

int PrintInstruction::run() {
    cout << dynamic_cast<ValueOperand*>(operands[0])->getStringValue().toStdString() << flush;
    return 0;
}

ValidOperandTypes* PrintInstruction::getOperandTypes() {
    ValidOperandTypes* types = new ValidOperandTypes;
    types->validateValueOperand();
    return types;
}
