#ifndef ANALYZER_H
#define ANALYZER_H

#include "dbHandlerGet.h"
#include "student.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

class analyzer {
private:
  string dirname;
  string outputfilename;
  // a vector of student that is filled with call to getStudentData
  vector <student> studentVector ; 
  // a 2D vector from STL containing the data of all students for all subjects 
  // ready for the computations - filled by call to arrangeStudentData
  vector <vector <int> > studentData;

  // the variables that hold the output of the algorithms for data analysis

  // function that puts the data in an internal 2D structure where the algorithms
  // for analysis will be performed
  void arrangeStudentData();

public:
  // this is the constructor, where the first argument is 
  // the directory path and the second argument is the output txt file name.  
  analyzer(string, string);
  // it displays on STDOUT the results of the data analysis
  void show();
  // it saves in output txt file the results of the data analysis
  void save();
  // it calls dbHandlerGet, with a pointer to array of student objects
  // it returns the student data inside the array
  void getStudentData(); 
};


#endif
