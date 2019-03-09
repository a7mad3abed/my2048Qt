#ifndef BOARD_H
#define BOARD_H


#include <cstdlib>
#include <iostream>
#include <vector>
#include "cell.h"
#include <random>



extern int dimension;




class Board {
public:
    Board();
    int score;
    bool gameIsOver;
    void initBoard();
    std::vector<Cell> exportBorad()const;
    void left();
    void right();
    void up();
    void down();

private:
    int randVal();
    void newCell(int);
    bool noMove();
    int generateRandom(std::vector<int>& candidates);
    bool noFreeCells();

    void compressLeft();
    void compressRight();
    void compressDown();
    void compressUp();

    void joinLeft();
    void joinRight();
    void joinUp();
    void joinDown();


    void gameOver();
    void quit();
private:
    std::vector<Cell> mBoard;
    bool moved = false;
};


#endif // BOARD_H
