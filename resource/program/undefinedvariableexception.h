#ifndef UNDEFINEDVARIABLEEXCEPTION_H
#define UNDEFINEDVARIABLEEXCEPTION_H

#include <QString>
#include "runtimeexception.h"

class UndefinedVariableException : public RuntimeException {
public:
    UndefinedVariableException(QString&);
    const char* what() const noexcept;

protected:
    QString varName;
};

#endif // UNDEFINEDVARIABLEEXCEPTION_H
