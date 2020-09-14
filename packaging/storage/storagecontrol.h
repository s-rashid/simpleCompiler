#ifndef STORAGECONTROL_H
#define STORAGECONTROL_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTextCodec>

class StorageControl
{
public:
    bool save(QString fileName, QString fileContents);
    bool load(QString fileName, QString& fileContents);
};

#endif // STORAGECONTROL_H
