#include <iostream>
#include <cstring>
#include <vector>
#include "media.h"
#include "games.h"

void Add();
void Search();
void Delete();
bool userSelection();
void setLowerCase(char cstring[]);
void checkInvalid();

using namespace std;

int main() {
  vector<media> medias; //media will be the parent class

  cout << "media class" << endl;
  //media* testParent = new media();
  games* newGame = new games(); //passing in values for the new game

  newGame->setYear(10);

  cout << newGame->getYear() << endl;

  

  //create a test piece of media
  
  while (!userSelection()); //keep running prgram until user enters quit 

  
  
  return 0;
}


void Add() { //user able to add media
  
}

void Search() { //user searches through media based on title or year

}

void Delete() { //user can delete an item (using destructor!!) using the same search functionality.

}

//Menu where user selects what they want to do.
bool userSelection() {
  bool validIn = false;
  while (!validIn) {
    char input[7]; 
    char usrChoice;
    cout << "Add (a), Search for (s), or Delete (d) media. Quit (q)" << endl;
    
    cin.get(input, 7);
    setLowerCase(input); //set the letters of the input to lowercase
    cin.ignore(); //prevent extra return
    
    //Checks which input the user did.
    if (strcmp(input, "add") == 0 || strcmp(input, "a") == 0) {
      validIn = true;
      Add();
    } else if (strcmp(input, "search") == 0 || strcmp(input, "s") == 0) {
      validIn = true;
      Search();
    } else if (strcmp(input, "delete") == 0 || strcmp(input, "d") == 0) {
      validIn = true;
      Delete();
    } else if (strcmp(input, "quit") == 0 || strcmp(input, "q") == 0) {
      return true; //bool returns true is we want to exit the program.
    } else {
      cout << "invalid input" << endl;
    }
    checkInvalid(); //checks for input that break the program.
  }
  return false; //default keep looping through program. 
}

//Pass in an array by reference, to change all contents to lowercase
 void setLowerCase(char cstring[]) {
   for (int i = 0; i != strlen(cstring); i++) { //loop until string end
     cstring[i] = tolower(cstring[i]); //set the char here to lowercase
   }
 }

void checkInvalid() {
  while (cin.fail()) {
    cin.clear();
    //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.ignore(100, '\n');
    cout << "You entered an invalid input. Try again" << endl;
  }
}
