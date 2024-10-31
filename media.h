
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
  char* getTitle();
  void setYear(int year);
  int getYear();
  virtual void printData();

  virtual ~media(); //destructor
  
protected: //common variables
  char title[20];
  int year;
};

#endif
