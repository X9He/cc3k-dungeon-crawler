#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>
#include "floor.h"
#include "pc.h"
#include "character.h"

using namespace std;


int main() {
    srand(time(0));
    cin.exceptions(ios::eofbit|ios::failbit);
    string cmd;
    int level = 1;
    cout << "choose your role" << endl;
    cout << "s for shade" << endl;
    cout << "d for drow" << endl;
    cout << "v for vampire" << endl;
    cout << "t for troll" << endl;
    cout << "g for goblin" << endl;
    cout << "q for quit" << endl;
    
    string role;
    PC *player = nullptr;
    while (cin >> role) {
        if (role == "s") {
            PC p;
            player = &p;
            break;
        } else if (role == "d") {
            Drow d;
            player = &d;
            break;
        } else if (role == "v") {
            Vampire v;
            player = &v;
            break;
        } else if (role == "t") {
            Troll t;
            player = &t;
            break;
        } else if (role == "g"){
            Goblin g;
            player = &g;
            break;
        } else if (role == "q"){
            cout << "Quiting" << endl;
            return 0;
        } else {
            cout << "Invalid role" << endl;
        }
    }
    
    cout << "printing palyer stuff: "<<player->getMax() << player->getAtk() << player->getDef() << endl;
    
    
    
    while (level < 6) {
        Floor f(player);
        f.init(player);
        cout << "finished initializing" << endl;
        string cmd;
        cout<< "Enter a direction: " <<endl;
        while (cin >> cmd) {
            if (cmd == "q") {
                cout << "Quiting" << endl;
                return 0;
            }
            if (cmd == "no" || cmd=="so" || cmd == "ea" || cmd == "we"
                || cmd == "ne" || cmd == "nw" || cmd == "se" || cmd == "sw" ) {
                if (f.movePlayer(cmd) == false) {
                    level++;
                    player->initAtkDef();
                    cout << "Entering level " << level << endl;
                    break;
                }
            } else if (cmd == "a") {
                string dir;
                cin >> dir;
                f.playerAttack(dir);
                if (player->die()) {
                    cout << "Lost" << endl;
                    return 0;
                }
            } else if (cmd == "u") {
                string dir;
                cin >> dir;
                f.playerUsePotion(dir);
            }
            cout << "finished one round" << endl;
            // f.updateEnemy();
            f.prettyPrint();
            cout<< "Enter a direction: " <<endl;
        }
        f.clearFloor();
    }
    
    
    cout << "Won" << endl;
    cout << "Gold Amount: " << player->getGold() << endl;
}

