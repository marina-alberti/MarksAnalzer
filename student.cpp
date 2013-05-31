#include "student.h"
#include <string>
using namespace std;

student::student(string namein, int rollin) {
  name = namein;
  roll = rollin;
}

int student::getMarks(string subject) {
  return marks[subject];
}

int student::getMarks(int number) {
  int mycount = 0;
  int studentMarks;
  MapType::const_iterator end = marks.end(); 
  for (MapType::const_iterator it = marks.begin(); it != end; ++it) {
    mycount++;
    if (mycount == number) break;
    studentMarks =  it->second;
  }
  return studentMarks;
}

void student::setMarks(string subject, int markin) {
  marks[subject] = markin;
}

void student::setName(string namein) {
  name = namein;
}

void student::setRoll(int rollin) {
  roll = rollin;
}

void student::show() {
  cout << "Name: " << name << "  Roll: "  << roll << endl;
  MapType::const_iterator end = marks.end(); 
 
  for (MapType::const_iterator it = marks.begin(); it != end; ++it) {
    cout << "Subject: " << it->first;
    cout << "  Mark: " << it->second << '\n';
    }
}
