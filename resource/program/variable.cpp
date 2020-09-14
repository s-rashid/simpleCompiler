#include "variable.h"

Variable::Variable(QString n) : Identifier (n) {
  isDefined = false;
}

Variable::~Variable() {

}

void Variable::define() {
    isDefined = true;
}
