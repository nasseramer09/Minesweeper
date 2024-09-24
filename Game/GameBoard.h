#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Cell.h"

class GameBoard
{
private:
int row;
int column;
int mineNumbers;
std::vector<std::vector<Cell> > board;

public:
    GameBoard(int row, int column, int mineNumbers);
    ~GameBoard();
    void boardGenerator();
    void boardDisplay();
    bool revealCell(int r, int c);
    bool checkWin() const;
    void markCell(int r, int c);
    void numberOfBorderingMines();

};




