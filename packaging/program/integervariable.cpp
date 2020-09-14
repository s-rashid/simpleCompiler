#include <iostream>
#include "integervariable.h"
using namespace std;

IntegerVariable::IntegerVariable(QString n) : Variable (n) {
    this->value = 0;
}

IntegerVariable::~IntegerVariable() {

}

void IntegerVariable::setValue(int v) {
    this->value = v;
}

int IntegerVariable::getValue() {
    if (!this->isDeclared) {
        throw "test_error";
    }
    return this->value;
}

void IntegerVariable::clean() {
    this->isDeclared = false;
    this->value = 0;
}

void IntegerVariable::write(QJsonObject & json) {
    json["type"] = "IntegerVariable";
    json["name"] = this->name;
}

void IntegerVariable::print() {
    cout << this->name.toStdString() << " = ";
    if (!this->isDeclared) {
        cout << "NULL";
    } else {
        cout << to_string(this->value);
    }
    cout << endl;
}
