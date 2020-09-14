#include "variableoperand.h"

VariableOperand::VariableOperand(){
    this->var = nullptr;
}

VariableOperand::VariableOperand(Variable* iden) : ValueOperand () {
    this->var = iden;
}

int VariableOperand::getValue() {
    return this->var->getValue();
}

QString VariableOperand::getStringValue() {
    return QString::number(getValue());
}

Variable* VariableOperand::getIdentifier() {
    return this->var;
}

void VariableOperand::read(const QJsonObject& json, ProgramContext* context){
    QJsonObject varJson = json["var"].toObject();
    QString name = varJson["name"].toString();
    this->var = dynamic_cast<Variable*>(context->getIdentifier(name));
}

void VariableOperand::write(QJsonObject& json){
    json["type"] = QString("VariableOperand");
    QJsonObject operandJson;
    this->var->write(operandJson);
    json["var"] = operandJson;
}
