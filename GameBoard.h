#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

class GameBoard
{
private:
int row;
int column;
int mineNumbers;
std::vector<std::vector<char> > board;

public:
    GameBoard(int row, int column, int mineNumbers);
    ~GameBoard();
    void boardGenerator();
    void boardDisplay();
};




