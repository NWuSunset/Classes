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

  
private:
  char director[20];
  int year;
  int duration;
  float rating;
};
