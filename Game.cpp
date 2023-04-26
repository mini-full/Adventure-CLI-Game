#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<ctime>
#include<cstdlib>

#include "Room.h"
#include "Player.h"
#include "Lobby.h"
#include "Windsor.h"
#include "Dungeon.h"
#include "Game.h"

using namespace std;

/**
 * @brief To let the friend know where the monster is.
 * 
 */
extern int monster_r, monster_c;


void draw_monster(){
    cout << MONSTER << endl;
}

void draw_princess(){
    cout << PRINCESS << endl;
}

void welcome(){
    cout << WELCOME << endl;
}

/**
 * @brief Check if the position is in the map.
 * 
 * @param row 
 * @param col 
 * @return true 
 * @return false 
 */
bool in_map(int row, int col){
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE;
}

/**
 * @brief Randomly create a new room.
 * 3/4 chance to create a Windsor room.
 * 1/4 chance to create a Dungeon room.
 * 
 * @return Room* 
 */
Room* create_room(){
    int rnd = rand() % 4;
    if (rnd){
        return new Windsor;
    }
    else return new Dungeon;
}

/**
 * @brief Recursively initialize the map with rooms,
 * garantee that there is a path from the start to the end
 * and the map are connected.
 *
 * @param game_map
 * @param row
 * @param col
 * @return int
 */
int map_init(vector<vector<Room*> >& game_map, int row, int col){
    static int count = 0; // Record the number of rooms created
    // a place that can be reached in one step
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    for (int i = 0;i < 4; ++i){
        int next_row = row + dx[i];
        int next_col = col + dy[i];
        if (in_map(next_row, next_col) && game_map[next_row][next_col] == nullptr && (rand()%2)){
            game_map[next_row][next_col] = create_room();
            map_init(game_map, next_row, next_col);
            ++count;
        }
        if (count > MAX_ROOM) break;
    }
    int ret = count;
    // skip the lobby
    if (row == SIZE - 1 && col == SIZE / 2) count = 0;
    return ret;
}

/**
 * @brief Initialize the game.
 * Randomly create a map with rooms.
 * Randomly place the monster and princess.
 * Inserting the paths.
 * 
 * @param game_map 
 */
void game_init(vector<vector<Room*> >& game_map){
    system("clear");
    welcome();
    int num = 0;
    // a place that can be reached in one step
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    int monster_x, monster_y, princess_x, princess_y;
    while (num < 7){
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                game_map[i][j] = nullptr;
            }
        }
        // here SIZE - 1 and SIZE / 2 are to make sure lobby is in the middle bottom
        game_map[SIZE - 1][SIZE / 2] = new Lobby;
        num = map_init(game_map, SIZE - 1, SIZE / 2);
    }

    // Randomly place the monster and princess
    // make sure the monster and princess are not in the same room
    // make sure the monster and princess are not in the lobby
    // make sure the monster and princess are not in a room that doesn't exist.
    do{
        monster_x = rand() % SIZE;
        monster_y = rand() % SIZE;
    } while (game_map[monster_x][monster_y] == nullptr
        || (monster_x == SIZE - 1 && monster_y == SIZE / 2));
    do{
        princess_x = rand() % SIZE;
        princess_y = rand() % SIZE;
    } while (game_map[princess_x][princess_y] == nullptr
        || (princess_x == SIZE - 1 && princess_y == SIZE / 2)
        || (princess_x == monster_x && princess_y == monster_y));
    game_map[monster_x][monster_y]->set_monster(true);
    // to public the position of the monster
    monster_r = monster_x;
    monster_c = monster_y;
    game_map[princess_x][princess_y]->set_princess(true);
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if (game_map[i][j]){
                for (int k = 0; k < 4; k++){
                    if (in_map(i + dx[k], j + dy[k]) && (game_map[i + dx[k]][j + dy[k]])){
                        if (k == 0) game_map[i][j]->insert_path("East", dx[k], dy[k]);
                        else if (k == 1) game_map[i][j]->insert_path("West", dx[k], dy[k]);
                        else if (k == 2) game_map[i][j]->insert_path("South", dx[k], dy[k]);
                        else if (k == 3) game_map[i][j]->insert_path("North", dx[k], dy[k]);
                    }
                }
            }
        }
    }
}

/**
 * @brief Show the map to the player.
 * 
 * @param game_map 
 * @param player 
 */
