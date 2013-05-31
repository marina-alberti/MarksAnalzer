#include <string>
#include <iostream>
#include <map>
#include <stdlib.h>
#include <fstream>
#include "dbHandlerGet.h"
#include "student.h"
#include <cstring>
#include <dirent.h>
#include <cstdlib>
#include <sys/stat.h>
#include <sys/types.h>
#include <sstream>

using namespace std;

int main() {

  
  vector < vector <int > > myVector;
  vector <int > myRow(2, 35);
  //myRow = {1,5};
  myVector.push_back(myRow);
  myVector.push_back(myRow);
 // myVector[0].push_back(1);
  for (vector< vector <int > >::iterator it = myVector.begin() ; it != myVector.end(); ++it) {
    for ( vector <int>:: iterator it2 = (*it).begin(); it2 !=(*it).end() ; ++it2 ) {
      cout << endl << *it2<< endl; 
    }
  cout << "End line " << endl;
  }  

}

/*
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


/*  const char * filepath = "./FilesMarks/student01"; //filepath.c_str();
  
  ifstream fileStream(filepath, ifstream::in);
  string line;
 
  //fileStream.open(filepath);
  if (fileStream.is_open()) {
    int iline = 0;
    while (( fileStream.good()) && (iline < 9))  {
      iline ++;
      getline (fileStream, line);
     // cout << line << endl;
   
    istringstream ss(line);
    string singleword;
      if (iline == 1) {
        getline(ss, singleword, ',');
        string namein = singleword;
        ss >> singleword;
        string rollin = singleword;
        cout << "The student name is : " << namein << " and the roll is : " << rollin << endl;
      }
      else {
        //getline(ss, singleword, " ");
        ss >> singleword;
        string subject = singleword;
        ss >> singleword;
        string mark = singleword;
        cout << "The subject is : " << subject << " and the mark is : " << mark << endl;
      }  
    }
  }
  fileStream.close();
}
  
*/

/*  int numberElements;
  cout << "Enter the number of elements of the data structure: ";
  cin >> numberElements;
  // the map that will contain the data of string and int
  typedef std::map<std::string, int> MapType;
  MapType mymap;
  // in a for loop we ask to the user to input data from stdin
  for (int i = 1; i<=numberElements; i++) {
    string subject;
    int mark;
    cout << "\nSubject " << i ;
    cout << "\nEnter the subject name: " << endl;
    cin >> subject ;
    cout << "\nEnter the mark: ";
    cin>> mark; 
    // the data in input are inserted into the map
    mymap[subject] = mark;
  }  

// We display the values of the elements of the map using the iterator method of the map
  cout << "\nThe following elements have been inserted into the map:\n";
  MapType::const_iterator end = mymap.end(); 
  for (MapType::const_iterator it = mymap.begin(); it != end; ++it) {
    std::cout << "Subject: " << it->first;
    std::cout << "   Mark: " << it->second << endl;
  }
  return 0;
*/

