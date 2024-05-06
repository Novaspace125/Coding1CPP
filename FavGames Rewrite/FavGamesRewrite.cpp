#include "function.h"
#include "include.h"
#include <fstream>

// Use Getline(). Use a Vector<string>. Use a header file for the load() and
// save() functions. Load will add the favgames from the .txt file to the
// vector. Save will write the favgames from the vector to the file. T

int main() {
  cout << "Hello World!\n";
  // Create a program that will accept the user's fav games. On quit of
  // application, save those games to file.
  vector<string> favGames;
  ofstream file;                       // creating variable
  file.open("file.txt", ios::app);     // opening the file
  file << "Here is a line of text.\n"; // pushing this information into that
                                       // file
  file.close();

  // a new variable with the type "ifstream" names "readfromfile"

  while (true) {
    Say("What would you like to do?");
    string input;
    getline(cin, input);
    // add game

    if (input == "add") {
      Say("what game would you like to add?");
      getline(cin, input);
      file.open("favGames.txt", ios::app); // opening the file

      file << "\n"; // pushing this information into that file
      file << input;
      file.close();
    }
    // load games
    ifstream readFromFile("favGames.txt");
    string line;
    if (readFromFile.is_open()) {
      while (getline(readFromFile, line)) {
        cout << line << "\n"; // reads out the names from the file
        favGames.push_back(input);
        // favGames.push_back(line);
      }
      readFromFile.close();
    } else {
      cout << "could not read from file.";
    }
    // if (favGames.size() > 0) {
    //  cout << "The first name in Favorite Games is " << favGames[0] << ".\n";
    // }
    // show game

    if (input == "show") {

      cout << "There are " << favGames.size() << " items in our list.\n";
      for (int i = 0; i < favGames.size(); i++) {
        // if(favGames[i] == "") continue; // keep looping
        // cout << favGames[i] << "\n";
      }

      // edit games
      // file.open("favGames.txt", ios::app); // opening the file
      // file << favGames.push_back(favGame(size - 1));
      // file.close();

    }
    // quit game
    else if (input == "quit") {
      Say("thanks for playing.");
      break;
    }
  }
}