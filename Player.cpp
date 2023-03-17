/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Player.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * <#Name#> Colin Gordon
 * <#Uniqname#> cogo
 *
 * Project 4: Battleship
 *
 * <#description#>
 */

#include <fstream>

#include "Player.h"


Player::Player() {
    // TODO: write implementation here.
    name = "";
    num_ships = 0;
    remaining_ships = 0;
    init_grid();
}

Player::Player(string name_val) {
    // TODO: write implementation here.
    name = name_val;
    num_ships = 0;
    remaining_ships = 0;
    init_grid();
}

void Player::init_grid() {
    // TODO: write implementation here.
    for(int i = 0; i < MAX_GRID_SIZE; i++) {
        for (int k = 0; k < MAX_GRID_SIZE; k++) {
            grid[i][k] = EMPTY_LETTER;
            guess_grid[i][k] = EMPTY_LETTER;
        }
    }
    return;
}

string Player::get_name() {
    // TODO: write implementation here.
    return name;

}

int Player::get_num_ships() {
    // TODO: write implementation here.
    
    return num_ships;
}

int Player::get_remaining_ships() {
    // TODO: write implementation here.
    return remaining_ships;
}

char Player::get_grid_at(int row, int col) {
    // TODO: write implementation here.
    return grid[row][col];
}

char Player::get_guess_grid_at(int row, int col) {
    // TODO: write implementation here.
    return guess_grid[row][col];
}

void Player::add_ship(Ship ship) {
    // TODO: write implementation here.
    if(num_ships == MAX_NUM_SHIPS) {
        return;
    }
    ships[num_ships] = ship;
    if(ship.is_horizontal()) {
       
        for(int i = 0; i < ship.get_size(); i++) {
           
        }
    }
    num_ships++;
    remaining_ships++;
    return;
}

void Player::attack(Player &opponent, Position pos) {
    // TODO: write implementation here.
    int rowChoice = pos.get_row();
    int colChoice = pos.get_col();
    if(opponent.get_grid_at(rowChoice, colChoice) == SHIP_LETTER) {
        guess_grid[rowChoice][colChoice] = HIT_LETTER;
        opponent.grid[rowChoice][colChoice] = HIT_LETTER;
        cout << get_name() << " " << "(" << rowChoice << "," << colChoice << ") " << "hit";
    }
    else {
        guess_grid[rowChoice][colChoice] = MISS_LETTER;
        opponent.grid[rowChoice][colChoice] = MISS_LETTER;
        cout << get_name() << " " << "(" << rowChoice << "," << colChoice << ") " << "miss";
    }
    return;
}

void Player::announce_ship_sunk(int size) {
    // TODO: write implementation here.
    if(size == 2){
        cout << "Congratulations " << name << "! You sunk a Destroyer";
    }
    else if(size == 3) {
        cout << "Congratulations " << name << "! You sunk a Submarine";
    }
    else if(size == 4) {
        cout << "Congratulations " << name << "! You sunk a Battleship";
    }
    else if(size == 5) {
        cout << "Congratulations " << name << "! You sunk a Carrier";
    }
    return;
}

bool Player::load_grid_file(string filename) {
    // TODO: write implementation here.
    
    return false;
}

bool Player::destroyed() {
    // TODO: write implementation here.
    if(num_ships == 0) {
        return true;
    }
    return false;
}

// Your code goes above this line.
// Don't change the implementations below!

void Player::print_grid() {
    ::print_grid(grid);
}

void Player::print_guess_grid() {
    ::print_grid(guess_grid);
}
