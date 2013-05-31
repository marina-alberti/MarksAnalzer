#include "dbHandlerGet.h"
#include "student.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cstring>
#include <dirent.h>
#include <cstdlib>
#include <sys/stat.h>
#include <sys/types.h>
#include <vector>
using namespace std;

#define DEBUG 1

dbHandlerGet::dbHandlerGet(string dirnamein) {
  dirname = dirnamein;
  nFiles = 0;
}


/*http://forums.devarticles.com/c-c-help-52/pass-and-return-vector-from-to-function-c-150630.html */
void dbHandlerGet::openDir(vector<student> & sD) {  
  DIR *dp;
  struct dirent *ep;
  struct stat filestat;
  const char * dirnameC = dirname.c_str();

  dp = opendir(dirnameC);
  if (dp != NULL) {
    // for each file inside the directory
    while ((ep = readdir(dp)) != NULL) {
      if (DEBUG) {cout << "START loop cicle: " << ep->d_name << " is the name! "<< endl; }
      if (S_ISDIR(filestat.st_mode)) {continue; } 
      if ((strcmp(ep->d_name, ".") == 0) || (strcmp(ep->d_name, "..") == 0)) {continue; }
      string filepath = dirname + "/" + ep->d_name;
      student * mystudent = openFile(filepath);
      sD.push_back(*mystudent); // should i dereference it ?
      nFiles = nFiles + 1;
      if (DEBUG) {cout << "Added a new student. Now, nFiles = " << nFiles << endl; }
    }
    closedir (dp);
  }
  else {
    perror ("Could not open the directory!");
  }
}

// we open the file for reading, 
// read it line by line
// and save the data in the student object
student * dbHandlerGet::openFile(string filepath){
  student * mystudent = new student;
  const char * filepathC = filepath.c_str();
  ifstream fileStream(filepathC, ifstream::in);
  string line;
  if (fileStream.is_open()) {
    if (DEBUG) { cout << "The file student called " << filepath << " is now open inside the openFile function. " << endl;}
    int iline = 0;
    int maxLines = N_SUB+1;
    while ((fileStream.good()) && (iline < maxLines)) {
      iline ++;
      getline (fileStream, line);
      istringstream ss(line);
      string singleword;
      if (iline == 1) {
        getline(ss, singleword, ',');
        string namein = singleword;
        ss >> singleword;
        string rollin = singleword;
        const char * rollinC = rollin.c_str();
        int rollinInt = atoi(rollinC);       
        mystudent -> setName(namein);
        mystudent -> setRoll(rollinInt);
      }
      else {
        ss >> singleword;
        string subject = singleword;
        ss >> singleword;
        string mark = singleword;
        const char * markC = mark.c_str();
        int markInt = atoi(markC);
        mystudent -> setMarks(subject, markInt);
      }
    }
  }
  fileStream.close();
  if (DEBUG) {mystudent -> show(); }
  return mystudent;
}



