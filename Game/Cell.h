#ifndef CELL_H
#define CELL_H

class Cell
{
private:
    bool mine; //kollar om cellen inehåller en mina 
    bool marked; //kollar om cellen är markerad
    bool revealed; //kollar om cellen har öppnats/avslöjats
    int borderingMines;
    

public:
    Cell();

    bool isMine() const;
    bool isMarked() const;
    bool isRevealed() const;
    int getBorderingMines() const;
    void placeMine();
    void mark();
    void unMark();
    void reveal();
    void setBorderingMines(int num);

   
    
};

#endif