//
//  playMove.cpp
//  TicTacToe
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: write your code for playMove in this file

#include "globals.h"
#include "GameState.h"

void playMove(GameState& game_state) {
    game_state.set_moveValid(game_state.get_moveValid());
    if(game_state.get_moveValid() == 1){
        game_state.set_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn(), game_state.get_turn());
        game_state.set_winCode(game_state.get_turn());
        
    }
    game_state.set_gameOver(game_state.get_turn());
    game_state.set_turn(game_state.get_moveValid());
    return;
}

