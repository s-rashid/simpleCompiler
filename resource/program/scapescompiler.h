#ifndef SCAPESCOMPLIER_H
#define SCAPESCOMPLIER_H

#include <QString>
#include "compiler.h"
#include "program.h"
#include "instructionfactory.h"

using namespace std;

class ScapesCompiler : public Compiler{

public:
    void compile(Program*, QString);

};

#endif
