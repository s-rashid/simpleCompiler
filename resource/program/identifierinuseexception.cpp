#include "identifierinuseexception.h"

IdentifierInUseException::IdentifierInUseException(QString& n) : SyntaxException () {
    this->name = n;
    QString str = "Name \"" + this->name + "\" is already in use";
    baseMsg = str.toStdString();
}

const char* IdentifierInUseException::what() const noexcept {
    return msg.c_str();
}
