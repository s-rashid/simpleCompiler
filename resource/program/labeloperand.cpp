#include "labeloperand.h"

LabelOperand::LabelOperand(){
    this->label = nullptr;
}
LabelOperand::LabelOperand(Label* iden) : Operand () {
    this->label = iden;
}

Label* LabelOperand::getIdentifier() {
    return this->label;
}
void LabelOperand::read(const QJsonObject& json, ProgramContext* context){
    QJsonObject varJson = json["label"].toObject();
    QString name = varJson["name"].toString();
    this->label = dynamic_cast<Label*>(context->getIdentifier(name));
}
void LabelOperand::write(QJsonObject& json){
    json["type"] = QString("LabelOperand");
    QJsonObject labelJson;
    this->label->write(labelJson);
    json["label"] = labelJson;
}
