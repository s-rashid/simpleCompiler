#ifndef UNSUPPORTEDOPERANDEXCEPTION_H
#define UNSUPPORTEDOPERANDEXCEPTION_H

#include <QString>
#include "syntaxexception.h"

class UnsupportedOperandException : public SyntaxException {
public:
    UnsupportedOperandException(QString&);
    const char* what() const noexcept;

protected:
    QString operand;
};

#endif // UNSUPPORTEDOPERANDEXCEPTION_H
