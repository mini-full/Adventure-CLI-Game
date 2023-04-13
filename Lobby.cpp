#include<iostream>
#include<vector>
#include<map>
#include "Room.h"
#include "Lobby.h"

void Lobby::situation_prompt(vector<vector<Room*> >& game_map, Player& player){
    cout << "$LOBBY$" << endl;
    cout << "#System#\n\tWelcome to the lobby." << endl;
    Room::situation_prompt(game_map, player);
}
