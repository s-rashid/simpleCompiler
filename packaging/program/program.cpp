#include <iostream>

#include "program.h"

Program::Program(const QString fileName) {
    this->fileName = fileName;
}

Program::~Program() {
    qDeleteAll(instructions);
    instructions.clear();

    qDeleteAll(variables);
    variables.clear();
}

int Program::addInstruction(Instruction* instruction) {
    instructions.append(instruction);
    return instructions.size() - 1;
}

Identifier* Program::getIdentifier(const QString& key) {
    return variables.value(key, nullptr);
}

bool Program::addIdentifier(const QString key, Identifier* value) {
    if (variables.contains(key)) {
        return false;
    }
    variables.insert(key, value);
    return true;
}

int Program::getLastCompare() {
    return lastCompare;
}

void Program::setLastCompare(const int & value) {
    lastCompare = value;
}

void Program::setCurrentLine(const int & value) {
    std::cout << "Jumping from line " << currentLine << " to " << value << std::endl;
    currentLine = value;
}

QString Program::getFileName() {
    return fileName;
}

void Program::setFileName(const QString fileName) {
    this->fileName = fileName;
}

int Program::launch() {
    int exitCode = 0;
    currentLine = 0;
    QString errorMessage = "default_error";

    std::cout << "Starting program..." << std::endl;
    // TODO should the program break without a EndInstruction?

    while (exitCode == 0) {
        exitCode = executeLine();
    }

    std::cout << std::endl;
    if (exitCode == 1) {
        std::cout << "Ending program normally" << std::endl;
    } else if (exitCode == 2) {
        std::cout << "Ending program with error message: " << errorMessage.toStdString() << " at line " << currentLine << std::endl;
    }

    std::cout << std::endl << std::endl;

    QHashIterator<QString, Identifier*> i(variables);
    while(i.hasNext()){
        i.next();
        i.value()->clean();
    }

    return exitCode;
}

int Program::executeLine() {
    if (0 > currentLine || currentLine >= instructions.size()) {
        throw UnexpectedProgramEndException();
    }
    return instructions[currentLine++]->run();
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
    json["variables"] = variablesJson;
}
