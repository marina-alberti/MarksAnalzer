#include "analyzer.h"
#include "student.h"
#include "dbHandlerGet.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

analyzer::analyzer(string dirnamein, string filenamein) {
  // initialization of the data members in the constructor
  dirname = dirnamein;
  outputfilename = filenamein;
}

void analyzer::getStudentData() {
  cout << "The function getStudentData() is called by the analyzer class. " << endl;
  // create an object dbHandlerGet
  dbHandlerGet mydbHandler(dirname);
  // obtains the array of student objects from the dbHandlerGet object
  mydbHandler.openDir(studentVector);
  cout << "The size of the student vector is: " << studentVector.size() << endl;
}

void analyzer::arrangeStudentData() {
  // for each element of the studentVector 1D vector
  // create a new line in the studentData 2D vector
  // fill in the elements of the row with the data of all subjects in same order
  // myvector.push_back(myrow);

  // iteration over all the student objects present in the vector of students
  for (int i = 0; i < studentVector.size(); i++) {
    vector<int> myStudentRow;
    MapType::const_iterator end = studentVector[i].marks.end();
    // iteration over all the subjects
    for (MapType::const_iterator it = studentVector[i].marks.begin(); it != end; ++it) {
      myStudentRow.push_back( it->second );
      // if (DEBUG) { cout << myStudenRow } 
    }

  studentData.push_back(myStudentRow); 
  }
}
