#ifndef RUNTIMEEXCEPTION_H
#define RUNTIMEEXCEPTION_H

#include <exception>
#include <QString>

class RuntimeException : public std::exception {
public:
    virtual const char* what() const noexcept = 0;

protected:
    std::string msg;
    RuntimeException();
};

#endif // RUNTIMEEXCEPTION_H
