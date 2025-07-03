// Diego Segura-Chavez
// Favorite Games Redux

#include "Favorite_Games_ReduxFun.h"   // Everything in there is here too

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> games;
    char input;
    Load(games);
    cout << "Welcome to the Favorite Games Collection Manager (REDUX).\n";
    cout << "Nothing's case sensitive now (except for game titles!) :D\n";
    
    while (true) {
        cout << "\nWhat would you like to do?\n";
        cout << "You can type in the following options below.\n";
        cout << "\t[A] to add a game to the list\n";
        cout << "\t[E] to edit a game on the list\n";
        cout << "\t[R] to remove a game from the list\n";
        cout << "\t[S] to show current collection of games\n";
        cout << "\t[Q] to quit\n";
        cin >> input;

        switch(toupper(input)) {
            case 'A':
                Add(games);
                break;
            case 'E':
                Edit(games);
                break;
            case 'R':
                Remove(games);
                break;
            case 'S':
                Show(games);
                break;
            case 'Q':
                cout << "Are you sure you would like to quit? (Y/N)\n";
                cin.ignore(); // Ignore input buffer
                cin >> input;
                if(toupper(input) == 'Y') {
                    Quitting(games);
                    cout << "Thank you for using the Favorite Games Collection Manager.\n";
                    
                    return 0; // Closes program

                } else {
                    cout << "Returning N. Taking you back to the collection...\n";
                    cin.ignore(); // Ignore input buffer
                }
            default:
                cout << "Invalid input. Please try again.\n";
        }
    }
}