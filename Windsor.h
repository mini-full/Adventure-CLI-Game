#ifndef __WINDSOR_H__
#define __WINDSOR_H__

class Windsor: public Room{
    public:
    void print_room()const{ cout << "Windsor\t"; }
    void situation_prompt(vector<vector<Room*> >& GameMap, Player& player);
};

#endif