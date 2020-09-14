#include "valueoperand.h"

ValueOperand::ValueOperand() : Operand () {}

QString ValueOperand::getStringValue() {
    return QString::number(getValue());
}
