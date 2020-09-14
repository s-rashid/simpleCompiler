#include "arrayvariable.h"
#include <iostream>

ArrayVariable::ArrayVariable(QString n) : Variable (n) {}
ArrayVariable::ArrayVariable(QString n, int size) : Variable (n) {
    this->size = size;
    this->initElements();
}
ArrayVariable::~ArrayVariable() {
    for (int i = 0; i < size; i++) {
        delete elements[i];
    }
    delete elements;
}

void ArrayVariable::initElements(){
    elements = new Variable *[size];
    for (int i = 0; i < size; i++) {
        QString arrVar = "arrElem@" + QString::number(i);
        elements[i] = new IntegerVariable(arrVar);
    }
}
void ArrayVariable::setArrayValue(int index, int value) {
    get(index)->setValue(value);
}

void ArrayVariable::setValue(int) {
    throw UnsupportedOperationException();
}

int ArrayVariable::getValue() {
    throw UnsupportedOperationException();
}

int ArrayVariable::getArrayValue(int index) {
    return get(index)->getValue();
}

Variable* ArrayVariable::get(int index) {
    if (index >= size) {
        throw ArrayIndexOutOfBoundsException(index, size, name);
    }
    return elements[index];
}

void ArrayVariable::read(const QJsonObject& json){
    this->name = json["name"].toString();
    this->size = json["size"].toInt();
    this->initElements();
}

void ArrayVariable::write(QJsonObject & json) {
    json["type"] = "ArrayVariable";
    json["name"] = this->name;
    json["size"] = this->size;
}

void ArrayVariable::print() {
    cout << this->name.toStdString() << " = ";
    if (!this->isDefined) {
        cout << "NULL";
    } else {
        cout << to_string(this->size);
    }
    cout << endl;
}
