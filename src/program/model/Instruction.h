#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "../Program.h"

using namespace std;

class Instruction {
  public:
    Instruction(string = "Unknown");
    virtual ~Instruction();
    void print();
    void setNextInstruction(Instruction*);
    void run();

  protected:
    string name;
    virtual void execute()=0;

  private:
    Instruction* next;
};

#endif
