#ifndef STORAGECONTROL_H
#define STORAGECONTROL_H

#include <QObject>
#include <QFile>
#include <QTextStream>

class StorageControl
{
public:
    StorageControl();
    bool save(QString fileName, QString fileContents);
    bool load(QString fileName, QString& fileContents);

};

#endif // STORAGECONTROL_H
