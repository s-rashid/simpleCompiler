#ifndef VARIABLE_H
#define VARIABLE_H

#include <QString>
#include "identifier.h"

class Variable : public Identifier {
public:
    ~Variable();
    void declare();
    virtual void setValue(int) = 0;
    virtual int getValue() = 0;
    virtual void print() = 0;
    virtual void clean() = 0;
    virtual void write(QJsonObject&) = 0;

protected:
    Variable(QString);
    bool isDeclared;
};

#endif
