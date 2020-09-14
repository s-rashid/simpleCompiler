#include <iostream>
#include <iomanip>
using namespace std;

#include "label.h"

Label::Label(int line, QString n) : Identifier (n) {
    this->lineNumber = line;
}

int Label::getValue() {
    return this->lineNumber;
}
/**
 * @brief LabelOperand::write writes an operands data to a json object
 * @param json object to be written to
 */
void Label::write(QJsonObject & json) {
    json["type"] = "Label";
    json["name"] = this->name;
    //json["lineNumber"] = lineNumber;
}


