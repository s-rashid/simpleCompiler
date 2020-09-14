#ifndef PARSEDLINE_H
#define PARSEDLINE_H

#include <QString>
#include <QList>

class ParsedLine
{
public:
    ParsedLine();
    ParsedLine(QString,QString,QList<QString>);
    QString getLabel();
    QString getInstrucType();
    QList<QString> getOperands();
    QString toQString();
    void setLabel(QString);
    void setInstrucType(QString);
    void addOperand(QString);

private:
    QString label;
    QString instrucType;
    QList<QString> operands;

};

#endif // PARSEDLINE_H
