#include <iostream>
#include <iomanip>

#include "identifier.h"

Identifier::Identifier(QString n) {
  name = n;
}

Identifier::~Identifier() {

}

QString Identifier::getName(){
    return this->name;
}

void Identifier::print() {
  std::cout << name.toStdString() << std::endl;
}
