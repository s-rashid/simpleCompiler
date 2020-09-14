#ifndef INSTRUCTIONFACTORY_H
#define INSTRUCTIONFACTORY_H

#include <QString>
#include "instruction.h"
#include "program.h"
#include "unsupportinstructionexception.h"
#include "endinstruction.h"
#include "declareintegerinstruction.h"
#include "declarearrayinstruction.h"
#include "readintegerinstruction.h"
#include "printinstruction.h"
#include "compareinstruction.h"
#include "addinstruction.h"
#include "moveinstruction.h"
#include "jumpinstruction.h"
#include "jumpmoreinstruction.h"
#include "jumplessinstruction.h"
#include "jumpequalinstruction.h"

class InstructionFactory {
public:
    Instruction* createInstruction(Program*, QString, bool isClassName = true);
private:
    void convertToClassName(QString&);
};

#endif // INSTRUCTIONFACTORY_H
