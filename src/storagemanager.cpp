#include <iostream>
using namespace std;

#include "../include/storagemanager.h"
#include "../include/storagecontrol.h"
#include "../include/file.h"


void StorageManager::save(File file, int& response){
  StorageControl* sc = new StorageControl();
  sc->save(file.getDirectory(), file.getContents(), response);
  delete sc;
}

void StorageManager::load(File& file, int& response){
  StorageControl* sc = new StorageControl();
  string contents;

  sc->load(file.getDirectory(), contents, response);
  if (response == 0){
    file.setContents(contents);
  }
  delete sc;
}
// temp test
// g++ -o main -I ../include storagemanager.cpp storagecontrol.cpp file.cpp
// ./main
int main(){
  StorageManager* sm = new StorageManager();
  File* file1 = new File("./test.scapl", "line1\nline2");
  File* file2 = new File("./test.scapl");
  int response1;
  int response2;
  cout << "File 1 contents: " << endl << file1->getContents() << endl;
  cout << "File 2 contents: " << endl << file2->getContents() << endl;
  cout << "save(file1)" << endl << "load(file2)" << endl << endl;
  sm->save(*file1, response1);
  sm->load(*file2, response2);
  cout << "File 1 contents: " << endl << file1->getContents() << endl;
  cout << "File 2 contents: " << endl << file2->getContents() << endl;
}