void show_map(vector<vector<Room*> >& game_map, Player& player){
    cout << "$MAP$" << endl;
    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};
    for (int i = 0; i < SIZE; i++){
        cout << "\t";
        for (int j = 0; j < SIZE; j++){
            if (game_map[i][j] == nullptr){
                cout << " \t \t";
            }
            else if (player.visited[i][j]){
                game_map[i][j]->print_room();
                // if the player is in the room
                if (i == player.get_row() && j == player.get_col()){
                    cout << "<-";
                }
                cout << "\t";
            }
            else{
                cout << " \t \t";
            }
        }
        cout << endl;
    }
    cout << endl;
}

/**
 * @brief Show the map to the admin.
 * 
 * @param game_map 
 * @param player 
 */
void admin_map(vector<vector<Room*> >& game_map, Player player){
    cout << "$ADMIN MAP$" << endl;
    for (int i = 0; i < SIZE; i++){
        cout << "\t";
        for (int j = 0; j < SIZE; j++){
            if (game_map[i][j] == nullptr){
                cout << "none\t \t";
            }
            else{
                game_map[i][j]->print_room();
                if(game_map[i][j]->has_monster()) cout<< "M";
                if(game_map[i][j]->has_princess()) cout<< "P";
                if(i == player.get_row() && j == player.get_col()) cout << "<-";
                cout << "\t";
            }
        }
        cout << endl;
    }
    cout << endl;
}

/**
 * @brief Get command and pre-process it.
 * 
 * @return string 
 */
string get_command(){
    string cmd;
    getline(cin, cmd);
    if (cmd[0] >= 'a' && cmd[0] <= 'z'){
        cmd[0] += 'A' - 'a';
    }
    // remove the proceeding "Go "
    if (cmd.substr(0, 3).compare("Go ") == 0){
        cmd = cmd.substr(3);
        if (cmd[0] >= 'a' && cmd[0] <= 'z'){
            cmd[0] += 'A' - 'a';
        }
    }
    return cmd;
}

/**
 * @brief This is to interact with the player for every turn
 * If and only if the player moves, this turn will be finished.
 * 
 * @param game_map 
 * @param player 
 * @return true This turn is not finished
 * @return false This turn is finished
 */
bool interact(vector<vector<Room*> >& game_map, Player& player){
    string cmd = get_command();
    if (cmd.compare("Map") == 0){
        show_map(game_map, player);
    }
    else if(cmd.compare("Admin") == 0){
        admin_map(game_map, player);
    }
    else if (game_map[player.get_row()][player.get_col()]->has_room(cmd)){
        player.move(cmd);
        player.visit(player.get_row(), player.get_col());
        return false;
    }
    else{
        cout << "#System#\n\tYou cannot do that, try annother command\n";
        cout << "\tMap: get the game_map of the visited place\n";
        cout << "\tGo [orientation]: Move to the next room(if exists)" << endl;
    }
    return true;
}

/**
 * @brief CHeck if the player meets a monster or the princess.
 * 
 * @param game_map 
 * @param player 
 * @return true if monster is met, game over
 * @return false 
 */
bool check_meeting(vector<vector<Room*> >& game_map, Player& player){
// chekcs will be made inside meet_monster, and dialogues will shown inside it.
    if (game_map[player.get_row()][player.get_col()]->meet_monster()){
        getchar();
        return true;
    }
    if (game_map[player.get_row()][player.get_col()]->meet_princess()){
        player.get_princess();
        game_map[player.get_row()][player.get_col()]->set_princess(false);
    }
    return false;
}

/**
 * @brief Check if the player won the game
 * i.e. to check if the player is in the lobby with princess.
 * 
 * @param game_map 
 * @param player 
 * @return true 
 * @return false 
 */
bool check_lobby(vector<vector<Room*> >& game_map, Player& player){
    if (player.get_row() == SIZE - 1 && player.get_col() == SIZE / 2){
        if (player.has_princess()){
            cout << WIN << endl;
            cout << "#System#\n\tYou have found the princess and saved the world!" << endl;
            cout << "\tYou win! Press any key to start a new game!" << endl;
            getchar();
            return false;
        }
    }
    return true;
}

void play(){
    vector<vector<Room*> > game_map(SIZE, vector<Room*>(SIZE));
    Player player(SIZE - 1, SIZE / 2);
    // Starts at the lobby
    player.visit(SIZE - 1, SIZE / 2);
    srand((unsigned)time(0));
    game_init(game_map);
    getchar();
    while (1){
        system("clear");
        cout << endl;
        if(check_meeting(game_map, player)) break;
        if (!check_lobby(game_map, player)) break;
        game_map[player.get_row()][player.get_col()]->situation_prompt(game_map, player);
        while (1){
            if (!interact(game_map, player)) break;
        }
    }
}
