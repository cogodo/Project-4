/**
 * Copyright 2019 University of Michigan EECS183
 *
 * test.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 * 
 * <#Name#> Colin Gordon, Christopher Sherbenou
 * <#Uniqname#> cogo, csherben
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
    test_game();

    return;
}

void test_position() {
    Position pos;
    Position pos2 = Position(0, 3);
    Position pos3 = Position('1', 'D');
    return;
}

void test_ship() {
    
    Ship ship;
    Ship ship2 = Ship(Position('1', 'C'), Position('1', 'E'));
    Ship ship3 = Ship(Position(0, 2), Position(2, 2));
    ship2.has_position(Position('1', 'D'));
    ship2.hit();
    ship2.hit();
    ship2.hit();
    ship2.hit();

    return;
}

void test_player() {
    // Write your tests here
    Player bob;
    Player carl = Player("Carl");
    carl.init_grid();
    bob.init_grid();
    carl.load_grid_file("grid3.txt");
    carl.print_grid();
    bob.load_grid_file("grid1.txt");
    bob.print_grid();
    carl.attack(bob, Position('7', 'A'));
    carl.attack(bob, Position('6', 'A'));
    carl.attack(bob, Position('5', 'A'));
    carl.attack(bob, Position('4', 'A'));
    carl.attack(bob, Position('3', 'A'));
    carl.attack(bob, Position('8', 'B'));
    carl.attack(bob, Position('8', 'C'));
    carl.attack(bob, Position('1', 'F'));
    carl.attack(bob, Position('1', 'G'));
    carl.attack(bob, Position('1', 'H'));
    carl.attack(bob, Position('1', 'A'));
    carl.attack(bob, Position('1', 'H'));
    carl.attack(bob, Position('3', 'E'));
    carl.attack(bob, Position('3', 'F'));
    carl.attack(bob, Position('3', 'G'));
    carl.attack(bob, Position('3', 'H'));
    carl.print_guess_grid();
    return;
}

void test_game() {
    Player bob;
    Player carl = Player("Carl");
    Game game1 = Game(carl, "grid1.txt", bob, "grid2.txt");
    cout << game1.get_p1().get_name() << endl;
    cout << game1.get_p2().get_name() << endl;
    game1.check_valid_move(game1.get_move(carl.get_name()));

    game1.start(EASY, MAX_ROUNDS);


    return;
}

