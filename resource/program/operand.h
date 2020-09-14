#ifndef OPERAND_H
#define OPERAND_H

#include <QString>
#include <QJsonObject>
#include "identifier.h"
#include "programcontext.h"

class Operand {
public:
    Operand();
    virtual ~Operand();
    virtual void write(QJsonObject&) = 0;
    virtual void read(const QJsonObject&, ProgramContext*) = 0;

};

#endif // OPERAND_H
