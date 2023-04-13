#ifndef __DUNGEON_H__
#define __DUNGEON_H__

extern int monster_c, monster_r;
using namespace std;

class Dungeon: public Room{
    public:
    void print_room()const{ cout << "Dungeon\t"; }
    void situation_prompt(vector<vector<Room* > >& game_map, Player& player);

};

#endif