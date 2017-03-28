#include <iostream>
#include <vector>
#include <utility>
#include "floor.h"

using namespace std;

int main() {
    cin.exceptions(ios::eofbit|ios::failbit);
    string cmd;
    Floor f;
    int level = 1;
    cout << "choose your role" << endl;
    cout << "s for shade" << endl;
    cout << "d for drow" << endl;
    cout << "v for vampire" << endl;
    cout << "t for troll" << endl;
    cout << "g for goblin" << endl;
    cout << "q for quit" << endl;
    
    string role;
    cin >> role;
    if (role == "s") {
        PC * player;
    } else if (role == "d") {
        Drow * player;
    } else if (role == "v") {
        Vampire * player;
    } else if (role == "t") {
        Troll * player;
    } else if (role == "g"){
        Goblin * player;
    } else if (role == "q"){
        cout << "Quiting" << endl;
        return;
    }
    
    
    while (level < 6) {
        Floor f{PC};
        string direction;
        while (cin >> direction) {
            if (direction == "q") {
                cout << "Quiting" << endl;
                return;
            }
            if (floor.moveplayer(direction) == false) {
                level++;
                PC.initAtkDef();
                cout << "Entering level " << level << endl;
                break;
            }
            if (player->die()) {
                cout << "Lost" << endl;
                return;
            }
            floor.updateEnemy();
            floor.prettyprint();
        }
    }
    
    cout << "Won" << endl;
    cout << "Gold Amount: " << PC.getGold() << endl;
}
