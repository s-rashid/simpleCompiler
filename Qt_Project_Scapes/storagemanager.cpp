#include "storagemanager.h"
#include "storagecontrol.h"

int StorageManager::save(QString fileName, QString fileContents) {
    StorageControl* sc = new StorageControl();
    int response = sc->save(fileName, fileContents);
    delete sc;
    return response;
}

int StorageManager::load(QString fileName, QString& fileContents) {
    StorageControl* sc = new StorageControl();
    int response = sc->load(fileName, fileContents);
    delete sc;
    return response;
}
