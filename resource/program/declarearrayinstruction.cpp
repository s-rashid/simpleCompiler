#include "declarearrayinstruction.h"

DeclareArrayInstruction::DeclareArrayInstruction(Program* p) : Instruction (p, "DeclareArrayInstruction", 2) {}

DeclareArrayInstruction::~DeclareArrayInstruction() {}

int DeclareArrayInstruction::run(UserDisplayPrompt*) {
    return 0;
}

void DeclareArrayInstruction::setLabel(Label*) {
    throw RedeclaredVariableException(name);
}

ValidOperandTypes* DeclareArrayInstruction::getOperandTypes(int operandIndex) {
    ValidOperandTypes* types = new ValidOperandTypes;
    if (operandIndex == 0) {
        types->validateVariableDeclarationOperand();
    }
    else if (operandIndex == 1) {
        types->setLiteralIntOperandValidity(true);
    }
    return types;
}

void DeclareArrayInstruction::preCompile(ProgramContext* context, QList<QString> operandStrs) {
    int size = operandStrs[1].toInt();
    ArrayVariable* var = new ArrayVariable(operandStrs[0], size);
    bool added = context->addIdentifier(operandStrs[0], var);
    if (!added) {
        throw IdentifierInUseException(operandStrs[0]);
    }
}
