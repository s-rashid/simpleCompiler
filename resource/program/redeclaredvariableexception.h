#ifndef REDECLAREDVARIABLEEXCEPTION_H
#define REDECLAREDVARIABLEEXCEPTION_H

#include <QString>
#include "syntaxexception.h"

class RedeclaredVariableException : public SyntaxException {
public:
    RedeclaredVariableException(QString&);
    const char* what() const noexcept;

protected:
    QString varName;
};

#endif // REDECLAREDVARIABLEEXCEPTION_H
