#include "literalintegeroperand.h"
LiteralIntegerOperand::LiteralIntegerOperand(){};
LiteralIntegerOperand::LiteralIntegerOperand(QString string) : ValueOperand () {
    this->value = string.toInt();
}

int LiteralIntegerOperand::getValue() {
    return this->value;
}

QString LiteralIntegerOperand::getStringValue() {
    return QString::number(this->value);
}
void LiteralIntegerOperand::read(const QJsonObject& json, ProgramContext *){
    this->value = json["value"].toInt();
}
/**
 * @brief LiteralIntegerOperand::write an operands data to a json object
 * @param json object to be written to
 */
void LiteralIntegerOperand::write(QJsonObject& json){
    json["type"] = QString("LiteralIntegerOperand");
    json["value"] = this->value;
}
