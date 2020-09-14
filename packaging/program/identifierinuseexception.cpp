#include "identifierinuseexception.h"

IdentifierInUseException::IdentifierInUseException(QString& n) : SyntaxException () {
    this->name = n;
}

const char* IdentifierInUseException::what() const noexcept {
    QString str = "Name \"" + this->name + "\" is already in use found at line " + QString::number(this->lineNum) + ": " + this->line;
    QByteArray bytes = str.toLocal8Bit();
    return bytes.data();
}
