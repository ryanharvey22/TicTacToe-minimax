//
//  ttt.h
//  TicTacToe
//
//  Created by Ryan Harvey on 11/16/20.
//  Copyright © 2020 Ryan Harvey. All rights reserved.
//

#ifndef ttt_h
#define ttt_h

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

const char human = 'X';
const char ai = 'O';

struct Coords {
    
    int x, y, score;
    
};

class Game {
    
    char state[3][3];
    int score = 0;
        
public:
    
    Game();
            
    char getWinner();
            
    bool boardIsFull();
    
    bool gameOver();
            
    void printboard();
            
    void computerMove();
    
    void humanMove();
            
    Coords minimax(bool isMaximizer);
            
    //Coords evaluate(char board[3][3]);
    
    void playGame();
};

#endif /* ttt_h */
