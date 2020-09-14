#ifndef UNSUPPORTINSTRUCTIONEXCEPTION_H
#define UNSUPPORTINSTRUCTIONEXCEPTION_H

#include <QString>
#include "syntaxexception.h"

class UnsupportInstructionException : public SyntaxException {
public:
    UnsupportInstructionException(QString&);
    const char* what() const noexcept;

protected:
    QString instruction;
};


#endif // UNSUPPORTINSTRUCTIONEXCEPTION_H
