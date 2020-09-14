#include "syntaxexception.h"

SyntaxException::SyntaxException() : std::exception () {
    lineNum = -1;
    line = "Unknown";
    baseMsg = "Unexpected Error";
    msg = baseMsg;
}

void SyntaxException::setLine(QString& l) {
    line = l;
}

void SyntaxException::setLineNumber(int i) {
    lineNum = i;
}

void SyntaxException::process() {
    QString str = " found at line " + QString::number(lineNum) + ": " + line;
    msg = baseMsg + str.toStdString();
}
