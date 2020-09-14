#ifndef IDENTIFIERFACTORY_H
#define IDENTIFIERFACTORY_H

#include "label.h"
#include "integervariable.h"
#include "arrayvariable.h"

class IdentifierFactory
{
public:
    Identifier* createIdentifier(QString);
};

#endif // IDENTIFIERFACTORY_H
