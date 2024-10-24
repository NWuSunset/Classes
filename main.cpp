#include <iostream>
#include <cstring>
#include <vector>
#include "media.h"
#include "games.h"

void AddPrompt(vector<media> &);
void Add(vector<media> &);
void Search();
void Delete();
bool userSelection(vector<media> &);
void setLowerCase(char cstring[]);
void checkInvalid();

const int MAX_INPUT = 21; 

using namespace std;

int main() {
  vector<media> medias; //media will be the parent class
  
  cout << "media class" << endl;
  //media* testParent = new media();
  games* newGame = new games(); //passing in values for the new game

  char input[MAX_INPUT];
  cin.getline(input, MAX_INPUT);
  cout << input << endl;
  newGame->setTitle(input);
  newGame->setYear(10);
  

  cout << newGame->getYear() << endl;
  cout << newGame->getTitle() << endl;

  

  //create a test piece of media
  
  while (!userSelection(medias)); //keep running prgram until user enters quit 

  
  
  return 0;
}


void Add(vector<media> &medias, int m) { //user adds stuff to selected media field
  char input[MAX_INPUT];
  int yearIn = 0;
  float ratingIn = 0.00;
  
  if (m == 1) {
  games* newGame = new games();
  cout << "Title: " << endl;
  cin.getline(input, MAX_INPUT);
  newGame->setTitle(input);
  cout << "Year: " << endl;
  cin >> yearIn;
  cin.ignore();
  newGame->setYear(yearIn);
  cout << "Publisher: " << endl;
  cin.getline(input, MAX_INPUT);
  newGame->setPublisher(input);
  cout << "Rating: " << endl;
  cin >> ratingIn;
  cin.ignore();
  newGame->setRating(ratingIn);

  cout << "debug" << endl;
  } else if (m == 2) {
    
    
  } else if (m == 3) {

  }
}

void Search() { //user searches through media based on title or year

}

void Delete() { //user can delete an item (using destructor!!) using the same search functionality.

}

//Menu where user selects what they want to do.
bool userSelection(vector<media> &medias) {
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
      AddPrompt(medias);
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

void AddPrompt(vector<media> &medias) { //User selects which media to add (in new function to reduce clutter)
  cout << "What type of media do you want to add?" << endl;
  char input[7];
  bool validIn = false;
  while (!validIn) {
    cin.getline(input, 7);
    setLowerCase(input);
    if (strcmp(input, "games") == 0) {
      validIn = true;
      Add(medias, 1);
    } else if (strcmp(input, "movies") == 0) {
       validIn = true;
       Add(medias, 2);
    } else if (strcmp(input, "music") == 0) {
       validIn = true;
       Add(medias, 3);
    } else {
      cout << "Invalid Input" << endl;
    }
    checkInvalid();
  }
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
