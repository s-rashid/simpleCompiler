#ifndef INTEGERVARIABLE_H
#define INTEGERVARIABLE_H

#include <QString>
#include "variable.h"
#include "identifier.h"
#include "undefinedvariableexception.h"

#define VARIABLE_TAG "var"

class IntegerVariable : public Variable {
public:
    IntegerVariable(QString);
    ~IntegerVariable();
    void setValue(int);
    int getValue();
    void print();
    void read(const QJsonObject&);
    void write(QJsonObject&);

protected:
    int value;
};

#endif // INTEGERVARIABLE_H
