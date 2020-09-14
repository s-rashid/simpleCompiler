#ifndef INSTRUCTIONFACTORY_H
#define INSTRUCTIONFACTORY_H

#include <QString>
#include "instruction.h"
#include "program.h"
#include "unsupportinstructionexception.h"
#include "endinstruction.h"
#include "declareintegerinstruction.h"
#include "readintegerinstruction.h"
#include "printinstruction.h"
#include "compareinstruction.h"
#include "jumpinstruction.h"
#include "jumpmoreinstruction.h"

class InstructionFactory {
public:
    Instruction* createInstruction(Program*, QString);

};

#endif // INSTRUCTIONFACTORY_H
