#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
  cout << "Hello World!\n";
    vector<string> favGames;  
    while(true) {
        cout << "What would you like to do?\n";
        string input;
        getline(cin, input);

        if(input == "add") {
            cout << "what game would you like to add?\n";
            getline(cin, input);
            favGames.push_back(input); 
        
        }  
        
        else if (input == "show") { 
             
            cout << "There are " << favGames.size() << " items in our list.\n";
            for (int i = 0; i < favGames.size(); i ++) {
                // if(favGames[i] == "") continue; // keep looping
                cout << favGames[i] << "\n";
            }
            
        }

        else if(input == "quit") {
            cout << "thanks for playing.\n";
            break;
        }
            
            

        
    }

    
}