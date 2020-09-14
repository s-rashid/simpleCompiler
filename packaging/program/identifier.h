#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include <QString>
#include <QJsonObject>

class Identifier {
public:
    virtual ~Identifier();
    virtual void print();
    virtual void write(QJsonObject&) = 0;
    virtual void clean();

protected:
    Identifier(QString);
    QString name;

};
#endif
