#include "storagemanager.h"

/**
 * @brief StorageManager::save
 * @param fileName
 * @param fileContents
 * @return
 */
int StorageManager::save(QString fileName, QString fileContents) {
    StorageControl sc = StorageControl();
    int response = sc.save(fileName, fileContents);
    return response;
}

int StorageManager::load(QString fileName, QString& fileContents) {
    StorageControl sc = StorageControl();
    int response = sc.load(fileName, fileContents);
    return response;
}
