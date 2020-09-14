#include "unsupportinstructionexception.h"

/**
 * @brief UnsupportInstructionException::UnsupportInstructionException error when upsupported instruction
 * @param instruc, name of invalid instruction
 */
UnsupportInstructionException::UnsupportInstructionException(QString& instruc) : SyntaxException() {
    instruction = instruc;
}

/**
 * @brief UnsupportInstructionException::what creates an error messege for an unsupported operand based on the current state of the object
 * @return an error messege
 */
const char* UnsupportInstructionException::what() const noexcept {
    QString str = "Unsupport Instruction \"" + instruction + "\" found at line " + QString::number(lineNum) + ": " + line;
    QByteArray bytes = str.toLocal8Bit();
    return bytes.data();
}
