#include "invalidnumoperandsexception.h"

InvalidNumOperandsException::InvalidNumOperandsException(QString instruc, int expected, int received) : SyntaxException () {
    this->instruction = instruc;
    this->numExpected = expected;
    this->numReceived = received;
    QString str = "Invalid number of operands for " + this->instruction + " expected " + QString::number(this->numExpected) +
            " received " + QString::number(this->numReceived);
    baseMsg = str.toStdString();
}

const char* InvalidNumOperandsException::what() const noexcept {
    return msg.c_str();
 }
