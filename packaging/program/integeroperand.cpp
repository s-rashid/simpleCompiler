#include "integeroperand.h"

IntegerOperand::IntegerOperand(IntegerVariable* iden) : VariableOperand () {
    this->var = iden;
}

int IntegerOperand::getValue() {
    return this->var->getValue();
}

QString IntegerOperand::getStringValue() {
    return QString::number(this->var->getValue());
}

Variable* IntegerOperand::getIdentifier() {
    return this->var;
}

void IntegerOperand::write(QJsonObject& json){
    json["type"] = QString("IntegerOperand");
    QJsonObject operandJson;
    this->var->write(operandJson);
    json["var"] = operandJson;
}
