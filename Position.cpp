/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Position.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * <#Name#>Colin Gordon, Chris Sherbenou
 * <#Uniqname#>cogo, csherben
 *
 * Project 4: Battleship
 *
 * <#description#> Represent a set of coordinates on battleship grid
 */

#include "Position.h"
#include "utility.h"
#include <iostream>

Position::Position() {
    // TODO: write implementation here.
     row = 0;
     col = 0;
}

Position::Position(int row_in, int col_in) {
    // TODO: write implementation here.
    row = row_in;
    row = check_range(row);
    col = col_in;
    col = check_range(col);
}

Position::Position(char row_in, char col_in) {
    // TODO: write implementation here.
    row = row_in - '1';
    row = check_range(row);
    col = toupper(col_in) - 'A';
    col = check_range(col);
}

int Position::get_row() {
   
    return row;
}

void Position::set_row(int row_in) {
    // TODO: write implementation here.
    row = row_in;
    row = check_range(row);
    return;
}

int Position::get_col() {
    // TODO: write implementation here.
    
    return col;
}

void Position::set_col(int col_in) {
    // TODO: write implementation here.
    col = col_in;
    col = check_range(col);
    return;
}

void Position::read(istream &is) {
    // TODO: write implementation here.
    char junk;
    char temp;
    is >> row;
    if(is.fail()) {
        is.clear();
        is >> junk >> row >> junk >> temp >> junk;
        col = int(temp);
    }
    else {
        is >> temp;
        col = int(temp);
    }
    row = row - 1;
    row = check_range(row);
    col = toupper(static_cast<char>(col)) - 'A';
    col = check_range(col);
    return;
}

void Position::write(ostream &os) {
    // TODO: write implementation here.
    os << "(" << (row + 1) << "," << (static_cast<char>(col + 'A')) << ")";
    return;
}

int Position::check_range(int val) {
    // TODO: write implementation here.
        if(val <= 7 && val >= 0) {
        return val;
    }
    else if(val < 0) {
        return 0;
    }
    else {
        return 7;
    }
}


// Your code goes above this line.
// Don't change the implementations below!

istream &operator>>(istream &is,  Position &pos) {
    pos.read(is);
    return is;
}

ostream &operator<<(ostream &os, Position pos) {
    pos.write(os);
    return os;
}

