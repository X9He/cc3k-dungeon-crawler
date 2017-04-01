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
    bool isFrozen = false;
    bool hostile = false;
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
	        player = new Shade;
	        break;
	    } else if (role == "d") {        
	        player = new Drow;
	        break;
	    } else if (role == "v") {
	        player = new Vampire;
	        break;
	    } else if (role == "t") {
	        player = new Troll;
	        break;
	    } else if (role == "g"){
	        player = new Goblin;
	        break;
	    } else if (role == "q"){
	        cout << "Quiting" << endl;
	        return 0;
	    } else {
	        cout << "Invalid role" << endl;
	    }
    }

    // cout << "printing palyer stuff: "<<player->getMax() << player->getAtk() << player->getDef() << endl;
    
    

    while (level < 6) {
        cout << "Entering level " << level << endl;
        player->initAtkDef();
        cout << "finished init atk def" << endl;
        Floor f(player, isFrozen, hostile);
        cout << "finished floor construction" << endl;
        f.init(player);
        cout << "finished initializing" << endl;
        string direction;
        string cmd;
        cout<< "Enter a direction: " <<endl;
        while (cin >> cmd) 
        {
        	if (cmd == "q") 
        	{
                cout << "Quiting" << endl;
                f.clearFloor();
                return 0;
            }
            if (cmd == "no" || cmd=="so" || cmd == "ea" || cmd == "we"
                || cmd == "ne" || cmd == "nw" || cmd == "se" || cmd == "sw" ) 
            {
            	if (f.movePlayer(cmd) == false) 
            	{
                    level++;
                    cout << "Entering level " << level << endl;
                    break;
                }
            } 
            else if (cmd == "a") 
            {
                string dir;
                cin >> dir;
                f.playerAttack(dir);
                if (player->die()) {
                    cout << "Lost" << endl;
                    return 0;
                }
            } 
            else if (cmd == "u") 
            {
                string dir;
                cin >> dir;
                f.playerUsePotion(dir);
            } 
            else if (cmd == "b") 
            {
                level++;
                break;
            }
            else if (cmd == "f") 
            {
                f.setFrozen();
                cout << "Enter a direction: " << endl;
                continue;
            } else if (cmd == "r"){
            	level = 1;
            	player->initAll();
            	break;
            }

            // cout << "finished one round" << endl;

            f.updateEnemy();

            if (player->die()) {
            	cout << "Lost" << endl;
            	break;
            }

            f.prettyPrint();
            cout << "player hp:" << player->getHP() << endl;
            f.printEnemyHP();

            cout<< "Enter a direction: " <<endl;
        }
        isFrozen = f.getFrozen();
        hostile = f.getHostile();
        f.clearFloor();
        if (player->die()) break;
  }
    
    if(!player->die()) {        
        cout << "Won" << endl;
        cout << "Gold Amount: " << player->getGold() << endl;
        cout << "HP, Atk and Def: " << player->getHP() << " " << player->getAtk() << " " << player->getDef() << endl;
    }
    delete player;
}

