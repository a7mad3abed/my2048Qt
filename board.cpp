#include "board.h"



int dimension = 4;

std::random_device rd;
std::mt19937 rng(rd());

Board::Board():
    score {0},
    gameIsOver{false}
{}

int Board::randVal() {
    std::vector<int> numbersToChooseFrom;
    for (int i = 0; i < 20; i++) {
        if (i == 4) numbersToChooseFrom.push_back(i);
        if (i != 4) numbersToChooseFrom.push_back(2);
    }

    std::uniform_int_distribution<int> uni(0, numbersToChooseFrom.size() - 1);
    auto random_integer = uni(rng);

    return numbersToChooseFrom[random_integer];


}

void Board::compressLeft() {
    for (int x = 0; x < dimension;  x++) {
        for (int i = 0; i < dimension; i++) {
            if (mBoard[x*dimension+i].value() == 0) {
                for (int j = i + 1; j < dimension; j++) {
                    if (mBoard[x*dimension+j].value() > 0) {
                        mBoard[x*dimension+i].setValue(mBoard[x*dimension+j].value());
                        mBoard[x*dimension+j].setValue(0);
                        moved = true;
                        break;
                    }
                }
            }
        }
    }
}

void Board::joinLeft() {
    for (int x = 0; x < dimension;  x++) {
        for (int i = 0; i < dimension-1; i++) {
                    if (mBoard[x*dimension+i].value() == mBoard[x*dimension+i+1].value() && mBoard[x*dimension+i].value() != 0) {
                        mBoard[x*dimension+i].setValue(mBoard[x*dimension+i].value()*2);
                        score += mBoard[x*dimension + i].value();
                        mBoard[x*dimension+i+1].setValue(0);
                        moved = true;
                    }
        }
    }

}

void Board::compressUp() {
    for (int x = 0; x < dimension;  x++) {
        for (int i = 0; i < dimension; i++) {
            if (mBoard[x+i*dimension].value() == 0) {
                for (int j = i + 1; j < dimension; j++) {
                    if (mBoard[x+j*dimension].value() > 0) {
                        mBoard[x+i*dimension].setValue(mBoard[x+j*dimension].value());
                        mBoard[x+j*dimension].setValue(0);
                        moved = true;
                        break;
                    }
                }
            }
        }
    }
}

void Board::joinUp() {
    for (int x = 0; x < dimension;  x++) {
        for (int i = 0; i < dimension-1; i++) {
            if (mBoard[x+i*dimension].value() == mBoard[x+(i+1)*dimension].value() && mBoard[x+i*dimension].value() != 0) {
                        mBoard[x+i*dimension].setValue(mBoard[x+(i+1)*dimension].value()*2);
                        score += mBoard[x + i * dimension].value();
                        mBoard[x+(i+1)*dimension].setValue(0);
                        moved = true;
            }
        }
    }

}

void Board::compressRight() {
    for (int x = 0; x < dimension; x++) {
        for (int i = dimension - 1; i > 0; i--) {
            if (mBoard[x*dimension+i].value() == 0) {
                for (int j = i - 1; j >= 0; j--) {
                    if (mBoard[x*dimension+j].value() > 0) {
                        mBoard[x*dimension+i].setValue(mBoard[x*dimension+j].value());
                        mBoard[x*dimension+j].setValue(0);
                        moved = true;
                        break;
                    }
                }
            }
        }
    }
}

void Board::joinRight() {
    for (int x = 0; x < dimension; x++) {
        for (int i = dimension - 1; i > 0; i--) {
            if (mBoard[x*dimension+i].value() == mBoard[x*dimension+i-1].value() && mBoard[x*dimension+i].value() != 0) {
                mBoard[x*dimension+i].setValue(mBoard[x*dimension+i-1].value()*2);
                score += mBoard[x*dimension + i].value();
                mBoard[x*dimension+i-1].setValue(0);
                moved = true;
            }
        }
    }

}

void Board::compressDown() {
    for (int x = 0; x < dimension; x++) {
        for (int i = dimension - 1; i > 0; i--) {
            if (mBoard[x+i*dimension].value() == 0) {
                for (int j = i - 1; j >= 0; j--) {
                    if (mBoard[x+j*dimension].value() > 0) {
                        mBoard[x+i*dimension].setValue(mBoard[x+j*dimension].value());
                        mBoard[x+j*dimension].setValue(0);
                        moved = true;
                        break;
                    }
                }
            }
        }
    }
}

void Board::joinDown() {
    for (int x = 0; x < dimension; x++) {
        for (int i = dimension - 1; i > 0; i--) {
            if (mBoard[x+i*dimension].value() == mBoard[x+(i-1)*dimension].value() && mBoard[x+i*dimension].value() != 0) {
                mBoard[x+i*dimension].setValue(mBoard[x+(i-1)*dimension].value()*2);
                score += mBoard[x + i * dimension].value();
                mBoard[x+(i-1)*dimension].setValue(0);
                moved = true;
            }
        }
    }

}

void Board::left()
{
    compressLeft();
    joinLeft();
    compressLeft();


    if (moved) {
        newCell(randVal());
        moved = false;
    }

    if (noMove() && noFreeCells()) gameOver();


}

void Board::right()
{
    compressRight();
    joinRight();
    compressRight();

    if (moved) {
        newCell(randVal());
        moved = false;
    }

    if (noMove() && noFreeCells()) gameOver();

}

void Board::up() {
    compressUp();
    joinUp();
    compressUp();



    if (moved) {
        newCell(randVal());
        moved = false;
    }

    if (noMove() && noFreeCells()) gameOver();

}

void Board::down() {
    compressDown();
    joinDown();
    compressDown();
    if (moved) {
        newCell(randVal());
        moved = false;
    }

    if (noMove() && noFreeCells()) gameOver();

}

void Board::initBoard() {
    for (int i = 0; i < 16; i++) {
        Cell cell;
        mBoard.push_back(cell);
    }
    newCell(2);
    newCell(2);

}

void Board::gameOver() {
    gameIsOver = true;
}

void Board::quit() {
    exit(0);
}

bool Board::noMove() {
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension-1; j++) {
            if (mBoard[i*dimension + j].value() == mBoard[i*dimension + j + 1].value()) return false;
        }

    }

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension - 1; j++) {
            if (mBoard[i + j * 4].value() == mBoard[i + (j + 1) * 4].value()) return false;
        }
    }

    return true;
}

int Board::generateRandom(std::vector<int>& candidates) {
    std::uniform_int_distribution<int> uni(0, candidates.size() - 1);
    auto random_integer = uni(rng);

    return candidates[random_integer];
}



bool Board::noFreeCells() {
    std::vector<int> freeCells;
    for (int i = 0; i < mBoard.size(); i++) {
        if (mBoard[i].isFree()) freeCells.push_back(i);
    }
    return (freeCells.size() == 0);
}

void Board::newCell(int val) {

    std::vector<int> freeCells;
    for (int i = 0; i < mBoard.size(); i++) {
        if (mBoard[i].isFree()) freeCells.push_back(i);
    }

    if (noFreeCells() && !noMove()) return;

    int mIndex = generateRandom(freeCells);
    mBoard[mIndex].setValue(val);
}

std::vector<Cell> Board::exportBorad() const
{
    return mBoard;
}


