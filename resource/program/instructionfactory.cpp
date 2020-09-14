#include "instructionfactory.h"

Instruction* InstructionFactory::createInstruction(Program* program, QString type, bool isClassName) {

    if (!isClassName) convertToClassName(type);

    if (QString::compare(type, "EndInstruction") == 0) {
        return new EndInstruction(program);
    } else if (QString::compare(type, "DeclareIntegerInstruction") == 0){
        return new DeclareIntegerInstruction(program);
    } else if (QString::compare(type, "ReadIntegerInstruction") == 0){
        return new ReadIntegerInstruction(program);
    } else if (QString::compare(type, "DeclareArrayInstruction") == 0){
        return new DeclareArrayInstruction(program);
    } else if (QString::compare(type, "PrintInstruction") == 0){
        return new PrintInstruction(program);
    } else if (QString::compare(type, "CompareInstruction") == 0){
        return new CompareInstruction(program);
    } else if (QString::compare(type, "AddInstruction") == 0){
        return new AddInstruction(program);
    } else if (QString::compare(type, "MoveInstruction") == 0){
        return new MoveInstruction(program);
    } else if (QString::compare(type, "JumpInstruction") == 0){
        return new JumpInstruction(program);
    } else if (QString::compare(type, "JumpMoreInstruction") == 0){
        return new JumpMoreInstruction(program);
    } else if (QString::compare(type, "JumpLessInstruction") == 0){
        return new JumpLessInstruction(program);
    } else if (QString::compare(type, "JumpEqualInstruction") == 0){
        return new JumpEqualInstruction(program);
    }
    throw UnsupportInstructionException(type);
}

void InstructionFactory::convertToClassName(QString& type){
    QHash<QString, QString> types;
    types["end"] = "EndInstruction";
    types["dci"] = "DeclareIntegerInstruction";
    types["dca"] = "DeclareArrayInstruction";
    types["rdi"] = "ReadIntegerInstruction";
    types["prt"] = "PrintInstruction";
    types["cmp"] = "CompareInstruction";
    types["add"] = "AddInstruction";
    types["mov"] = "MoveInstruction";
    types["jmp"] = "JumpInstruction";
    types["jmr"] = "JumpMoreInstruction";
    types["jls"] = "JumpLessInstruction";
    types["jeq"] = "JumpEqualInstruction";

    if (types.contains(type)) {
        type = types[type];
    } else {
        throw UnsupportInstructionException(type);
    }
}
