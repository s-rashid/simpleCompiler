#include <iostream>
using namespace std;

#include "Program.h"

Program::Program() {
  rootInstruction = new MoveInstruction("Root");

  Instruction* prevInstruction = rootInstruction;
  Instruction* currInstruction = NULL;
  for(int i=0; i<7; i++) {
    currInstruction = new MoveInstruction("Step" + to_string(i + 1));
    prevInstruction->setNextInstruction(currInstruction);
    prevInstruction = currInstruction;
  }
  prevInstruction->setNextInstruction(NULL);
}

Program::~Program() {
  delete rootInstruction;
}

int Program::launch() {

  Identifier* iden;
  for(int i=0; i<10; i++) {
    iden = new Label("VAR" + to_string(i + 1));
    iden->print();
    delete iden;
  }

  for(int i=0; i<15; i++) {
    // TODO pass a value to Variable
    iden = new Variable("VAR" + to_string(i + 1));
    iden->print();
    delete iden;
  }

  rootInstruction->run();
  return 0;
}
