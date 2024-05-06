#include <iostream>
#include <string> 
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

bool AskYN (string question) {
    do {
       
    cout << question << "(y/n)\n";
      char input;
        cin >> input;

        if (input == 'y') {
            return true;
        }
        if (input == 'n') {
            return false; 
        }
    }while (true);
}

int DiceRoll (int sides = 6) { //default value of 6
    if (sides < 1) {
        sides = 2;
    }
    if ( sides > 6) {
        sides = 6;
    }
    return rand() % sides + 1;
}
int CastDamage(int min, int max) {
    int damage = rand() % (max - min) + min; 
    if(DiceRoll() == 6) {
        damage += damage;
    }

    return damage;

}

int main() {
     srand(time(0));
  cout << "Hello World!\n";
    //Let's have the player go on an adventure!
    cout << "Welcome to the Adventure!\n";
   int playerHealth = 10;
    int totalGold = 0;
    int turns = 0;
    do {
       
       // The player will also find a random amount of gold. This is the end of the loop.
        cout << "Oh no, you've encountered an orc!\n";
         //If they say "yes", they will meet an orc who will attack them! The orc will roll for "attack" and the player will roll for "block". if the number for block is greater than or equal to the number for attack,
        int orcDamage = DiceRoll(6);
        int playerBlock = DiceRoll(6);
        if (orcDamage > playerBlock) {
            int damageTaken = CastDamage(3,4);
           playerHealth -= damageTaken; 
            cout << "You have taken " << damageTaken << " damage!\n";
            // cout << "Your health is now " << playerHealth << ".\n";
            
        }
        if (playerHealth <= 0) {
            cout << "You have been defeated! Game Over!\n";
            break;
        }
        
        turns ++;
         // the player will successfully block the attack, lose one health point, and run away!
        if (playerBlock >= orcDamage) {
            playerHealth -= 1;
            int goldFound = DiceRoll(10);
            totalGold += goldFound;
            cout << "You successfully blocked the orc's attack!\n";  
            cout << "you found some gold! You now have " << goldFound << " gold!\n";
            // cout << "your health is now " << playerHealth << ".\n";
        
        }
        if (playerHealth > 0) {
            cout << "You survived with " << playerHealth << " health and " << totalGold << " gold!\n";
        }
         // The player should be asked at the beginning of each turn if they would like to go adventuring. 
        if (AskYN ("Do you want to keep adventuring?")) {
            cout << "Lets go!\n";
            
        }else {  //If the player decides to stop adventuring, the loop will stop.
            cout << "Thanks for playing!\n";
              break; 
        }
    
    }while(true);
    if (playerHealth > 0) {
        cout << "you lasted " << turns << " turns!\n";
    
        if(playerHealth > 5) {
        cout << "You survived with " << playerHealth << " health and " << totalGold << " gold!\n";
    
        }else if(playerHealth <= 5) {
        cout << "You have " << playerHealth << " health\n"; 
        cout << "you should proabably go to the doctor!\n";
        }        

    }
   

    //after the loop is over, the player will be told whether they are alive still.If they are alive, they will be told how many turns they lasted and how much gold they found. if they are alive but their health is less than 5, they will be encouraged to go to the doctor. If they are dead, they will be told how much gold is left by their body.

    //Include the following functions:

   // int RollDie(int sides = 6)
    //string askYesNo(string question)
    //Use a do-while loop in main() for the main adventure loop.
}