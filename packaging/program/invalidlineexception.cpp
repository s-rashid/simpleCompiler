#include "invalidlineexception.h"

InvalidLineException::InvalidLineException(QString label) : SyntaxException() {
    this->label = label;
}

const char* InvalidLineException::what() const noexcept {
    QString str = "Label \"" + this->label + "\" on line " + QString::number(this->lineNum) + " has no instruction";
    QByteArray bytes = str.toLocal8Bit();
    return bytes.data();
}
