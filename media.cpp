#include "media.h"
#include <iostream>
#include <cstring>


media::media() {
  //Will have common methods: title, year
  //  cout << "Media Constructor" << endl;
  
}

//set the title, taking in a title
void media::setTitle(char title[]) {
  strcpy(this->title, title); //copy the input title to this title (since arrays are by reference we don't want to break it). 
}

char* media::getTitle() { //(Virtual) can return char pointer
  char* toReturn = title; //set the title array to 
  return toReturn;
}

void media::setYear(int year) {
  this->year = year; //year is of pointer type media* (need to use a pointer thing) 
}

int media::getYear() { //Virtual
  return year;
}

void media::printData() { //Virutal
  //cout << "PARENT PRINT DATA" << endl;
}

media::~media () {
  //  cout << "MEDIA DECONSTRUCTOR";
  delete[] title; //delete the title char array since it may still be stored even when the object is removed
}
