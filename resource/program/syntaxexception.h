#ifndef SYNTAXEXCEPTION_H
#define SYNTAXEXCEPTION_H

#include <exception>
#include <QString>

class SyntaxException : public std::exception {
public:
    void setLineNumber(int);
    void setLine(QString&);
    void process();
    virtual const char* what() const noexcept = 0;

protected:
    SyntaxException();
    int lineNum;
    QString line;
    std::string baseMsg;
    std::string msg;
    const QByteArray* bytes;
};

#endif // SYNTAXEXCEPTION_H
