#include "literalstringoperand.h"
LiteralStringOperand::LiteralStringOperand(){};
LiteralStringOperand::LiteralStringOperand(QString string) : ValueOperand () {
    this->value = string.mid(1, string.size() - 2);
}

int LiteralStringOperand::getValue() {
    return this->value.toInt();
}

QString LiteralStringOperand::getStringValue() {
    return this->value;
}
void LiteralStringOperand::read(const QJsonObject& json, ProgramContext*){
    this->value = json["value"].toString();
}
/**
 * @brief LiteralStringOperand::write writes an operands data to a json object
 * @param json object to be written to
 */
void LiteralStringOperand::write(QJsonObject& json){
    json["type"] = QString("LiteralStringOperand");
    json["value"] = this->value;
}
