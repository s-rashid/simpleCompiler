#include "declareintegerinstruction.h"

DeclareIntegerInstruction::DeclareIntegerInstruction(Program* p) : Instruction (p, "DeclareIntegerInstruction", 1) {}

DeclareIntegerInstruction::~DeclareIntegerInstruction() {}

int DeclareIntegerInstruction::run(UserDisplayPrompt*) {
    return 0;
}

void DeclareIntegerInstruction::setLabel(Label*) {
    throw RedeclaredVariableException(name);
}

ValidOperandTypes* DeclareIntegerInstruction::getOperandTypes(int operandIndex) {
    ValidOperandTypes* types = new ValidOperandTypes;
    if (operandIndex == 0) {
        types->validateVariableDeclarationOperand();
    }
    return types;
}

void DeclareIntegerInstruction::preCompile(ProgramContext* context, QList<QString> operandStrs) {
    IntegerVariable* var = new IntegerVariable(operandStrs[0]);
    bool added = context->addIdentifier(operandStrs[0], var);
    if (!added) {
        throw IdentifierInUseException(operandStrs[0]);
    }
}


