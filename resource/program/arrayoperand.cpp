#include "arrayoperand.h"

ArrayOperand::ArrayOperand() : VariableOperand (nullptr){};
ArrayOperand::ArrayOperand(ArrayVariable *iden, ValueOperand* index) : VariableOperand (iden) {
    this->index = index;
}

int ArrayOperand::getValue() {
    return dynamic_cast<ArrayVariable*>(this->var)->getArrayValue(index->getValue());
}

Variable* ArrayOperand::getIdentifier() {
    return dynamic_cast<ArrayVariable*>(this->var)->get(index->getValue());
}

void ArrayOperand::read(const QJsonObject& json, ProgramContext* context){
    QJsonObject varJson = json["var"].toObject();
    QString name = varJson["name"].toString();
    this->var = dynamic_cast<Variable*>(context->getIdentifier(name));

    BasicOperandFactory bof;
    QJsonObject indexJson = json["index"].toObject();
    QString opType = indexJson["type"].toString();
    this->index = dynamic_cast<ValueOperand*>(bof.createOperand(opType));
    index->read(indexJson, context);
}

/**
 * @brief LiteralIntegerOperand::write an operands data to a json object
 * @param json object to be written to
 */
void ArrayOperand::write(QJsonObject& json){
    json["type"] = QString("ArrayOperand");
    QJsonObject indexJson;
    this->index->write(indexJson);
    json["index"] = indexJson;
    QJsonObject varJson;
    this->var->write(varJson);
    json["var"] = varJson;
}
