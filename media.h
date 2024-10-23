
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

protected: //common variables
  char title[20];
  int year;
};

#endif
