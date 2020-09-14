#include "redeclaredvariableexception.h"

RedeclaredVariableException::RedeclaredVariableException(QString& op) : SyntaxException () {
    varName = op;
    QString str = "Cannot redeclare variable \"" + varName + "\"";
    baseMsg = str.toStdString();
}

const char* RedeclaredVariableException::what() const noexcept {
    return msg.c_str();
}
