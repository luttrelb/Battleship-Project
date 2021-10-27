#include <iostream>
#include <string>

class Board {
    public:
        void setBoard(){
            for (int row = 0; row < 10; row++){
                for (int col = 0; col < 10; col++){
                    board[row][col] = o;
                }
            }
        }

        const Board getBoard(){
            
        }
        
    private:
        int board[10][10];
    
}
