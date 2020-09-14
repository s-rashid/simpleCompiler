#ifndef FILE_H
#define FILE_H

#include <string>

using namespace std;

class File{

private:
  string contents;
  string directory;

public:
  File(string directory, string contents = "");
  void setContents(string contents);
  void setDirectory(string directory);
  string getContents();
  string getDirectory();

};
#endif
