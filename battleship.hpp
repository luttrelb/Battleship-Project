#include <iostream>
#include <string>
#include "board.hpp"

enum ShipDirection {VERTICAL, HORIZONTAL};

class Battleship {
    private:
        string player; //private variable used for switching turns (player)
        string computer; //private variable used for switching turns (computer)

    public:
        //set player function for swapping to player functionality
        void setPlayer(string gamePlayer){
            this->gamePlayer = player;
        }

        //set player function for swapping to computer functionality
        void setComputer(string gameComputer){
            this->gameComputer = computer;
        }

        //function that checks if the game has been won yet
        const bool checkGameState(Board board){
            //for loop with nested for loop that checks all spaces for 1s, 2s, 3s, 4s, or 5s
            //finding any of these values indicates game is still going
            for(int row = 0; row < 10; row++){
				for(int col = 0; col < 10; col++){
					if((board[row][col] = 1) || (board[row][col] = 2) || (board[row][col] = 3 || (board[row][col] = 1) || 4)
                    || (board[row][col] = 5)){
					    return false;
					}
                }
            }
            //return true otherwise
			return true;
        }
}
