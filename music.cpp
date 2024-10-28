#include "music.h"

music::music() {
  cout << "Music Constructor" << endl;
}

void music::setArtist(char artist[]) {
  strcpy(this->artist, artist);
}

char* music::getArtist() {
  char* toReturn = artist;
  return toReturn;
}

void music::setDuration(int duration) {
  //In secondds
  this->duration = duration;
}

int music::getDuration() {
  return duration;
}

void music::setRating(float rating) {
  //0-10 scale (to one decimal place if needed)
  this->rating = rating;
}

float music::getRating() {
  return rating;
}


