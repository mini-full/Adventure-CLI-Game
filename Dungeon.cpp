#include <vector>
#include <iostream>
#include <map>
#include "Room.h"
#include "Player.h"
#include "Dungeon.h"

/**
 * @brief Here, the army of friends will tell the player the location of the monster.
 * 
 * @param game_map 
 * @param player 
 */
void Dungeon::situation_prompt(vector<vector<Room*> >& game_map, Player& player){
    cout << "$DUNGEON$" << endl;
    cout << "#System#\n\tWelcome to the Dungeon, you encoutered a \
lurking friend army\n";
    cout << "#Friend#\n\tI just met the monster, I was bitten and is gonna die." << endl;
    cout << "\tRemember...the monster is at ";
    if (monster_r < player.get_row())
        cout << "\tNorth ";
    else if (monster_r > player.get_row()) cout << "\tSouth ";
    else cout << "\tjust";
    if (monster_c < player.get_col())
        cout << " West" << endl;
    else if (monster_c > player.get_col())
        cout << " East" << endl;
    else if (monster_r == player.get_row() && monster_c == player.get_col())
        cout << " HERE!" << endl;
    else
        cout << endl;
    Room::situation_prompt(game_map, player);
}
