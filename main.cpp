#include <iostream>
#include <cstring>
#include <vector>
#include "media.h"
#include "games.h"
#include "music.h"
#include "movies.h"

void AddPrompt(vector<media*> &);
void Add(vector<media*> &);
void Search(vector<media*> &);
void Delete(vector<media*> &);
bool userSelection(vector<media*> &);
void setLowerCase(char cstring[]);
void checkInvalid();

const int MAX_INPUT = 21; 

using namespace std;

int main() {
  vector<media*> medias; //media will be the parent class
  
  while (!userSelection(medias)) {
    checkInvalid();
  } //keep running prgram until user enters quit
  
  return 0;
}


void Add(vector<media*> &medias, int m) { //user adds stuff to selected media field
  char input[MAX_INPUT];
  int yearIn = 0;
  float ratingIn = 0.00;
  int durationIn = 0;
  
  if (m == 1) {
    games* newGame = new games();
    cout << "Title: " << endl;
    cin.getline(input, MAX_INPUT);
    newGame->setTitle(input);

    cout << "Publisher: " << endl;
    cin.getline(input, MAX_INPUT);
    newGame->setPublisher(input);

    cout << "Year: " << endl;
    cin >> yearIn;
    newGame->setYear(yearIn);

    cout << "Rating: " << endl;
    cin >> ratingIn;
    newGame->setRating(ratingIn);

    cin.ignore();

    medias.push_back(newGame); 
  } else if (m == 2) {
    //Music
    music* newSong = new music();

    cout << "Title: " << endl;
    cin.getline(input, MAX_INPUT);
    newSong->setTitle(input);
    
    cout << "Artist: " << endl;
    cin.getline(input, MAX_INPUT);
    newSong->setArtist(input);

    cout << "Year: " << endl;
    cin >> yearIn;
    newSong->setYear(yearIn);

    cout << "Duration (in seconds): " << endl;
    cin >> durationIn;
    newSong->setDuration(durationIn);
    
    cout << "Rating: " << endl;
    cin >> ratingIn;
    newSong->setRating(ratingIn);

    cin.ignore();

    medias.push_back(newSong);
  } else if (m == 3) {
    //Movies
    movies* newMovie = new movies();
    cout << "Title: " << endl;
    cin.getline(input, MAX_INPUT);
    newMovie->setTitle(input);
    
    cout << "Director: " << endl;
    cin.getline(input, MAX_INPUT);
    newMovie->setDirector(input);

    cout << "Year: " << endl;
    cin >> yearIn;
    newMovie->setYear(yearIn);
    
    cout << "Duration (in minutes): " << endl;
    cin >> durationIn; 
    newMovie->setDuration(durationIn);
    
    cout << "Rating: " << endl;
    cin >> ratingIn;
    newMovie->setRating(ratingIn);

    cin.ignore();

    medias.push_back(newMovie);
  }
}

void Search(vector<media*> &medias) { //user searches through media based on title or year
  char input[MAX_INPUT];
  char titleIn[MAX_INPUT];
  int yearIn = 0;
  bool isValid = false;
  

  cout << "Do you want to search for a title or a year?" << endl;
  cin.getline(input, MAX_INPUT);
  
  setLowerCase(input);
  if (strcmp(input, "title") == 0) { 
    cout << "Title: " << endl;
    cin.getline(titleIn, MAX_INPUT);
    cout << " " << endl;
    for (vector<media*>::iterator it = medias.begin(); it != medias.end(); it++) {
      if (strcmp((*it)->getTitle(), titleIn) == 0) {
	(*it)->printData();
	isValid = true;
      }
    }
  }

  if (strcmp(input, "year") == 0) {
    cout << "Year: " << endl;
    cin >> yearIn;
    cin.ignore();
    cout << " " << endl;

    for (vector<media*>::iterator it = medias.begin(); it != medias.end(); it++) {
      if ((*it)->getYear() == yearIn) {
	(*it)->printData();
	isValid = true;
      }   
    }
  }

  if (!isValid) { //If invalid input (or the title/year isn't in database)
    cout << "Input is invalid or there are no matches in the database" << endl;
  }
}

