#include "label.h"

Label::Label(QString n) : Identifier (n) {}

void Label::read(const QJsonObject& json){
    this->name = json["name"].toString();
}
/**
 * @brief LabelOperand::write writes an operands data to a json object
 * @param json object to be written to
 */
void Label::write(QJsonObject & json) {
    json["type"] = "Label";
    json["name"] = this->name;
}


