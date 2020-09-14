#ifndef IDENTIFIERINUSEEXCEPTION_H
#define IDENTIFIERINUSEEXCEPTION_H

#include <QString>
#include "syntaxexception.h"

class IdentifierInUseException : public SyntaxException {
public:
    IdentifierInUseException(QString&);
    const char* what() const noexcept;

protected:
    QString name;
};

#endif // IDENTIFIERINUSEEXCEPTION_H
