#include "manageprogcontrol.h"

void ManageProgramControl::saveFile(QString& fileName, QString& dir, QString& fileContents) {
    SaveFileControl fc;
    fc.saveProgram(fileName, dir, fileContents);
}

void ManageProgramControl::compileProgram(UserDisplayPrompt* prompt, QString& source, QString& fileName) {
    CompilerProgramControl cc;
    cc.compileProgram(prompt, source, fileName);
}

void ManageProgramControl::runProgram(UserDisplayPrompt* prompt, QString& fileName) {
    RunProgramControl rc;
    rc.launchProgram(prompt, fileName);
}

void ManageProgramControl::loadProgram(QString& source, QString& fileName) {
    LoadFileControl lc;
    lc.loadProgram(fileName, source);
}
