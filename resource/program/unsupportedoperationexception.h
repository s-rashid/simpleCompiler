#ifndef UNSUPPORTEDOPERATIONEXCEPTION_H
#define UNSUPPORTEDOPERATIONEXCEPTION_H

#include <QString>
#include "runtimeexception.h"

class UnsupportedOperationException : public RuntimeException
{
public:
    UnsupportedOperationException();
    const char* what() const noexcept;

protected:
    QString operand;
};



#endif // UNSUPPORTEDOPERATIONEXCEPTION_H
