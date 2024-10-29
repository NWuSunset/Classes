
#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <cstring>

using namespace std;

class media {
 public:
  media();

  //Common methods
  void setTitle(char title[]);
  virtual char* getTitle();
  void setYear(int year);
  virtual int getYear();
  virtual void printData();
  
protected: //common variables
  char title[20];
  int year;
};

#endif
