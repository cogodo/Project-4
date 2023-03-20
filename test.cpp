/**
 * Copyright 2019 University of Michigan EECS183
 *
 * test.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * Project 4: Battleship
 *
 * Contains functions for testing classes in the project. 
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "Position.h"
#include "Ship.h"
#include "Player.h"
#include "Game.h"
#include "utility.h"

using namespace std;


void test_position();
void test_ship();
void test_player();
void test_game();

void startTests() {
    test_position();
    test_ship();
    test_player();
    
    return;
}

void test_position() {
    // Write your tests here
    return;
}

void test_ship() {
    // Write your tests here
    return;
}

void test_player() {
    // Write your tests here
    Player bob;
    Position pos1('1','A');
    Position pos2('1','C');
    Position pos3('5', 'F');
    Position pos4('2','F');
    Ship ship1(pos1, pos2);
    Ship ship2(pos3, pos4);
    bob.init_grid();
   
    bob.add_ship(ship1);
    bob.add_ship(ship2);
    bob.print_grid();
   
    return;
}

