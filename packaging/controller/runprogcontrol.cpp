#include "runprogcontrol.h"

void RunProgramControl::launchProgram () {

    DevEnv *devEnv = DevEnv::getInstance();
    Program *program = devEnv->getProgram();

    program->launch();
}
