using namespace std;
#include <string>
#include "../include/file.h"

File::File(string directory, string contents /* = "" */){
  this->directory = directory;
  this->contents = contents;
}

void File::setContents(string contents){ this->contents = contents; }
void File::setDirectory(string directory){ this->directory = directory; }
string File::getContents(){ return(this->contents); }
string File::getDirectory(){ return(this->directory); }
