#include "dbHandlerGet.h"
#include "student.h"
#include "analyzer.h"
#include <string>

// this program is about a marks analyzer

using namespace std;

int main() {
  string inputdir = "./FilesMarks";
  string outputfile = "myOutput.txt";
  analyzer myanalyzer(inputdir, outputfile); 
  myanalyzer.getStudentData();
 //dbHandlerGet myhandler(inputdir);
  return 0;
}
