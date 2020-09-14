#ifndef MANAGEPROGCONTROL_H
#define MANAGEPROGCONTROL_H

#include "savefilecontrol.h"
#include "compileprogcontrol.h"
#include "loadfilecontrol.h"
#include "runprogcontrol.h"
#include "userdisplayprompt.h"

class MainWindow;

class ManageProgramControl {

public:
    void saveFile(QString&, QString&, QString&);
    void compileProgram(UserDisplayPrompt*, QString&, QString&);
    void runProgram(UserDisplayPrompt*, QString&);
    void loadProgram(QString&, QString&);

};

#endif // MANAGEPROGCONTROL_H
