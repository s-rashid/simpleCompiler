#include "unsupportedoperandexception.h"
/**
 * @brief UnsupportedOperandException::UnsupportedOperandException
 * @param op, operand text to provide error info to user
 */
UnsupportedOperandException::UnsupportedOperandException(QString& op) : SyntaxException () {
    operand = op;
}
/**
 * @brief UnsupportedOperandException::what creates an error messege for an unsupported operand based on the current state of the object
 * @return an error messege
 */
const char* UnsupportedOperandException::what() const noexcept {
    QString str = "Unsupport Operand \"" + operand + "\" found at line " + QString::number(lineNum) + ": " + line;
    QByteArray bytes = str.toLocal8Bit();
    return bytes.data();
}
