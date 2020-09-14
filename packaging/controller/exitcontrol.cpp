#include "exitcontrol.h"

void ExitControl::cleanUp() {
    // TODO make sure this is call for every exit
    DevEnv *devEnv = DevEnv::getInstance();
    delete devEnv;
}
