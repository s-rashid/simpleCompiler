#include "programdeserializer.h"

void ProgramDeserializer::deserialize(Program* program, const QJsonObject& json){
    ProgramContext* context = new ProgramContext();
    IdentifierFactory identifierFactory;
    InstructionFactory instructionFactory;
    QJsonArray instructionsJson = json["instructions"].toArray();
    QJsonArray identifiersJson = json["identifiers"].toArray();

    //create identifiers from json
    foreach (QJsonValue identifierValue, identifiersJson){
        QJsonObject identifierJson = identifierValue.toObject();
        QString type = identifierJson["type"].toString();
        Identifier* iden = identifierFactory.createIdentifier(type);
        iden->read(identifierJson);
        context->addIdentifier(identifierJson["name"].toString(), iden);
    }
    //create instructions from json
    foreach (QJsonValue instructionValue, instructionsJson){

        QJsonObject instructionJson = instructionValue.toObject();
        QString type = instructionJson["type"].toString();

        Instruction* instruction = instructionFactory.createInstruction(program, type);
        instruction->read(instructionJson, context);
        program->addInstruction(instruction);
    }

    program->read(context);
}
