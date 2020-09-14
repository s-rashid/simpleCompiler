#ifndef SYNTAXEXCEPTION_H
#define SYNTAXEXCEPTION_H

#include <exception>
#include <QString>

class SyntaxException : public std::exception {
public:
    void setLineNumber(int);
    void setLine(QString&);
    virtual const char* what() const noexcept = 0;

protected:
    SyntaxException();
    int lineNum;
    QString line;
};

#endif // SYNTAXEXCEPTION_H
