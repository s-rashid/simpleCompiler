#ifndef COMPILEPROGCONTROL_H
#define COMPILEPROGCONTROL_H

#include "savefilecontrol.h"
#include "displayerrorprompt.h"
#include "program/devenv.h"
#include "program/program.h"
#include "program/scapescompiler.h"

class CompilerProgramControl {
public:
    void compileProgram(DisplayErrorPrompt* prompt, QString&, QString&);
private:
    void serialize(Program *program, QString);
};
#endif // COMPILEPROGCONTROL_H
