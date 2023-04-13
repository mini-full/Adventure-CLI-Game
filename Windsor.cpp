#include<iostream>
#include<vector>
#include<map>
#include "Room.h"
#include "Windsor.h"

/**
 * @brief Nothing special happens in the Windsor room.
 * 
 * @param game_map 
 * @param player 
 */
void Windsor::situation_prompt(vector<vector<Room*> >& game_map, Player& player){
    cout << "$Windsor$\n#System#\n\t\
The abandoned Windsor Castle is magnificent but dilapidated." << endl;
    Room::situation_prompt(game_map, player);
}