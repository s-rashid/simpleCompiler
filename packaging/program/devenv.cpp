#include "devenv.h"
#include <iostream>

//DevEnv::instance singleton refernce
DevEnv* DevEnv::instance = nullptr;

DevEnv::~DevEnv() {
    delete currentProgram;
}
//Only allows 1 instance of object
DevEnv* DevEnv::getInstance(){
  if (instance == nullptr){
    instance = new DevEnv();
  }
  return instance;
}

void DevEnv::setProgram(Program* program) {
    if (this->currentProgram != nullptr) {
        delete this->currentProgram;
    }
    this->currentProgram = program;
}


