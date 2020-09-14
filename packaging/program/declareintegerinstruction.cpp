#include "declareintegerinstruction.h"

DeclareIntegerInstruction::DeclareIntegerInstruction(Program* p) : Instruction (p, "DeclareIntegerInstruction", 1) {}

DeclareIntegerInstruction::~DeclareIntegerInstruction() {}

int DeclareIntegerInstruction::run() {
    dynamic_cast<IntegerOperand*>(this->operands[0])->getIdentifier()->declare();
    return 0;
}

ValidOperandTypes* DeclareIntegerInstruction::getOperandTypes() {
    ValidOperandTypes* types = new ValidOperandTypes;
    types->setIntegerOperandValidity(true);
    return types;
}

void DeclareIntegerInstruction::preCompile(QList<QString> operandStrs) {
    IntegerVariable* var = new IntegerVariable(operandStrs[0]);
    bool added = this->program->addIdentifier(operandStrs[0], var);
    if (!added) {
        throw IdentifierInUseException(operandStrs[0]);
    }
}
