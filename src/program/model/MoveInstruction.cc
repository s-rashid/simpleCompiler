#include <iostream>
#include <iomanip>
using namespace std;

#include "MoveInstruction.h"

MoveInstruction::MoveInstruction(string n) : Instruction (n) {}

void MoveInstruction::execute() {
  this->print();
}
