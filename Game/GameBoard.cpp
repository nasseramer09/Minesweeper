#include "GameBoard.h"


GameBoard::GameBoard(int row, int column, int mineNumbers):row(row), column(column), mineNumbers(mineNumbers), board(row, std::vector<Cell>(column)){
boardGenerator();
}

GameBoard::~GameBoard(){}

void GameBoard::boardGenerator(){
    std::srand(std::time(0));
    //minprna placeras slumpmässigt 

    for (int i = 0; i < mineNumbers; i++)
    {
        int r;
        int c;
        do
        {
           r=std::rand() % this -> row;
           c = std::rand() % this -> column;

        } while (board[r][c].isMine());
        board[r][c].placeMine();
    }
    //kollar hur antal angränsande minor
    numberOfBorderingMines();
}

void GameBoard::numberOfBorderingMines(){
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < column; c++)
        {
            if (!board[r][c].isMine()){

                int mineCount=0;

                for (int i = -1; i <= 1; i++)
                {
                    for (int j = -1; j <= 1; j++){
                        int nr= r +i;
                        int nc = c+j;
                        if (nr >= 0 && nr < row && nc >=0 && nc < column){
                            if (board[nr][nc].isMine()){
                                mineCount++;
                             
                            }
                            
                        }
                        
                    }
                    
                }
                board[r][c].setBorderingMines(mineCount);
                
            }
            
        }
        
    }
    
}

void GameBoard::boardDisplay(){
    std::cout<< " ";
    for (int c = 0; c < column; c++){
       
           std::cout << (char)('A' + c) << " ";
        }
        std::cout << std::endl; 


        for (int r = 0; r < row; r++){
            std::cout << r + 1 << " ";
            for (int c = 0; c < column; c++) {
                if (board[r][c].isRevealed()){
                    if (board[r][c].isMine()){
                        std::cout << " * ";
                    }else{
                        std::cout <<board[r][c].getBorderingMines()<< " ";
                    }
                    
                }else if (board[r][c].isMarked())
                {
                    std::cout<< " M ";
                }else{
                    std::cout << " _ ";
                }
                
            }
            std::cout << std::endl;
            
        }
        
}

bool GameBoard::revealCell(int r, int c){
    if (r>=0 && r < row && c >=0 && c < column && !board[r][c].isRevealed()){
        board[r][c].reveal();

        if (board[r][c].isMine())
        {
           return true;
        }
        
        if (board[r][c].getBorderingMines()==0 && !board[r][c].isMine()){
           for (int i = -1; i <= 1; i++){
            for (int j = -1; j <= 1; j++){
               revealCell(r + i, c + j);
            }
            
           }
           
        }
        
    }

    return false;
    
}

void GameBoard::markCell(int r, int c){
    if (r >= 0 && r < row && c >= 0 && c < column && !board[r][c].isRevealed())
    {
        board[r][c].mark();
    }
    
}

bool GameBoard::checkWin() const{
    for (int r = 0; r < row; r++)
    {
       for (int c = 0; c < column; c++)
       {
        if (!board[r][c].isMine() && !board[r][c].isRevealed())
        {
            return false;
        }
        
       }
    }
    return true;
}