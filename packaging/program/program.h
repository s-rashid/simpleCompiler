#ifndef PROGRAM_H
#define PROGRAM_H

class Instruction;

#include <QList>
#include <QHash>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include "identifier.h"
#include "label.h"
#include "variable.h"
#include "instruction.h"
#include "unexpectedprogramendexception.h"
/**
 * @brief The Program class is a compilied scapl program stored in objects ready to run
 */
class Program {
public:
    Program(const QString);
    ~Program();
    int launch();
    int addInstruction(Instruction*);
    Identifier* getIdentifier(const QString&);
    bool addIdentifier(const QString, Identifier*);
    int getLastCompare();
    void setLastCompare(const int&);
    void setCurrentLine(const int&);
    QString getFileName();
    void setFileName(const QString);
    //void read(const QJsonObject&);
    void write(QJsonObject&) const;

private:
    int currentLine;
    int lastCompare;
    QString fileName;
    QList<Instruction*> instructions;
    QHash<QString, Identifier*> variables;
    int executeLine();

};

#endif
