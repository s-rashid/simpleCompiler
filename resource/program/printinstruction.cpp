#include <iostream>
#include <iomanip>
using namespace std;

#include "printinstruction.h"

PrintInstruction::PrintInstruction(Program* p) : Instruction (p, "PrintInstruction", 1) {}

PrintInstruction::~PrintInstruction() {}

int PrintInstruction::run(UserDisplayPrompt* prompt) {
    ValueOperand* operand = dynamic_cast<ValueOperand*>(operands[0]);
    cout << operand->getStringValue().toStdString() << flush;
    prompt->printToDisplay(operand->getStringValue());
    return 0;
}

ValidOperandTypes* PrintInstruction::getOperandTypes(int operandIndex) {
    ValidOperandTypes* types = new ValidOperandTypes;
    if (operandIndex == 0) {
        types->validateValueOperand();
    }
    return types;
}
