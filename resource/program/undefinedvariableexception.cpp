#include "undefinedvariableexception.h"

UndefinedVariableException::UndefinedVariableException(QString& name) : RuntimeException() {
    this->varName = name;
    QString str = "UndefinedVariableException: accessing undefined variable \"" + varName + "\"";
    msg = str.toStdString();
}

const char* UndefinedVariableException::what() const noexcept {
    return msg.c_str();
}
