#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H

#include <QString>

class StorageManager {

public:
    int save(QString fileName, QString filContents);
    int load(QString fileNmae, QString& fileContents);
};

#endif // STORAGEMANAGER_H
