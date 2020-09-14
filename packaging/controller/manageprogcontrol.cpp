#include "manageprogcontrol.h"

void ManageProgramControl::saveFile(QString& fileName, QString& dir, QString& fileContents) {
    SaveFileControl fc;
    fc.saveProgram(fileName, dir, fileContents);
}

void ManageProgramControl::compileProgram(DisplayErrorPrompt* prompt, QString& source, QString& fileName) {
    CompilerProgramControl cc;
    cc.compileProgram(prompt, source, fileName);
}

void ManageProgramControl::runProgram() {
    RunProgramControl rc;
    rc.launchProgram();
}

void ManageProgramControl::exitProgram() {
    ExitControl ec;
    ec.cleanUp();
}

