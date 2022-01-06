//
//  TicTacToe.cpp
//  TicTacToe
//
//  Created by Ryan Harvey on 11/16/20.
//  Copyright © 2020 Ryan Harvey. All rights reserved.
//


#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include "ttt.h"

using namespace std;

Game::Game(){
    
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            
            state[x][y] = ' ';
            
        }
    }
}
    
char Game::getWinner(){
    
     for(int x = 0; x < 3; x++){
         
         if(state[x][0] == ai && state[x][1] == ai && state[x][2] == ai){
             return ai;
         }
         if(state[x][0] == human && state[x][1] == human && state[x][2] == human){
             return human;
         }
     }
         
     for(int y = 0; y < 3; y++){
             
         if(state[0][y] == ai && state[1][y] == ai && state[2][y] == ai){
             return ai;
         }
         if(state[0][y] == human && state[1][y] == human && state[2][y] == human){
             return human;
         }
     }
     
     if(state[0][0] == ai && state[1][1] == ai && state[2][2] == ai){
         return ai;
     }
     if(state[0][0] == human && state[1][1] == human && state[2][2] == human){
         return human;
     }
     if(state[0][2] == ai && state[1][1] == ai && state[2][0] == ai){
         return ai;
     }
     if(state[0][2] == human && state[1][1] == human && state[2][0] == human){
         return human;
     }
     return 'T';
}
    
bool Game::boardIsFull(){
    
    for(int x = 0; x < 3; x++){
           for(int y = 0; y < 3; y++){
               
               if(state[x][y] == ' '){
                   return false;
               }
           }
       }
       return true;
}

bool Game::gameOver(){
    
    if(getWinner() != 'T')
        return true;
    if(boardIsFull())
        return true;
    return false;
}
    
void Game::printboard(){
    
    cout <<"\n";
    cout << state[0][0] << " | " << state[0][1] << " | " << state[0][2] << endl;
    cout << "\n";
    cout << state[1][0] << " | " << state[1][1] << " | " << state[1][2] << endl;
    cout << "\n";
    cout << state[2][0] << " | " << state[2][1] << " | " << state[2][2] << endl;
    cout << "\n\n";
}
    
void Game::computerMove(){
    
    cout << "The computers move:" << endl;
    
    Coords move;
    
    move = minimax(false);
    
    state[move.x][move.y] = ai;
    
    printboard();
}

void Game::humanMove(){
    
    bool esketit = true;
    
    int x, y;
    
    while(esketit){
        
        cout << "\nEnter in coordinates of your move" << endl;
        cout << "Row: ";
        cin >> x;
        cout << "Col: ";
        cin >> y;
        
        
    
        if(x < 3 && y < 3){
            if(state[x][y] == ' '){
                state[x][y] = human;
                esketit = false;
            }
            else{
                cout << "Chose an unoccupied cell" << endl;
            }
        }
        else{
            cout << "Enter a number from 0 to 2" << endl;
        }
    }
    
    cout << "Your Move: " << endl;
    
    printboard();
    
}

Coords Game::minimax(bool isMaximizer){
    
    Coords bestMove;
    
    if(getWinner() == ai){
        bestMove.score = -10;
        return bestMove;
    }
    
    if(getWinner() == human){
        bestMove.score = 10;
        return bestMove;
    }
    
    if(boardIsFull()){
        bestMove.score = 0;
        return bestMove;
    }
    
    if(isMaximizer){
        
        bestMove.score = -1000;
        
        for(int x = 0; x < 3; x++){
            for(int y = 0; y < 3; y++){
                
                if(state[x][y] == ' '){
                    
                    state[x][y] = human;
                    Coords tempMove = minimax(false);
                    if(tempMove.score > bestMove.score){
                        bestMove.score = tempMove.score;
                        bestMove.x = x;
                        bestMove.y = y;
                        
                    }
                    state[x][y] = ' ';
                }
            }
        }
    }
    else{
        
        bestMove.score = 1000;
        
        for(int x = 0; x < 3; x++){
            for(int y = 0; y < 3; y++){
                
                if(state[x][y] == ' '){
                    
                    state[x][y] = ai;
                    Coords tempMove = minimax(true);
                    if(tempMove.score < bestMove.score){
                        bestMove.score = tempMove.score;
                        bestMove.x = x;
                        bestMove.y = y;
                    }
                    state[x][y] = ' ';
                }
            }
        }
    }
    return bestMove;
}

void Game::playGame(){
    
    cout << "*** Welcome to the imposible TicTicToe game ***" << endl;
    
    while(!gameOver()){
        
        humanMove();
        if(gameOver())
            break;
        
        computerMove();
        if(gameOver())
            break;
    }
    
    if(getWinner() == human)
        cout << "You Won!" << endl;
    else if(getWinner() == ai)
        cout << "The Computer Won!" << endl;
    else
        cout << "The game is a Tie" << endl;
    return;
}
