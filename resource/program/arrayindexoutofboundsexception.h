#ifndef ARRAYINDEXOUTOFBOUNDSEXCEPTION_H
#define ARRAYINDEXOUTOFBOUNDSEXCEPTION_H

#include <QString>
#include "runtimeexception.h"

class ArrayIndexOutOfBoundsException : public RuntimeException
{
public:
    ArrayIndexOutOfBoundsException(int&, int&, QString&);
    const char* what() const noexcept;

private:
    int index, size;

protected:
    QString varName;

};

#endif // ARRAYINDEXOUTOFBOUNDSEXCEPTION_H
