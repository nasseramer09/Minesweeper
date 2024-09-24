#include <iostream>
#include "GameBoard.h"
int main(){
    int rows;
    int columns;
    int mines;


    std::cout <<" Type how many rows do you want to have: \n";
    std::cin >> rows;

    std::cout <<" Type how many columns do you want to have: \n";
    std::cin >>columns;

    std::cout <<" Type how many mines do you want to place in the playground: \n ";
    std::cin >>mines;

    GameBoard game(rows,columns,mines);

   
    while (true)
    {
        game.boardDisplay();

        char action;
        std::cout <<" Choose R/r to revel your choise \n M/m to mark or flag a cell as a bomb \n or Q/q to quit the game ";
        std::cin>>action;

        if (action == 'Q' || action == 'q')
        {
            std::cout <<" Game is terminated,\n se you in on another game Bye!  ";
            break;
        }

         int c, r;
            std::cout << " Which row do you want to choose? \n ";
            std::cin>>r;
            
            std::cout << " Which column do you want to choose? \n ";
            std::cin>>c;

            r--;
            c--;

        if (r<0 || r >= rows || c <0 || c >= columns)
                    {
                        std::cout << "Invalid selection. try again";
                        continue;
                    }
           
           if (action == 'R' || action == 'r' ){
                bool isBomb = game.revealCell(r,c);

                if (isBomb){
                    std::cout<< "Kaboooooommmm!, Sorry that was  a mine\n You lose \n Game Over \n " ;
                    game.boardDisplay();
                    break;
                }

                if (game.checkWin())
                {
                   std::cout <<" Congratulation! YOU WON THE Game \n";
                   game.boardDisplay();
                   break;
                }
                
            }else if (action == 'M' || action == 'm'){
                game.markCell(r, c);
            }else{
                std::cout<< "Pleas follow the instructions";
            }
            
        }
    return 0;   
}
