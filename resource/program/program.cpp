#include <iostream>
#include <QDebug>
#include "program.h"
/**
 * @brief Program::Program
 * @param fileName
 */
Program::Program(const QString fileName) {
    this->fileName = fileName;
}

Program::~Program() {
    qDeleteAll(instructions);
    instructions.clear();

    qDeleteAll(variables);
    variables.clear();
}

void Program::addInstruction(Instruction* instruction) {
    QLinkedList<Instruction*>::iterator link = instructions.insert(instructions.end(), instruction);
    Label* label = instruction->getLabel();
    if (label != nullptr) {
        addLabelBinding(label, link);
    }
}

bool Program::addLabelBinding(Label* const key, QLinkedList<Instruction*>::iterator value) {
    if (labels.contains(key)) {
        return false;
    }
    labels.insert(key, value);
    return true;
}

void Program::jumpTo(Label* const key) {
    instructionIterator = labels.value(key, nullptr);
}

int Program::getLastCompare() {
    return lastCompare;
}

void Program::setLastCompare(const int & value) {
    lastCompare = value;
}

QString Program::getFileName() {
    return fileName;
}

void Program::setFileName(const QString fileName) {
    this->fileName = fileName;
}

int Program::launch(UserDisplayPrompt* prompt) {
    int exitCode = 0;
    QString errorMessage = "default_error";

    std::cout << "Starting program..." << std::endl;

    instructionIterator = instructions.begin();

    while (instructionIterator != instructions.end() && exitCode == 0) {
        Instruction** instruct = (instructionIterator++).operator->();
        //std::cout << "Running instructing: " << (*instruct)->to_string().toStdString() << std::endl;
        exitCode = (*instruct)->run(prompt);
    }

    std::cout << std::endl;
    if (exitCode == 1) {
        std::cout << "Ending program normally" << std::endl;
        prompt->printToDisplay("\nEnding program normally");
    } else if (exitCode == 0) {
        std::cout << "Unexpected end of program: " << errorMessage.toStdString() << std::endl;
        prompt->printToDisplay("\nUnexpected end of program");
    } else if (exitCode == 2) {
        std::cout << "User canceled program" << std::endl;
        prompt->printToDisplay("\nUser canceled program");
    }

    std::cout << std::endl << std::endl;

    return exitCode;
}

void Program::compile(ProgramContext* context) {
    QHashIterator<QString, Identifier*> i(context->getIdentifiers());
    while(i.hasNext()){
        i.next();
        variables.insert(i.key(),i.value());
    }
}
void Program::read(ProgramContext* context){
    this->variables = context->getIdentifiers();
}
void Program::write(QJsonObject& json) const {
    QJsonArray instructionsJson;
    QJsonArray variablesJson;

    QHashIterator<QString, Identifier*> i(variables);
    while(i.hasNext()){
        i.next();
        QJsonObject variableJson;
        //identifier writes to the object
        i.value()->write(variableJson);
        variableJson["name"] = i.key();
        variablesJson.append(variableJson);
    }

    foreach(Instruction *instruction, instructions){

        QJsonObject instructionJson;
        instruction->write(instructionJson);
        instructionsJson.append(instructionJson);
    }
    json["instructions"] = instructionsJson;
    json["identifiers"] = variablesJson;
}
