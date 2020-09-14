#ifndef LABEL_H
#define LABEL_H

#include <QString>
#include "identifier.h"

class Label : public Identifier {
public:
    Label(QString);
    void read(const QJsonObject&);
    void write(QJsonObject&);

};

#endif
