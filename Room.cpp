#include<string>
#include<map>
#include<iostream>
#include <vector>
#include "Game.h"
#include "Room.h"

void Room::situation_prompt(vector<vector<Room*> >& game_map, Player& player){
    cout << "#System#\n\tThere are " << path.size() << " exits: \n\t";
    for (auto iter = path.begin(); iter != path.end(); iter++)
        cout << iter->first << "\t";
    cout << endl;
}

bool Room::meet_monster()const{
    if (has_mons){
        draw_monster();
        cout << "#Player#\n\tOhhhh Holly Jesus! It's the monster!\
 If I win him I can find the princess!" << endl;
        cout << "#Aside#\n\tYou fight with the monster, but you lose.\
 You are dead. Game over. Press any key to start a new game\n";
        return true;
    }
    return false;
}

bool Room::meet_princess()const{
    if (has_prin){
        draw_princess();
        cout << "#Aside#\n\tYou have met the princess!\n";
        cout << "#Player#\n\tI must bring her back safely\n";
        cout << "#System#\n\tNew goal: Go back to the Lobby following the game_map!" << endl;
        return true;
    }
    return false;
}
