#include "savefilecontrol.h"

void SaveFileControl::saveProgram(QString& fileName, QString& dir, QString& fileContents) {
    QString path = dir + "/" + fileName;
    StorageManager sm;
    sm.save(path, fileContents);
}
