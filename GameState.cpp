//
//  GameState.cpp
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

#include "globals.h"
#include "GameState.h"

GameState::GameState(){
    selectedRow = 0;
    selectedColumn = 0;
    moveValid = true;
    gameOver = false;
    winCode = 0;
    turn = true;
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < boardSize; j++){
            gameBoard[i][j] = 0;
        }
    }       
}

void GameState::set_selectedRow(int value){
    selectedRow = value;
    return;
}

void GameState::set_selectedColumn(int value){
    selectedColumn = value;
    return;
}



void GameState::set_gameBoard(int row, int col, int value){
    if(moveValid == true){
         if(value==1){
            gameBoard[row][col] = 1;  
        }else{
             gameBoard[row][col] = -1;
        }
    }
    return;
}

bool GameState::get_moveValid(){
    return moveValid;
}

void GameState::set_moveValid(bool move){
    if (gameBoard[selectedRow][selectedColumn] == 0){
        moveValid = 1;
    }else{
        moveValid = 0;
    }
    return;
}

bool GameState::get_turn(){
    return turn;
}
void GameState::set_turn(bool value){
    if (value == false){
        turn = turn;
    }else{
        turn =!turn;
    }
    return;
}

int GameState::get_gameBoard(int row, int col){
    return gameBoard[row][col];
}

int GameState::get_selectedRow(){
    return selectedRow;
}

int GameState::get_selectedColumn(){
    return selectedColumn;
}

void GameState::set_winCode(int value){
    if(value == 1){
        if ((get_gameBoard(0,0) == 1) && (get_gameBoard(0,1) == 1) && (get_gameBoard(0,2) == 1)){
            winCode = 1;
            return;
        }else if ((get_gameBoard(1,0) == 1) && (get_gameBoard(1,1) == 1) && (get_gameBoard(1,2) == 1)){
            winCode = 2;
            return;
        }else if ((get_gameBoard(2,0) == 1) && (get_gameBoard(2,1) == 1) && (get_gameBoard(2,2) == 1)){
            winCode = 3;
            return;
        }else if ((get_gameBoard(0,0) == 1) && (get_gameBoard(0,1) == 1) && (get_gameBoard(0,2) == 1)){
            winCode = 4;
            return;
        }else if ((get_gameBoard(0,1) == 1) && (get_gameBoard(1,1) == 1) && (get_gameBoard(2,1) == 1)){
            winCode = 5;
            return;
        }else if ((get_gameBoard(0,2) == 1) && (get_gameBoard(1,2) == 1) && (get_gameBoard(2,2) == 1)){
            winCode = 6;
            return;
        }else if ((get_gameBoard(0,0) == 1) && (get_gameBoard(1,1) == 1) && (get_gameBoard(2,2) == 1)){
            winCode = 7;
            return;
        }else if ((get_gameBoard(0,2) == 1) && (get_gameBoard(1,1) == 1) && (get_gameBoard(2,0) == 1)){
            winCode = 8;
            return;
        }else{
            return;
        }
    }
    if(value == 0){
        if ((get_gameBoard(0,0) == -1) && (get_gameBoard(0,1) == -1) && (get_gameBoard(0,2) == -1)){
            winCode = 1;
            return;
        }else if ((get_gameBoard(1,0) == -1) && (get_gameBoard(1,1) == -1) && (get_gameBoard(1,2) == -1)){
            winCode = 2;
            return;
        }else if ((get_gameBoard(2,0) == -1) && (get_gameBoard(2,1) == -1) && (get_gameBoard(2,2) == -1)){
            winCode = 3;
            return;
        }else if ((get_gameBoard(0,0) == -1) && (get_gameBoard(0,1) == -1) && (get_gameBoard(0,2) == -1)){
            winCode = 4;
            return;
        }else if ((get_gameBoard(0,1) == -1) && (get_gameBoard(1,1) == -1) && (get_gameBoard(2,1) == -1)){
            winCode = 5;
            return;
        }else if ((get_gameBoard(0,2) == -1) && (get_gameBoard(1,2) == -1) && (get_gameBoard(2,2) == -1)){
            winCode = 6;
            return;
        }else if ((get_gameBoard(0,0) == -1) && (get_gameBoard(1,1) == -1) && (get_gameBoard(2,2) == -1)){
            winCode = 7;
            return;
        }else if ((get_gameBoard(0,2) == -1) && (get_gameBoard(1,1) == -1) && (get_gameBoard(2,0) == -1)){
            winCode = 8;
            return;
        }else{
            return;
        }
    }
    return;
}

int GameState::get_winCode(){
    return winCode;
}

void GameState::set_gameOver(bool value){
    if(get_winCode() != 0){
        gameOver = true;
        return;
    }
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < boardSize; j++){
            if(get_gameBoard(i,j)== 0){
                gameOver = false;
                return;
            }else if (get_gameBoard(i,j)!=0){
                gameOver = true;
            }
        }
    }
    return;
}

bool GameState::get_gameOver(){
    return gameOver;
}