#ifndef __LOBBY_H__
#define __LOBBY_H__

class Lobby : public Room{
    public:
    void print_room() const{ cout << "Lobby\t"; }
    void situation_prompt(vector<vector<Room*> >& game_map, Player &player);
};

#endif