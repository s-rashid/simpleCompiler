#ifndef OPERAND_H
#define OPERAND_H

#include <QString>
#include <QJsonObject>
#include "identifier.h"

class Operand {
public:
    Operand();
    virtual ~Operand();
    virtual void write(QJsonObject&) = 0;

};

#endif // OPERAND_H
