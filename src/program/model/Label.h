#ifndef LABEL_H
#define LABEL_H

#include "Identifier.h"

using namespace std;

#define LABEL_TAG "lbl"

class Label : public Identifier {
  public:
    Label(string);
};

#endif
