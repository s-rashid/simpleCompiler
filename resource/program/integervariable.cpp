#include <iostream>
#include "integervariable.h"
using namespace std;

IntegerVariable::IntegerVariable(QString n) : Variable (n) {
    this->value = 0;
}

IntegerVariable::~IntegerVariable() {

}

void IntegerVariable::setValue(int v) {
    define();
    this->value = v;
}

int IntegerVariable::getValue() {
    if (!this->isDefined) {
        throw UndefinedVariableException(name);
    }
    return this->value;
}


void IntegerVariable::read(const QJsonObject& json) {
    this->name = json["name"].toString();
}

void IntegerVariable::write(QJsonObject & json) {
    json["type"] = "IntegerVariable";
    json["name"] = this->name;
}

void IntegerVariable::print() {
    cout << this->name.toStdString() << " = ";
    if (!this->isDefined) {
        cout << "NULL";
    } else {
        cout << to_string(this->value);
    }
    cout << endl;
}
