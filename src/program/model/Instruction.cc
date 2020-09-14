#include <iostream>
#include <iomanip>
using namespace std;

#include "Instruction.h"

Instruction::Instruction(string n) {
  name = n;
}

Instruction::~Instruction() {
  delete next;
}

void Instruction::print() {
  cout << name;
  if (next != NULL) {
    cout << " -> ";
    next->print();
  } else {
    cout << endl;
  }
}

void Instruction::setNextInstruction(Instruction* n) {
  next = n;
}

void Instruction::run() {
  this->execute();
  if (next != NULL) {
    next->run();
  } else {
    cout << "done" << endl;
  }
}
