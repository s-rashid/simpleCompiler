#include "loadfilecontrol.h"

void LoadFileControl::loadProgram(QString& filePath, QString& fileContents) {
    StorageManager sm;
    QString contents;
    if (sm.load(filePath, contents) < 0) {
        return;
    }
    fileContents = contents;
}
