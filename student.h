#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <fstream>
#include <map>
using namespace std;
#define N_SUB 8;

typedef map<string, int> MapType;

class student {
private:
  int roll;
  string name;
  MapType marks;
public:
  student(string = "", int = 0);
  int getMarks(string);
  void setMarks(string, int);
  void setName(string);
  void setRoll(int);
  void show();
};

#endif
