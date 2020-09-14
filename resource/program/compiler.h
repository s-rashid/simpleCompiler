#ifndef COMPLIER_H
#define COMPLIER_H

#include <QString>
#include "program.h"

class Compiler {
public:
    virtual ~Compiler() = default;
    virtual void compile(Program*, QString) = 0;
};

#endif
