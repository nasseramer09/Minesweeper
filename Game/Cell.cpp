#include "Cell.h"

Cell::Cell(): mine(false), marked(false), revealed(false), borderingMines(0){}


bool Cell::isMine() const {
    return mine;
}

bool Cell::isMarked() const {
    return marked;
}

bool Cell::isRevealed() const {
    return revealed;
}

int Cell::getBorderingMines() const {
     return borderingMines;
}
void Cell::placeMine(){
    mine=true;
}

void Cell::mark(){
    marked=true;
}
void Cell::unMark(){
    marked=false;
}

void Cell::reveal(){
    revealed=true;
}
void Cell::setBorderingMines(int num){
    borderingMines = num;
}



