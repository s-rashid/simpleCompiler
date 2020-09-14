#include "unsupportinstructionexception.h"

/**
 * @brief UnsupportInstructionException::UnsupportInstructionException error when upsupported instruction
 * @param instruc, name of invalid instruction
 */
UnsupportInstructionException::UnsupportInstructionException(QString& instruc) : SyntaxException() {
    instruction = instruc;
    QString str = "Unsupport Instruction \"" + instruction + "\"";
    baseMsg = str.toStdString();
}

/**
 * @brief UnsupportInstructionException::what creates an error messege for an unsupported operand based on the current state of the object
 * @return an error message
 */
const char* UnsupportInstructionException::what() const noexcept {
    return msg.c_str();
}
