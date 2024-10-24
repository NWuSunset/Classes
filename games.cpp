#include "games.h"
#include <iostream>

using namespace std;

games::games() {
  cout << "games!" << endl;
}

void games::setPublisher(char publisher[]) {
  strcpy(this->publisher, publisher); 
}

char* games::getPublisher() {
  char* toReturn = publisher;
  return toReturn; 
}

void games::setRating(float rating) {
  this->rating = rating;
}

float games::getRating() {
  return rating;
}
