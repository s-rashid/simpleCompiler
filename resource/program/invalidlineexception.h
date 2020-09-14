#ifndef INVALIDLINEEXCEPTION_H
#define INVALIDLINEEXCEPTION_H

#include "syntaxexception.h"

class InvalidLineException : public SyntaxException {
public:
    InvalidLineException(QString label);
    const char* what() const noexcept;

protected:
    QString label;

};
#endif // INVALIDLINEEXCEPTION_H
