#ifndef IDENTIFIER_H
#define IDENTIFIER_H

using namespace std;

class Identifier {
  public:
    virtual ~Identifier();
    virtual void print();

  protected:
    Identifier(string, string);
    string varId;
    string name;

};
#endif
