#include <iostream>
#include <string>
#include "board.hpp"

//enumeration used to evaluate vertical or horizontal position
enum ShipDirection {VERTICAL, HORIZONTAL};

class Battleship {
    private:
        string winner; // holds the winner

    public:
    
       /**
        * function for setting winner of the game
        *
        * @return returns the winner of the game
        */
        //return winner
        string getWinner(){
            std::cout << "The winner is: " + winner + "!";
            return winner;
        }

        /**
        * setter for setting the initial row of the ship
        *
        * @param board the board that is being checked if in win state
        * @param currentTurn the turn of the player, used to set win state if current turn has won
        * @return returns true if game has been won, false otherwise
        */
        const bool checkGameState(Board board, string currentTurn){
            //for loop with nested for loop that checks all spaces for 1s, 2s, 3s, 4s, or 5s
            //finding any of these values indicates game is still going
            for(int row = 0; row < 10; row++){
				for(int col = 0; col < 10; col++){
					if((board[row][col] = 1) || (board[row][col] = 2) || (board[row][col] = 3 || (board[row][col] = 4)
                    || (board[row][col] = 5)){
					    return false;
					}
                }
            }
            //return true otherwise
            winner = currentTurn;
			return true;
        }
}
