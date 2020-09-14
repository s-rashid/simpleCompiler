#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H

#include <QString>
#include "storagecontrol.h"

class StorageManager {

public:
    int save(QString fileName, QString filContents);
    int load(QString fileName, QString& fileContents);
};

#endif // STORAGEMANAGER_H
