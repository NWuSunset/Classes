#include "media.h"

media::media() {
  //Will have common methods: title, year
  cout << "Media Constructor" << endl;
  
}

//set the title, taking in a title
void media::setTitle(char title[]) {
  
}

void media::setYear(int year) {
  this.year = year;
}

int media::getYear() {
  cout << "getYear" << endl;
  return year;
}
