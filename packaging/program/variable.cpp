#include "variable.h"

Variable::Variable(QString n) : Identifier (n) {
  isDeclared = false;
}

Variable::~Variable() {

}

void Variable::declare() {
    isDeclared = true;
}
