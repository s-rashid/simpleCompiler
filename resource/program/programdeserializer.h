#ifndef PROGRAMDESERIALIZER_H
#define PROGRAMDESERIALIZER_H

#include "QDebug"
#include "program.h"
#include "instructionfactory.h"
#include "identifierfactory.h"

class ProgramDeserializer
{
public:
    void deserialize(Program*, const QJsonObject&);
};

#endif // PROGRAMDESERIALIZER_H
