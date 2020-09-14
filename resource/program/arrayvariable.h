#ifndef ARRAYVARIABLE_H
#define ARRAYVARIABLE_H

#include <QString>
#include "variable.h"
#include "integervariable.h"
#include "identifier.h"
#include "unsupportedoperationexception.h"
#include "arrayindexoutofboundsexception.h"

using namespace std;

class ArrayVariable : public Variable {
public:
    ArrayVariable(QString);
    ArrayVariable(QString, int);
    ~ArrayVariable();
    void setValue(int);
    int getValue();
    void setArrayValue(int, int);
    int getArrayValue(int);
    Variable* get(int);
    void print();
    void write(QJsonObject&);
    void read(const QJsonObject&);

protected:
    int size;
    int pos;
    Variable **elements;
private:
    void initElements();
};

#endif // ARRAYVARIABLE_H
