#ifndef STORAGECONTROL_H
#define STORAGECONTROL_H

class StorageControl{

public:
  void create(string directory);
  void save(string directory, string contents, int& response);
  void load(string directory, string& contents, int& response);
};

#endif
