#ifndef DevEnv_H
#define DevEnv_H

#include <QString>
#include "program.h"

class DevEnv {
private:
    static DevEnv* instance;
    QString fileName;
    QString source;
    Program* currentProgram;

public:
    ~DevEnv();
    static DevEnv* getInstance();
    QString getFileName() { return this->fileName ;}
    QString getSource() { return this->fileName; }
    Program* getProgram() { return this->currentProgram; }
    void setFilename(QString fileName) { this->fileName = fileName; }
    void setSource(QString source) { this->source = source; }
    void setProgram(Program* program);

};

#endif // DEVENV_H
