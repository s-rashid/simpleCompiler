#ifndef RUNPROGCONTROL_H
#define RUNPROGCONTROL_H

#include "savefilecontrol.h"
#include "loadfilecontrol.h"
#include "userdisplayprompt.h"
#include "program/programdeserializer.h"
#include "program/program.h"
#include "program/scapescompiler.h"
#include "program/runtimeexception.h"

class RunProgramControl {
public:
    void launchProgram(UserDisplayPrompt* prompt, QString);
private:
    void deserialize(Program*, QString);
};

#endif // RUNPROGCONTROL_H
