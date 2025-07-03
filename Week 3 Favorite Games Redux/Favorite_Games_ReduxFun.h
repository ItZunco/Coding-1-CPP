// Diego Segura-Chavez
// Favorite Games Redux Functions


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

const string gameList = "gamelist.txt";

void Load(vector<string>& games) {
    ifstream file(gameList);
    string game;
    
    while (getline(file, game)) {
        if (!game.empty()) {
            games.push_back(game);
        
        }
    }
    file.close();
}

void Add(vector<string>& games) {
    string game;
    cout << "What game would you like to add?\n";
    cin.ignore(); // Ignore input buffer
    getline(cin, game);
    games.push_back(game);
    cout << game << " has been added to your collection.\n \n";

}

void Edit(vector<string>& games) {
    string game;
    cout << "What game would you like to edit?\n";
    cin.ignore(); // Ignore input buffer
    getline(cin, game);
    
    auto iter = find(games.begin(), games.end(), game); // Finding game
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
}

void Remove(vector<string>& games) {
    string game;
    cout << "What game would you like to remove?\n";
    cin.ignore(); // Ignore input buffer
    getline(cin, game);
    
    auto iter = find(games.begin(), games.end(), game); // Finding game
    if (iter !=games.end()) {
        games.erase(iter);
        cout << "Game has been deleted from the collection\n";

    } else {
        cout << "Game not found in the collection.\n";

    }
}

void Show(const vector<string>& games) {
    if (games.empty()) {
                cout << "The game collection is empty. ._.\n";

    } else {
        vector<string> sortedGames = games;
        sort(sortedGames.begin(), sortedGames.end());
        cout << "Here is your current Favorite Games Collection.\n";
            for (auto favGames : sortedGames) {
            cout << favGames << "\n"; // Shows Favorite Games

        }
    }
}

void Quitting(const vector<string>& games) {
    char answerYN;
    cout << "Would you like to save your Game Collection? (Y/N)\n";
    cin.ignore(); // Ignore input buffer
    cin >> answerYN;
    
    if (toupper(answerYN) == 'Y') {
        ofstream file(gameList);    // Saving list as txt file.
        for (const string& game : games) {
        file << game << '\n';
            
        }
        file.close();
        cout << "Game collection saved to " << gameList << ".\n";
            
    } else if (toupper(answerYN == 'N')) {
        cout << "Would you like to delete your existing Game Collection Save instead?\n";
        cin.ignore(); // Ignore input buffer
        cin >> answerYN;

        if (toupper(answerYN == 'Y')) {
            ofstream file(gameList, ios::trunc);
            file.close();
            cout << "Game Collection Save deleted.\n";

        }
    } else {
        cout << "Invalid input. Returning N.\n";
        
    }
}