#include "invalidlineexception.h"

InvalidLineException::InvalidLineException(QString label) : SyntaxException() {
    this->label = label;
    QString str =  "Invalid Line";
    baseMsg = str.toStdString();
}

const char* InvalidLineException::what() const noexcept {
    return msg.c_str();
}
