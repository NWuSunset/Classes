#include "media.h"
#include <iostream>

using namespace std;

class games : public media {
 public:
  games();
  char title[20];
  int year;
  char publisher[20];
  float rating;
};
