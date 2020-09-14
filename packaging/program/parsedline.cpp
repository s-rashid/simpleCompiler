#include "parsedline.h"

#include <iostream>

ParsedLine::ParsedLine(){}
ParsedLine::ParsedLine(QString label, QString instrucType, QList<QString> operands){
    this->label = label;
    this->instrucType = instrucType;
    this->operands = operands;
}

QString ParsedLine::getLabel() { return label; }
QString ParsedLine::getInstrucType() { return instrucType; }
QList<QString> ParsedLine::getOperands() { return operands; }

void ParsedLine::setLabel(QString l) { this->label = l; }
void ParsedLine::setInstrucType(QString i) { this->instrucType = i; }
void ParsedLine::addOperand(QString o) { this->operands.append(o); }

QString ParsedLine::toQString(){
    QString string;
    string += label + " " + instrucType + " ";
    foreach (QString operand, operands){
        string += operand + " ";
    }
    return string;
}
