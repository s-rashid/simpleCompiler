#ifndef LABELOPERAND_H
#define LABELOPERAND_H

#include <QString>
#include "programcontext.h"
#include "operand.h"
#include "label.h"

class LabelOperand : public Operand {
public:
    LabelOperand();
    LabelOperand(Label*);
    Label* getIdentifier();
    void read(const QJsonObject&, ProgramContext*);
    void write(QJsonObject&);

protected:
    Label* label;

};

#endif // LABELOPERAND_H
