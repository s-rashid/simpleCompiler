#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h> //for test

using namespace std;

#include "../include/storagecontrol.h"

void StorageControl::save(string directory, string contents, int& response){
  fstream fs;
  fs.open(directory, ios::out | ios::trunc);
  if (fs) {
    fs << contents << endl;
    response = 0;
  }
  else
    response = -1;
  fs.close();
}

//Probably not needed if creating a file just creates a file object and saves nothing
void StorageControl::create(string directory){
  fstream fs;
  fs.open(directory, ios::trunc);
  fs.close();
}

void StorageControl::load(string directory, string& contents, int& response){
  fstream fs;
  stringstream ss;
  fs.open(directory);
  if (fs){
    ss << fs.rdbuf();
    response = 0;
  }
  else
    response = -1;
  fs.close();
  contents = ss.str();
}
