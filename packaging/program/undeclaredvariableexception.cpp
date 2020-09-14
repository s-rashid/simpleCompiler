#include "undeclaredvariableexception.h"
/**
 * @brief UndeclaredVariableException::UndeclaredVariableException
 * @param op, name of undeclared variable
 */
UndeclaredVariableException::UndeclaredVariableException(QString& op) : SyntaxException () {
    varName = op;
}

const char* UndeclaredVariableException::what() const noexcept {
    QString str = "Undeclared variable \"" + varName + "\" found at line " + QString::number(lineNum) + ": " + line;
    QByteArray bytes = str.toLocal8Bit();
    return bytes.data();
}
