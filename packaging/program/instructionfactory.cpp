#include <iostream>

#include "instructionfactory.h"

//NOTE added type to the constructors for json writing
//could just use hardcoded QString("type") in each specific instruction?
//-cam
Instruction* InstructionFactory::createInstruction(Program* program, QString type) {
    if (QString::compare(type, "end") == 0) {
        return new EndInstruction(program);
    } else if (QString::compare(type, "dci") == 0){
        return new DeclareIntegerInstruction(program);
    } else if (QString::compare(type, "rdi") == 0){
        return new ReadIntegerInstruction(program);
    } else if (QString::compare(type, "prt") == 0){
        return new PrintInstruction(program);
    } else if (QString::compare(type, "cmp") == 0){
        return new CompareInstruction(program);
    } else if (QString::compare(type, "jmp") == 0){
        return new JumpInstruction(program);
    } else if (QString::compare(type, "jmr") == 0){
        return new JumpMoreInstruction(program);
    }
    throw UnsupportInstructionException(type);
}
