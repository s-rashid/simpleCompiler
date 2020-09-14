#include "runprogcontrol.h"
#include <QDebug>

void RunProgramControl::launchProgram (UserDisplayPrompt* prompt, QString name) {
    Program* program = new Program(name);
    try {
        deserialize(program, name);
    } catch(...) {
        prompt->displayRuntimeError("Invalid program file: " + name);
        delete program;
        return;
    }

    try {
        program->launch(prompt);
    } catch(RuntimeException& e) {
        QString msg = QString::fromLocal8Bit(e.what());
        prompt->displayRuntimeError(msg);
        delete program;
        return;
    }
}

void RunProgramControl::deserialize(Program* program, QString name){

    QString jsonString;
    if (!name.endsWith(".json")) {
        name = name.split(".")[0];
        name = name.append(".json");
    }
    LoadFileControl sm;
    sm.loadProgram(name, jsonString);
    if (jsonString.isEmpty()) {
        throw "invalid_file";
    }

    QJsonDocument doc = QJsonDocument::fromJson(jsonString.toUtf8());
    QJsonObject json = doc.object();
    if (json.size() == 0) {
        throw "invalid json";
    }
    qDebug() << "deserializing: " << name;
    ProgramDeserializer pd;
    pd.deserialize(program, json);

}
