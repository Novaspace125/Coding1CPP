//global variables why are they useful
// what's the OR operator
//passing and returning vectors
//do while checks the test


#include <iostream> // for cout and cin
#include <ctime>    // for srand(0)
#include <cstdlib>  // for rand() and srand()
#include <string>
#include <vector>
#include <map>
using namespace std;

 // vector<string> colors = {"Red", "Green", "Blue", "Yellow"}; //global variables go to the top so that all functions can see the varibles
//dangerous cuz everyone can see and edit unless u have to

//create a function named tripile, that returns an in that has beeen tripled
int triple (int givenNumber) { //return type function name(input parameters) {code block}
    return givenNumber * 3;
}

// cariable scope - variables only exist in the code block they are created in
void DisplayVec(vector<string> vec) {
    
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << ".\n";
    }
}

//function named addtovector return type id void, accepts two peraters
//vector of strings, and a string to add
vector<string> AddToVector(vector<string> vec, string newItem) { //copy of vec
    vec.push_back(newItem); //vec is equal to colors
    return vec;
}

//pass by copy/value vs passing by reference. 
void RefAddToVector (vector<string>& rVec, string newItem) {
    rVec.push_back(newItem);
}

bool PasswordCheck(string user, string pass) {
    if(user == "Brian") {
        if(pass == "Green") {
            return true;
        
        }else {
            cout << "Wrong Password.\n";
            return false;
        }
    }
    if(user == "admin" || pass == "admin"){ // || means or
        cout << "Speak Friend and enter.\n";
        return true;
    }
    else if (user == "Harry" && pass == "Expelliarmus") { // && equals and
        cout << "Hello harry!\n";
        return true;
    }
    
    else {
        cout << "Unreconizable user.\n";
        return false;
    }
    
}


int main() {
  cout << "Hello World!\n";

 cout << "triple of 5 is " << triple(5) << ".\n";
vector<string> colors = {"Red", "Green", "Blue", "Yellow"};
   vector<string> names = {"ron", "harry", "dumbledore"};
   RefAddToVector(colors, "Magenta"); //reference, talk about colors

    DisplayVec(colors);
   DisplayVec(names); 

    cout << "Oh, really like tourmaline, let's add that to the vector of colors.\n"; 
    colors = AddToVector (colors, "Tourmaline");

    cout << "Here's our colors: \n";
    DisplayVec(colors);

    // dictionaries (or map) are a key - value pair
    //#include map
    map < string , string > userpass; 
    userpass ["Brian"] = "green"; // [key] = value
   
    cout << userpass["Brian"] << ".\n";

    string username = "Brian";
    string password = "green";
    if(password == userpass[username]) {
        cout << "sucess!\n";
            
    }else {
        cout << "somethings is wrong.\n";
    }
}