#include "media.h"

using namespace std;

class movies : public media {
 public:
  movies();

  //methods
  void setDirector(char director[]);
  char* getDirector();
  void setDuration(int duration);
  int getDuration();
  void setRating(float rating);
  float getRating();
  void printData();
  
private:
  char director[20];
  int duration;
  int hours;
  int minutes;
  float rating;
};
