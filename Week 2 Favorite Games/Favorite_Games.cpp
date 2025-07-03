// Diego Segura-Chavez
// Favorite Games

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> games;
    string input;
    cout << "Welcome to the Favorite Games Collection Manager.\n";
    cout << "EVERYTHING YOU TYPE IS CHARACTER AND CASE SENSITIVE\n";

    while (true) {
        cout << "\nWhat would you like to do?\n";
        cout << "You can type in the following options below.\n";
        cout << "\t[add] to add a game to the list\n";
        cout << "\t[edit] to edit a game on the list\n";
        cout << "\t[delete] to delete a game from the list\n";
        cout << "\t[show] to show current list of games\n";
        cout << "\t[quit] to quit\n";
        getline(cin, input);
        
        if (input == "add") {
            cout << "What game would you like to add?\n";
            getline(cin, input);
            games.push_back(input);
            cout << input << " has been added to your collection.\n \n";

        } else if (input == "edit") {
            cout << "What game would you like to edit?\n";
            getline(cin, input);
            
            auto iter = find(games.begin(), games.end(), input); // Finding game
            if (iter !=games.end()) {
                string newName;
                cout << "Game found.\n";
                cout << "What would you like to change it to?\n";
                getline(cin, newName);
                *iter = newName;
                cout << "Game updated.\n";

            } else {
                cout << "Game not found in the collection.\n";
            }
        } else if (input == "delete") {
            cout << "What game would you like to delete?\n";
            getline(cin, input);
            
            auto iter = find(games.begin(), games.end(), input); // Finding game
            if (iter !=games.end()) {
                games.erase(iter);
                cout << "Game has been deleted from the collection\n";

            } else {
                cout << "Game not found in the collection.\n";

            }
        } else if (input == "show") {
            if (games.empty()) {
                cout << "The game collection is empty. ._.\n";

            } else {
                sort(games.begin(), games.end());
                cout << "Here is your current Favorite Games Collection.\n";
                for (auto favGames : games) {
                    cout << favGames << "\n"; // Shows Favorite Games

                }
            }
        } else if (input == "quit") {
            cout << "Are you sure you want to quit?\n";
            cout << "[yes] to confirm quit. Other to cancel.\n";
            cin >> input;
            if (input == "yes") {
                cout << "Thank you for using the Favorite Games Collection Manager.\n";
                cout << "Press any key to close the program.\n";
                cin.get(); // Waits for user to press a key

                return 0; // Closes the program

            } else {
                cout << "Taking you back to the collection...\n";
            }
        } else {
            cout << "Invalid option. Please try again\n";

        }
    }
}