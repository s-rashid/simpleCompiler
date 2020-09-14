#include "arrayindexoutofboundsexception.h"

ArrayIndexOutOfBoundsException::ArrayIndexOutOfBoundsException(int& initIndex, int& initSize, QString& initVarName) : RuntimeException(){
    index = initIndex;
    size = initSize;
    varName = initVarName;
    QString str = "Array Index Out of Bounds Exception: \"" + varName + "\" of size " + QString::number(size) + " at index " + QString::number(index);
    msg = str.toStdString();
}

const char* ArrayIndexOutOfBoundsException::what() const noexcept {
    return msg.c_str();
}
