#include "storagecontrol.h"

bool StorageControl::save(QString fileName, QString instructions){
    QFile file (fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return -1;

    QTextStream out(&file);
    out << instructions << endl;
    file.close();
    return 0;
}

bool StorageControl::load(QString fileName, QString& instructions){
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) return -1;

    QTextStream in(&file);
    instructions = in.readAll();
    file.close();
    return 0;

}
