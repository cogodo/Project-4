/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Player.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * <#Name#> Colin Gordon, Christopher Sherbenou
 * <#Uniqname#> cogo, csherben
 *
 * Project 4: Battleship
 *
 * <#description#>
 */

#include <fstream>
#include <sstream>
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
    for (int i = 0; i < MAX_GRID_SIZE; i++) {
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
    char x = grid[row][col];
    return x;
}

char Player::get_guess_grid_at(int row, int col) {
    // TODO: write implementation here.
    char y = guess_grid[row][col];
    return y;
}

void Player::add_ship(Ship ship) {
    // TODO: write implementation here.

    if (num_ships == MAX_NUM_SHIPS) {
        return;
    }
    ships[num_ships] = ship;
    if (ship.is_horizontal()) {
        int row = ship.get_start().get_row();
        if (ship.get_start().get_col() < ship.get_end().get_col()) {
            for (int i = ship.get_start().get_col(); i <= ship.get_end().get_col(); i++) {
                grid[row][i] = SHIP_LETTER;
            }
        }
        else {
            for (int j = ship.get_end().get_col(); j <= ship.get_start().get_col(); j++) {
                grid[row][j] = SHIP_LETTER;
            }
        }
    }

    else {
        int col = ship.get_start().get_col();
        if (ship.get_start().get_row() < ship.get_end().get_row()) {
            for (int k = ship.get_start().get_row(); k <= ship.get_end().get_row(); k++) {
                grid[k][col] = SHIP_LETTER;
            }
        }
        else {
            if (ship.get_start().get_row() > ship.get_end().get_row()) {
                for (int x = ship.get_end().get_row(); x <= ship.get_start().get_row(); x++) {
                    grid[x][col] = SHIP_LETTER;
                }
            }
        }
    }
    num_ships++;
    remaining_ships++;
    return;
}

void Player::attack(Player& opponent, Position pos) {
    // TODO: write implementation here.
    int rowChoice = pos.get_row();
    int colChoice = pos.get_col();
    bool hit = false;
    int temp = 0;
    if (opponent.grid[rowChoice][colChoice] == HIT_LETTER) {
        cout << get_name() << " (" << rowChoice << "," << colChoice << ") " << "miss";
        cout << endl;
        return;
    }
    for (int i = 0; i < opponent.num_ships; i++) {
        if (opponent.ships[i].has_position(pos) && opponent.grid[rowChoice][colChoice] != HIT_LETTER) {
            hit = true;
            opponent.ships[i].hit();
            if (opponent.get_name() == "CPU") {
                guess_grid[rowChoice][colChoice] = HIT_LETTER;
            }
            opponent.grid[rowChoice][colChoice] = HIT_LETTER;
            if (opponent.ships[i].has_sunk()) {
                opponent.remaining_ships--;
                temp = i;
            }
        }
    }
    int rowVisual = rowChoice + 1;
    char colVisual = static_cast<char>(toupper(colChoice + 'A'));
    if (hit == true) {
        cout << get_name() << " " << "(" << rowVisual << "," << colVisual << ") " << "hit";
        cout << endl;
        if (opponent.ships[temp].has_sunk()) {
            announce_ship_sunk(ships[temp].get_size());
        }
    }
    else if (hit == false) {
        guess_grid[rowChoice][colChoice] = MISS_LETTER;
        opponent.grid[rowChoice][colChoice] = MISS_LETTER;
        cout << get_name() << " (" << rowVisual << "," << colVisual << ") " << "miss";
        cout << endl;
    }

    return;
}

void Player::announce_ship_sunk(int size) {
    // DONE
    if (size == 2) {
        cout << "Congratulations " << name << "! You sunk a Destroyer" << endl;
    }
    else if (size == 3) {
        cout << "Congratulations " << name << "! You sunk a Submarine" << endl;
    }
    else if (size == 4) {
        cout << "Congratulations " << name << "! You sunk a Battleship" << endl;
    }
    else if (size == 5) {
        cout << "Congratulations " << name << "! You sunk a Carrier" << endl;
    }
    return;
}

bool Player::load_grid_file(string filename) {
    // TODO: write implementation here.
    ifstream gridRead;
    gridRead.open(filename);
    if (!gridRead.is_open()) {
        return false;
    }
    Position shipStart;
    Position shipEnd;
    while (gridRead >> shipStart && gridRead >> shipEnd) {
        Ship ship(shipStart, shipEnd);
        add_ship(ship);

    }
    return true;
}

bool Player::destroyed() {
    // DONE
    if (remaining_ships == 0) {
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
