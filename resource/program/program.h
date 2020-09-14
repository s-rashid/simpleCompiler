#ifndef PROGRAM_H
#define PROGRAM_H

class Instruction;

#include <QList>
#include <QLinkedList>
#include <QHash>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include "identifier.h"
#include "label.h"
#include "variable.h"
#include "instruction.h"
#include "programcontext.h"
#include "controller/userdisplayprompt.h"

/**
 * @brief The Program class is a compilied scaple program stored in objects ready to run
 */
class Program {
public:
    Program(const QString);
    ~Program();
    int launch(UserDisplayPrompt*);
    void addInstruction(Instruction*);
    QString getFileName();
    void setFileName(const QString);
    void compile(ProgramContext*);
    void jumpTo(Label* const);
    int getLastCompare();
    void setLastCompare(const int&);
    void read(ProgramContext*);
    void write(QJsonObject&) const;

private:
    QLinkedList<Instruction*>::iterator instructionIterator;
    int lastCompare;
    QString fileName;
    QLinkedList<Instruction*> instructions;
    QHash<QString, Identifier*> variables;
    QHash<Label*, QLinkedList<Instruction*>::iterator> labels;
    int executeInstruction();
    bool addLabelBinding(Label* const, QLinkedList<Instruction*>::iterator);

};

#endif
