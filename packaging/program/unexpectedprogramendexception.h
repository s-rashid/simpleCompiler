#ifndef UNEXPECTEDPROGRAMENDEXCEPTION_H
#define UNEXPECTEDPROGRAMENDEXCEPTION_H

#include <QString>
#include "syntaxexception.h"

class UnexpectedProgramEndException : public SyntaxException {
public:
    UnexpectedProgramEndException();
    const char* what() const noexcept;

};

#endif // UNEXPECTEDPROGRAMENDEXCEPTION_H
