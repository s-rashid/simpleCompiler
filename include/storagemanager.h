#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H

#include "../include/file.h"

class StorageManager{

public:
  //void create();
  void save(File file, int& response);
  void load(File& file, int& response);

};

#endif
