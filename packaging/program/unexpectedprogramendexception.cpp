#include "unexpectedprogramendexception.h"

UnexpectedProgramEndException::UnexpectedProgramEndException() {

}
/**
 * @brief UnexpectedProgramEndException::what creates and error messege for unexpected end instruciton
 * @return an error messege based on the stateof the object
 */
const char* UnexpectedProgramEndException::what() const noexcept {
    QString str = "Unexpected end of program found at line " + QString::number(lineNum) + ": " + line;
    QByteArray bytes = str.toLocal8Bit();
    return bytes.data();
}
