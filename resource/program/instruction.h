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
#include "programcontext.h"
#include "invalidnumoperandsexception.h"
#include "basicoperandfactory.h"
#include "controller/userdisplayprompt.h"

class Instruction {
public:
    virtual ~Instruction();
    virtual int run(UserDisplayPrompt*) = 0;
    QString to_string();
    void compile(ProgramContext*, QList<QString>);
    void read(const QJsonObject&, ProgramContext*);
    void write(QJsonObject&);
    virtual void setLabel(Label*);
    Label* getLabel();
    void addOperand(Operand*);

protected:
    Instruction(Program*, QString, int);
    QString name;
    int numArgs;
    Program* program;
    Label* label;
    QList<Operand*> operands;
    virtual ValidOperandTypes* getOperandTypes(int) = 0;
    virtual void preCompile(ProgramContext*, QList<QString>);
};

#endif
