#include "labeloperand.h"

LabelOperand::LabelOperand(Label* iden) : Operand () {
    this->label = iden;
}

int LabelOperand::getValue() {
    return this->label->getValue();
}

Label* LabelOperand::getIdentifier() {
    return this->label;
}

void LabelOperand::write(QJsonObject& json){
    json["type"] = QString("LabelOperand");
    QJsonObject labelJson;
    this->label->write(labelJson);
    json["label"] = labelJson;;
}
