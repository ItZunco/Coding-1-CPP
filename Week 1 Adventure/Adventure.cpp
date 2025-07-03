// Diego Segura-Chavez Adventure
// June 6th, 2025

#include <iostream>
using namespace std;

int main() {
    cout << "\tWelcome to the Adventure!\n";
    cout << "Here are the rules!\n";
    cout << "VVVVVVVVVVVVVVVVV\n";
    cout << "You and your enemy start with 10 Health (No health regen. Sorry...).\n";
    cout << "Attack your enemies until their health reaches 0 to win!\n";
    cout << "Defend by blocking or evading your enemies' attacks!\n";
    cout << "\tBlock to reduce damage taken (to a minimum of 1)!\n";
    cout << "\tEvade to avoid ALL damage you're about to take!\n";
    cout << "\tThe enemy can also choose to block or evade (or do nothing)!\n";
    cout << "If YOUR health reaches 0, you lose!\n";
    cout << "Have fun!\n";
    cout << "\nWould you like to start your adventure?\n";
    cout << "\"y\" for yes, \"n\" for no\n";

    char answerYN = 'y';    // Good for asking yes or no

    cin >> answerYN;

    if (answerYN == 'y') {
        cout << "Adventure Start!\n";
        // Setting up the game
        int PHealth = 10;   // P for Player
        int EHealth = 10;   // E for Enemy
        int Rounds = 0;
        string AtkAction = "attack";
        string PAction = "";
        while (PHealth > 0) {  // GAME START
            Rounds += 1;
            EHealth = 10;
            int Damage;
            cout << "Round " << Rounds << "\n";

            while (PHealth > 0 && EHealth > 0) { // Both the player and enemy are alive
                do {
                    cout << "\nIt's your turn!\n";
                    cout << "Type [attack] to attack!\n";
                    cin >> AtkAction;
                } while (AtkAction != "attack");

                // Player's turn
                int PAtk = rand() % 4;
                cout << "You attack the enemy!\n";
                cout << "Damage: " << PAtk << "\n";
                int EAction = rand() % 10;   //The enemy was evading WAY too much with a low number
                                             // so the max number is 10

                // Enemy Defense Choice
                if (EAction = 0){
                    cout << "The enemy attempts to block the attack!\n";
                    int Block = rand() % 4; // Block Strength
                    cout << "Block Strength:" << Block << "\n";
                    if (PAtk <= Block) {
                        cout << "1 Damage\n";
                        EHealth -= 1;
                    } else {
                        Damage = PAtk - Block;
                        cout << Damage << " Damage\n";
                        EHealth = Damage;
                    }
                } else if (EAction = 1) {
                    cout << "The enemy attempts to evade the attack!\n";
                    int Evade = rand() % 4; // Evade chance
                    cout << "Evade Chance: " << Evade << "\n";
                    if (PAtk < Evade) {
                        cout << "The enemy successfully evades your attack!\n";
                        cout << "All damage avoided!\n";
                    } else {
                        EHealth -= PAtk;
                        cout << "The enemy failed to evade!\n";
                        cout << PAtk << " Damage\n";
                    }
                } else {
                    EHealth -= PAtk;
                    cout << PAtk << "Damage\n";
                }
                
                cout << "Enemy Health: " << EHealth << "\n";

                if (EHealth <= 0) break;    //Enemy defeated if enemy health reaches 0

                // Enemy's turn
                cout << "The enemy prepares to attack...\n";
                int EAtk = rand() % 4;
                cout << "Damage:" << EAtk << "\n";
                cout << "Do you want to [block] or [evade]?\n";
                cin >> PAction;
                if (PAction == "block"){
                    cout << "You attempt to block the attack!\n";
                    int Block = rand() % 4; // Block Strength
                    cout << "Block Strength: " << Block << "\n";
                    if (EAtk <= Block){
                        cout << "1 Damage\n";
                        PHealth -= 1;
                    } else {
                        Damage = EAtk - Block;
                        cout << Damage << " Damage\n";
                        PHealth -= Damage;
                    }
                } else if (PAction == "evade") {
                    cout << "You attempt to evade the attack!\n";
                    int Evade = rand() % 4; // Evade chance
                    cout << "Dodge chance: " << Evade << "\n";
                    if (EAtk < Evade) {
                        cout << "You successfully evade the attack!\n";
                        cout << "All damage avoided!\n";
                    } else {
                        PHealth -= EAtk;
                        cout << "The enemy failed to evade!\n";
                        cout << EAtk << " Damage\n";
                    }
                } else {
                    cout << "Oops! You might've not typed in the choices correctly!\n";
                    cout << "Be sure to check the spelling next time. It's also case sensitive!\n";
                    cout << "Anyways... You take " << EAtk << "damage. Sorry!\n";
                }

                cout << "Player Health: " << PHealth << "\n";

            }
            // Post-Battle Outcome
            if (PHealth > 0) {
                cout << "You defeated your enemy!\n";
                cout << "YOU WIN\n";
                cout << "Your current health is: " << PHealth << "\n";
                cout << "Would you like to continue your adventure?\n";
                cout << "\"y\" to continue. \"n\" to stop here.\n";
                cin >> answerYN;
                if (answerYN != 'y'){
                    cout << "You head back home after many thrilling battles.\n";
                    if (PHealth <= 2){
                        cout << "I'd... recommend finding a doctor soon though.\n";
                        cout << "GAME OVER";
                        std::cin.get();

                        return 0;
                    }
                }
            } else {
                cout << "You have been defeated...\n";
                cout << "Your journey has come to an end...\n";
            }
        }
    } else if (answerYN == 'n') {
        cout << "Oh. Already? Well, see you next adventure!\n";
    } else {
        cout << "You typed " << answerYN << ", which wasn't one of the options.\n";
        cout << "You're gonna have to restart. Sorry. :T\n";
    }
    cout << "GAME OVER\n";
    cout << "Press any key to exit.\n";
        std::cin.get();

        return 0;   // Ends the program.
}