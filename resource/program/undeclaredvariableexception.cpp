#include "undeclaredvariableexception.h"
/**
 * @brief UndeclaredVariableException::UndeclaredVariableException
 * @param op, name of undeclared variable
 */
UndeclaredVariableException::UndeclaredVariableException(QString& op) : SyntaxException () {
    varName = op;
    QString str = "Undeclared variable \"" + varName + "\"";
    baseMsg = str.toStdString();
}

const char* UndeclaredVariableException::what() const noexcept {
    return msg.c_str();
}
