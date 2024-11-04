#include "movies.h"

movies::movies() {
  //  cout << "movies Constructor" << endl;
}

void movies::setDirector(char director[]) {
  strcpy(this->director, director);
}

char* movies::getDirector() {
  char* toReturn = director;
  return toReturn;
}

void movies::setDuration(int duration) {
  //In minutes
  this->duration = duration;
}

int movies::getDuration() {
  return duration;
}

void movies::setRating(float rating) {
  //0-10 scale (to one decimal place if needed)
  this->rating = rating;
}

float movies::getRating() {
  return rating;
}

void movies::printData() {
  cout << "MOVIE: " << endl;

  cout << title << endl;

  hours = duration / 60;
  minutes = duration % 60;
  cout << hours << "h " << minutes << "m" << endl; //prints out in hours+minutes

  cout << director << endl;
  cout << year << endl;
  cout << rating << endl;

  cout << "--------------" << endl;
}

movies::~movies() {
  //  cout << "MOVIE DECONSTRUCTOR" << endl;
  //delete[] director;
}

