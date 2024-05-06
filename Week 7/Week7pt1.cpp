#include <iostream>
#include <string> 
#include <vector>

// fuctions
//similar to f(x)
//inputs (peramiters) and outputs 
//reuse code and call them with a single words
// decllaring and defining a fuction
// calling a function
// return types
//


using namespace std;
//return type, function name, (input peramiters) {code}
void SayHello() {
    cout << "Hello.\n";
}

//return type, function name, (input peramiters) {code}
void Say(string givenText) {
    cout << givenText << "\n";
}

// return type, fuctionName
int AddTwoNumbers(int firstNum, int secondNum) {
    int sum = firstNum + secondNum;

    return sum;
}

//return type
bool AskYN(string question) {
    do {
        cout << question << "(y/n)\n"; 
        char input;
        cin >> input;

        if(input == 'y') {
            return true;
            
        }

        if(input == 'n') {
            return false;
        }

        cout << "you need to type a lower case 'y' or 'n'.\n";
    }while (true); 
    
}

// //dice roll returns a number between 1 and 6 inclusive
// int DiceRoll() {
//     return rand() % 6 + 1;
// }

// funtuon overloading means declarinf and defining another function wiht the same name
int DiceRoll (int sides = 6) { //default value of 6
    if (sides < 1) {
        sides = 2;
    }
    if ( sides > 100) {
        sides = 100;
    }
    return rand() % sides + 1;
}

// create a CastDamage() functtion that returns an int.
int CastDamage(int min, int max) {
    int damage = rand() % (max - min) + min; // number betwwen 5 and 9
    if(DiceRoll() == 6) {
        damage += damage;
    }

    return damage;
    
}
// accepts two input parameters min and max
// creates a int damage that is random in a range form min and max
// roll a d6 for a critical chance (if d6 = 6, doublr the damage)
// then retuerns damage
//use default values
// inMain(), call this function 10 times using a for loop

int main() {
    srand(time(0));
    cout << "Your Roll is " << DiceRoll() << ".\n";
    cout << "your D20 roll is " << DiceRoll(20) << ".\n";
    cout << "your D-14 roll is " << DiceRoll(-14) << ".\n";
    // for(int i = 0; i < 10; i++) {
    //     cout << "Enemy does " << CastDamage(12,24) << "!!\n";
    // }

    int playerHealth = 100;
    cout << "here we go adventureing!\n";
    do {
        int damageTaken = CastDamage(3,4);
        playerHealth -= damageTaken;
        cout << "Oh no! We've stubbed out toe. We've lost << " << damageTaken << " health.\n";
        cout << "Now we have " << playerHealth << " health.\n";
        if(playerHealth <= 0) break;

        if(AskYN("Do you want to keep playing?")) {
            cout << "great! here we go.\n";
        } else {
            cout << "thanks for playing!\n";
            break;
        }
        
    }while(true);
    
    SayHello();    //this calls the function
    SayHello();
    Say("How are you today?");
    Say("My name is Bob.");
    cout << "4 + 5 = " << AddTwoNumbers(4,5) << ".\n";
    if(AskYN("Do you want to keep playing?")) {
        cout << "great! here we go.\n";
    } else {
        cout << "thanks for playing!\n";
    }
    if(AskYN("Do you like cake?")) {
        
    }

    vector<string> unlikeableFoods = {"Cooked Spinach",                                                          "Mashed Potates", 
                                      "Radishes", 
                                      "Green Peas"};

    for(int i = 0; i < unlikeableFoods.size(); i++) {
        cout << unlikeableFoods[i] << "\n";
    }
    
    
    
}