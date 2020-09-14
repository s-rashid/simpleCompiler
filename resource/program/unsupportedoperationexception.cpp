#include "unsupportedoperationexception.h"

UnsupportedOperationException::UnsupportedOperationException() : RuntimeException() {
    QString str = "Unsupported operation exception";
    msg = str.toStdString();
}

const char* UnsupportedOperationException::what() const noexcept {
    return msg.c_str();
}
