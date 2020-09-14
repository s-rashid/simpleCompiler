#ifndef MANAGEPROGCONTROL_H
#define MANAGEPROGCONTROL_H

#include "savefilecontrol.h"
#include "compileprogcontrol.h"
#include "runprogcontrol.h"
#include "exitcontrol.h"
#include "displayerrorprompt.h"

class MainWindow;

class ManageProgramControl{

public:
    void saveFile(QString&, QString&, QString&);
    void compileProgram(DisplayErrorPrompt*, QString&, QString&);
    void runProgram();
    void exitProgram();

};

#endif // MANAGEPROGCONTROL_H
