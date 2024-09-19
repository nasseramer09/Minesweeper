#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

class GameBoard{
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

GameBoard::GameBoard(int row, int column, int mineNumbers):row(row), column(column), mineNumbers(mineNumbers), board(row, std::vector<char>(column, '-')){
boardGenerator();
}

GameBoard::~GameBoard(){}

void GameBoard::boardGenerator(){
    std::srand(std::time(0));

    for (int i = 0; i < mineNumbers; i++)
    {
        int row;
        int column;
        do
        {
           row=std::rand() % this->row;
           column = std::rand() % this->column;

        } while (board[row][column]=='*');
        board[row][column]='*';
    }
    
}

void GameBoard::boardDisplay(){
    for (int i = 0; i < row; i++){
        for (int c = 0; c < column; c++){
           std::cout << board[i][c] << " ";
        }
        std::cout << std::endl;
    }
    
}
