#include "media.h"
#include <iostream>

using namespace std;

class music : public media {
 public:
  music();

  void setArtist(char artist[]);
  char* getArtist();
  void setDuration(int duration);
  int getDuration();
  void setRating(float rating);
  float getRating();
  void printData();

  ~music();
  
private:
  char artist[20];
  int duration;
  int minutes;
  int seconds;
  float rating;
};
