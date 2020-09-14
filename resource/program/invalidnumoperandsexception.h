#ifndef INVALIDNUMOPERANDSEXCEPTION_H
#define INVALIDNUMOPERANDSEXCEPTION_H

#include <QString>
#include "syntaxexception.h"

class InvalidNumOperandsException : public SyntaxException {
public:
    InvalidNumOperandsException(QString, int, int);
    const char* what() const noexcept;

protected:
    QString instruction;
    int numExpected;
    int numReceived;
};

#endif // INVALIDNUMOPERANDSEXCEPTION_H
