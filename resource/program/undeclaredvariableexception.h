#ifndef UNDECLAREDVARIABLEEXCEPTION_H
#define UNDECLAREDVARIABLEEXCEPTION_H

#include <QString>
#include "syntaxexception.h"

class UndeclaredVariableException : public SyntaxException {
public:
    UndeclaredVariableException(QString&);
    const char* what() const noexcept;

protected:
    QString varName;
};

#endif // UNDECLAREDVARIABLEEXCEPTION_H
