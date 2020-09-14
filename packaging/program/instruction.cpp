#include "instruction.h"

Instruction::Instruction(Program* p, QString n, int num) {
    this->program = p;
    this->name = n;
    this->numArgs = num;
    this->label = nullptr;
}

Instruction::~Instruction() {
    qDeleteAll(this->operands);
    this->operands.clear();
}

void Instruction::compile(QList<QString> operandStrs) {
    if (operandStrs.size() != this->numArgs) {
        throw InvalidNumOperandsException(this->name, this->numArgs, operandStrs.size());
    }
    this->preCompile(operandStrs);
    OperandFactory factory(this->getOperandTypes());
    for (int i=0; i < this->numArgs; i++) {
        this->operands.append(factory.createOperand(this->program, operandStrs[i]));
    }
}

void Instruction::write(QJsonObject& json) {
    QJsonArray instructionsJson;
    foreach(Operand* operand, this->operands){
        QJsonObject operandJson;
        operand->write(operandJson);
        instructionsJson.append(operandJson);
    }
    json["operands"] = instructionsJson;
    json["type"] = this->name;
    if (label != nullptr) {
        QJsonObject labelJson;
        label->write(labelJson);
        json["label"] = labelJson;
    }
}

void Instruction::preCompile(QList<QString>) {

}

void Instruction::setLabel(Label* label) {
    this->label = label;
}

Label* Instruction::getLabel() {
    return this->label;
}