void Delete(vector<media*> &medias) { //user can delete an item (using destructor!!) using the same search functionality.
  char input[MAX_INPUT];
  char titleIn[MAX_INPUT];
  int yearIn = 0;
  bool isValid = false;

  
  cout << "Search using title or year?" << endl;
  cin.getline(input, MAX_INPUT);
  setLowerCase(input);

  if (strcmp(input, "year") == 0) {
      cout << "Year: " << endl;
      cin >> yearIn;
      cin.ignore();
      cout << " " << endl;
      for (vector<media*>::iterator it = medias.begin(); it != medias.end(); it++) {
	if ((*it)->getYear() == yearIn) {
	  isValid = true;
	  (*it)->printData();
	  cout << "Are you sure you want to delete this from the database? (yes/no)" << endl;
	  char answ[MAX_INPUT];
	  cin.getline(answ, MAX_INPUT);
	  setLowerCase(input);
       
	  if (strcmp(answ, "yes") == 0 || strcmp(answ, "y" ) == 0) { 
	    cout << "removing media..." << endl;
	    delete *it;
	    medias.erase(it);
	    return;
	  }
	}
      }
  }

  if (strcmp(input, "title") == 0) {
    cout << "Title: " << endl;
    cin.getline(titleIn, MAX_INPUT);
    cout << " " << endl;
    for (vector<media*>::iterator it = medias.begin(); it != medias.end(); it++) {
      if (strcmp((*it)->getTitle(), titleIn) == 0) {
	isValid = true;
	(*it)->printData();
	cout << "Are you sure you want to delete these things from the database? (yes/no)" << endl;
	char answ[MAX_INPUT];
	cin.getline(answ, MAX_INPUT);
	setLowerCase(input);          
	  
	if (strcmp(answ, "yes") == 0 || strcmp(answ, "y") == 0) {
	  cout << "removing media..." << endl;
	  delete *it;
	  medias.erase(it);
	  return;
	}
      }
    }
  }
  if (!isValid) { //If invalid input (or the title/year isn't in database)
    cout << "Input is invalid or there are no matches in the database" << endl;
  }
}

//Menu where user selects what they want to do.
bool userSelection(vector<media*> &medias) {
  bool validIn = false;
  char input[7]; 
  char usrChoice;
  cout << "Add (a), Search for (s), or Delete (d) media. Quit (q)" << endl;
  
  cin.get(input, 7);
  setLowerCase(input); //set the letters of the input to lowercase
  cin.ignore(80, '\n'); //prevent extra return
  
  //Checks which input the user did.
  if (strcmp(input, "add") == 0 || strcmp(input, "a") == 0) {
    validIn = true;
    AddPrompt(medias);
  } else if (strcmp(input, "search") == 0 || strcmp(input, "s") == 0) {
    validIn = true;
    Search(medias);
  } else if (strcmp(input, "delete") == 0 || strcmp(input, "d") == 0) {
    validIn = true;
    Delete(medias);
  } else if (strcmp(input, "quit") == 0 || strcmp(input, "q") == 0) {
    return true; //bool returns true is we want to exit the program.
  } else {
    cout << "invalid input" << endl;
  }
  return false; //default keep looping through program. 
}

void AddPrompt(vector<media*> &medias) { //User selects which media to add (in new function to reduce clutter)
  cout << "What type of media do you want to add?" << endl;
  char input[7];
  bool validIn = false;
  while (!validIn) {
    cin.getline(input, 7);
    setLowerCase(input);
    if (strcmp(input, "game") == 0) {
      validIn = true;
      Add(medias, 1);
    } else if (strcmp(input, "music") == 0) {
      validIn = true;
      Add(medias, 2);
    } else if (strcmp(input, "movie") == 0) {
      validIn = true;
      Add(medias, 3);
    } else {
      checkInvalid();
    }
  }
}


//Pass in an array by reference, to change all contents to lowercase
void setLowerCase(char cstring[]) {
  for (int i = 0; i != strlen(cstring); i++) { //loop until string end
    cstring[i] = tolower(cstring[i]); //set the char here to lowercase
  }
}

void checkInvalid() {
  cin.ignore(100, '\n');
  while (cin.fail()) {
    cin.clear();
    //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.ignore(100, '\n');
    cout << "You entered an invalid input. Try again" << endl;
  }
}

