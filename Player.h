#ifndef __PLAYER_H__
#define __PLAYER_H__

using namespace std;

class Room;
class Player{
    private:
    int curr_row;
    int curr_col;
    bool got_princess = false;

    public:
    Player(int row, int col): curr_row(row), curr_col(col){};
    bool visited[5][5] = { {false} };
    void visit(int row, int col) { visited[row][col] = true; }
    void move(string direction);
    inline int get_row()const{ return curr_row; }
    inline int get_col()const{ return curr_col; }
    inline void get_princess(){ got_princess = true; }
    inline bool has_princess() const{ return got_princess; }
};


#endif