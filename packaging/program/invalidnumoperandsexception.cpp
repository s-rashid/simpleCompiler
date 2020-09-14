#include "invalidnumoperandsexception.h"

InvalidNumOperandsException::InvalidNumOperandsException(QString instruc, int expected, int received) : SyntaxException () {
    this->instruction = instruc;
    this->numExpected = expected;
    this->numReceived = received;
}

const char* InvalidNumOperandsException::what() const noexcept {
    QString str = "Invalid number of operands for " + this->instruction + " expected " + QString::number(this->numExpected) +
                  " received " + QString::number(this->numReceived)+ " found at line " + QString::number(this->lineNum) + ": " + this->line;
    QByteArray bytes = str.toLocal8Bit();
    return bytes.data();
 }
