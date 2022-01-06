//
//  TicTacToe.hpp
//  TicTacToe
//
//  Created by Ryan Harvey on 11/16/20.
//  Copyright © 2020 Ryan Harvey. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

const char human = 'X';
const char ai = 'O';

enum Turn {HUMAN, AI};

struct Coords {
    
    int x, y;
    
};

class Game {
    
    char state[3][3];
        
public:
        
    Game(){
        
        Game();
            
        char getCell(int x, int y);
            
        void setCell(int x, int y, char player);
            
        char getWinner();
            
        bool boardIsFull();
            
        void printboard();
            
        void computerMove();
            
        int minimax(char board[3][3], bool isMaximizer);
            
        Coords evaluate(char board[3][3]);
    }
};
