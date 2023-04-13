#ifndef __ROOM_H__
#define __ROOM_H__

using namespace std;
class Player;
class Room{
    private:
    bool has_mons = false;
    bool has_prin = false;
    bool visited = false;
    public:
    map<string, pair<int, int> > path; // path to other rooms, if valid, key is direction, value is pair of row and col
    virtual void situation_prompt(vector<vector<Room*> >& game_map, Player& player); // prompts the player
    virtual void print_room()const = 0; // prints the room name, must be overloaded
    inline bool has_princess()const{ return has_prin; }
    inline bool has_monster()const{ return has_mons; }
    inline void set_princess(bool has){ has_prin = has; }
    inline void set_monster(bool has){ has_mons = has; }
    inline bool has_room(string direction)const{ return path.find(direction) != path.end(); }
    inline void insert_path(string direction, int row, int col){ path[direction] = pair<int, int>(row, col); }
    inline bool visited_room()const{ return visited; }
    inline void set_visited(bool visit){ visited = visit; }
    bool meet_princess()const;
    bool meet_monster()const;
};

#endif