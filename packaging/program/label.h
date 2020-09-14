#ifndef LABEL_H
#define LABEL_H

#include <QString>
#include "identifier.h"

class Label : public Identifier {
public:
    Label(int, QString);
    int getValue();
    void write(QJsonObject&);

private:
    int lineNumber;
};

#endif
