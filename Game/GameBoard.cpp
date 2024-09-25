#include "GameBoard.h"


GameBoard::GameBoard(int row, int column, int mineNumbers):row(row), column(column), mineNumbers(mineNumbers), board(row, std::vector<Cell>(column)){
boardGenerator();
}

GameBoard::~GameBoard(){}

void GameBoard::boardGenerator(){
    std::srand(std::time(0));
    //minprna placeras slumpmässigt 

    for (int i = 0; i < mineNumbers; i++){
        int r, c;
        do{
           r=std::rand() % this -> row;
           c = std::rand() % this -> column;

        } while (board[r][c].isMine());
        board[r][c].placeMine();
    }
    //kollar hur antal angränsande minor
    numberOfBorderingMines();
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
                //referens av cell
                Cell& cell = board[r][c];

                if (cell.isRevealed()){
                    if (cell.isMine()){
                        std::cout << " * ";
                        }
                        else {
                        std::cout <<cell.getBorderingMines()<< " ";
                        }
                    } 
                        else if (cell.isMarked()){
                        std::cout<< " M ";
                        }
                        else{
                            std::cout << " _ ";
                        }
                    }
                std::cout << std::endl;
            }   
    }

void GameBoard::numberOfBorderingMines(){
    //r = index i raden
    for (int r = 0; r < row; r++) {

        //c = kolmunindexen 
        for (int c = 0; c < column; c++){
            Cell& cell = board[r][c];

            if (!cell.isMine()){

                int mineCount = 0;
                
                for (int i = -1; i <= 1; i++){
                    for (int j = c -1; j <= c + 1; j++){
                        if (i >= 0 && i < row && j >= 0 && j < column){
                            if (board[i][j].isMine()){
                                mineCount++;
                            } 
                        } 
                    }
                }
                cell.setBorderingMines(mineCount);  
            } 
        }
    }
}

bool GameBoard::revealCell(int r, int c){
    if (r >= 0 && r < row && c >= 0 && c < column && !board[r][c].isRevealed()){
       Cell& cell = board[r][c];
        cell.reveal();

        if (cell.isMine()){
           return true;
        }
        
        if (cell.getBorderingMines()==0 && !cell.isMine()){
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
    if (r >= 0 && r < row && c >= 0 && c < column && !board[r][c].isRevealed()){
        board[r][c].mark();
    }
    
}

bool GameBoard::checkWin() const{
    for (int r = 0; r < row; r++) {
       for (int c = 0; c < column; c++){
        if (!board[r][c].isMine() && !board[r][c].isRevealed()){
            return false;
        }
       }
    }
    return true;
}