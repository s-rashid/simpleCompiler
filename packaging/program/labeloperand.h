#ifndef LABELOPERAND_H
#define LABELOPERAND_H

#include <QString>
#include "operand.h"
#include "label.h"

class LabelOperand : public Operand {
public:
    LabelOperand(Label*);
    int getValue();
    Label* getIdentifier();
    void write(QJsonObject&);

protected:
    Label* label;

};

#endif // LABELOPERAND_H
