#include <iostream>
#include <iomanip>

#include "identifier.h"

Identifier::Identifier(QString n) {
  name = n;
}

Identifier::~Identifier() {

}

void Identifier::print() {
  std::cout << name.toStdString() << std::endl;
}

void Identifier::clean() {}
