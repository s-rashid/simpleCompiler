#include "instruction.h"
#include <QDebug>

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

void Instruction::compile(ProgramContext* context, QList<QString> operandStrs) {
    if (operandStrs.size() != this->numArgs) {
        throw InvalidNumOperandsException(this->name, this->numArgs, operandStrs.size());
    }
    this->preCompile(context, operandStrs);
    OperandFactory factory;
    for (int i=0; i < this->numArgs; i++) {
        factory.setValidOperandTypes(this->getOperandTypes(i));
        this->operands.append(factory.createOperand(context, operandStrs[i]));
    }
}

QString Instruction::to_string() {
    return this->name;
}

void Instruction::read(const QJsonObject& json, ProgramContext* context){
    if (json.contains("label")){
        QString name = json["label"].toString();
        Label* label = dynamic_cast<Label*>(context->getIdentifier(name));
        this->setLabel(label);
    }
    if (json.contains("operands")){
        BasicOperandFactory bof;
        foreach (QJsonValue jsonValue, json["operands"].toArray()){
            QJsonObject json = jsonValue.toObject();
            QString type = json["type"].toString();
            Operand* operand = bof.createOperand(type);
            operand->read(json, context);
            this->addOperand(operand);
        }
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
        json["label"] = label->getName();
    }
}

void Instruction::preCompile(ProgramContext*, QList<QString>) {

}

void Instruction::setLabel(Label* label) {
    this->label = label;
}

Label* Instruction::getLabel() {
    return this->label;
}

void Instruction::addOperand(Operand* operand){
    this->operands.append(operand);
}
