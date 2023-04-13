#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<ctime>
#include<cstdlib>
#include "Player.h"

/**
 * @brief Move the player to the next room.
 * The checking for the validity of the move is done in the Game class.
 * 
 * @param direction 
 * @param map 
 */
void Player::move(string direction){
    if(direction.compare("South") == 0){
        curr_row++;
    }
    else if (direction.compare("North") == 0){
        curr_row--;
    }
    else if (direction.compare("East") == 0){
        curr_col++;
    }
    else if (direction.compare("West") == 0){
        curr_col--;
    }
}
