#ifndef INSTRUCTION_H
#define INSTRUCTION_H

class Program;

#include <QList>
#include <QString>
#include <QJsonObject>
#include <QJsonArray>
#include "operand.h"
#include "label.h"
#include "validoperandtypes.h"
#include "operandfactory.h"
#include "invalidnumoperandsexception.h"

class Instruction {
public:
    virtual ~Instruction();
    virtual int run() = 0;
    void compile(QList<QString>);
    void write(QJsonObject&);
    void setLabel(Label*);
    Label* getLabel();

protected:
    Instruction(Program*, QString, int);
    QString name;
    int numArgs;
    Program* program;
    Label* label;
    QList<Operand*> operands;
    virtual ValidOperandTypes* getOperandTypes() = 0;
    virtual void preCompile(QList<QString>);
};

#endif
