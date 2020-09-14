#ifndef PROGRAMCONTEXT_H
#define PROGRAMCONTEXT_H

#include <QList>
#include <QHash>
#include "identifier.h"

class ProgramContext {
public:
    ProgramContext();
    Identifier* getIdentifier(const QString&);
    QHash<QString, Identifier*> getIdentifiers();
    bool addIdentifier(const QString, Identifier*);

private:
    QHash<QString, Identifier*> variables;
};

#endif // PROGRAMCONTEXT_H
