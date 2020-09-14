#include "syntaxexception.h"

SyntaxException::SyntaxException() : std::exception () {
    lineNum = -1;
    line = "Unknown";
}

void SyntaxException::setLine(QString& l) {
    line = l;
}

void SyntaxException::setLineNumber(int i) {
    lineNum = i;
}
