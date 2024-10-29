

#include "media.h"
#include <iostream>

using namespace std;

class games : public media {
 public:
  games();

  //Methods
  void setPublisher(char publisher[]);
  char* getPublisher();
  void setRating(float rating);
  float getRating();
  void printData();
  
private:
  char publisher[20];
  float rating;
};
