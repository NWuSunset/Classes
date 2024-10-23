#include "media.h"
#include <iostream>
#include <cstring>


media::media() {
  //Will have common methods: title, year
  cout << "Media Constructor" << endl;
  
}

//set the title, taking in a title
void media::setTitle(char title[]) {
  strcpy(this->title, title); //copy the input title to this title (since arrays are by reference we don't want to break it). 
}

char* media::getTitle() { //can return char pointer
  char* toReturn = title; //set the title array to 
  return toReturn;
}

void media::setYear(int year) {
  this->year = year; //year is of pointer type media* (need to use a pointer thing) 
}

int media::getYear() {
  cout << "getYear" << endl;
  return year;
}
