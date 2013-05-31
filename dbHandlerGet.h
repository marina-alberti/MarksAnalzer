#ifndef DBHANDLERGET_H
#define DBHANDLERGET_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "student.h"

using namespace std;

class dbHandlerGet {
private:
  int nFiles;
  string dirname;
public:
  dbHandlerGet(string);
  void openDir(vector <student> &);
  student * openFile(string);
  //void readFile();
};

#endif 
