#include <iostream>
#include <string>
#include <random>
#include "ship.hpp"

enum ShipDirection {VERTICAL, HORIZONTAL};

class Board {
    public:

        Board(){

        }

        Board(Board board[10][10]) {
            board = board;
        }

        /**
        * initializes original state of the board
        */
        void setBoard(){
            Board board[10][10];
            for (int row = 0; row < 10; row++){
                for (int col = 0; col < 10; col++){
                    board[row][col] = 0;
                }
            }
        }

        /**
        * prints state of the board
        */
        void printBoard(Board board[10][10]){
            Board pBoard[10][10];
            for (int row = 0; row < 10; row++){
                for (int col = 0; col < 10; col++){
                    pBoard[row][col] = board[row][col];
                }
            }
            //prints 0 - 9 vertically above board
            std::cout << "  0 1 2 3 4 5 6 7 8 9 10" << std::endl;
            // rowLabel starts at A and is incremented A - J as column indicators
			char rowLabel = 'A';
            //for loop with nested for loop that iterates and prints the board
			for(int row = 0; row < 10; row++){
				std::cout << rowLabel << " ";
				rowLabel++;
				for(int col = 0; col < 10; col++){
					std::cout << pBoard[row][col] << " ";
				}
				std::cout << std::endl;
			}
        }
        
       /**
        * random number generator that pulls from even distribution
        *
        * @param range_from the starting point for random generator
        * @param range_to the ending point for random generator
        * @return the distribution generator 
        */
        int randGen(int range_from, int range_to){
            //create random device rand_dev
            std::random_device rand_dev;
            //create generator for rand_dev
            std::mt19937 generator(rand_dev());
            //pull from uniform distributions using the parameters for range_from, range_to
            std::uniform_int_distribution<int> distr(range_from, range_to);
            //print out 
            return distr(generator);
        }

        /**
        * Function that places the players ships
        *
        * @param ship ship to be placed
        * @param shipRow the row that the ship will be placed
        * @param shipCol the column that the ship will be placed
        * @param shipDir the direction the ship will be placed (horizontal, vertical)
        */
        void placeShipPlayer(Board board[10][10], Ship ship, int shipRow, int shipCol, int shipDir){
            Board boardP[10][10];
            for (int row = 0; row < 10; row++){
                for (int col = 0; col < 10; col++){
                    boardP[row][col] = board[row][col];
                }
            }

            if (shipDir == 0){
                //set direction to VERTICAL
                ship.setDirection(VERTICAL);
            }
            else {
                //set direction to HORIZONTAL
                ship.setDirection(HORIZONTAL);
            }
            //Let player know if chosen row, column, and direction are not valid inputs
            if (!openSpaceChecker(boardP, shipRow, shipCol, ship.getHitNum(), ship.getDirection())){
                std::cout << "Selected row and column are not valid spots to place ship" << std::endl;
            }
            //place ship if chosen row and column and direction are all valid
            if (openSpaceChecker(boardP, shipRow, shipCol, ship.getHitNum(), ship.getDirection())){
                placeShipHelper(boardP, shipRow, shipCol, ship.getHitNum(), ship.getDirection(), ship.getShipName());
            }
        }

        /**
        * function that is used in the process of checking and placing a ship correctly
        *
        * @param ship the ship to be placed by the computer
        */
        void placeShipComputer(Board board[10][10], Ship ship){
            Board boardC[10][10];
            for (int row = 0; row < 10; row++){
                for (int col = 0; col < 10; col++){
                    boardC[row][col] = board[row][col];
                }
            }
            //get rand num between 0 and 1 for direction
            int randDir = randGen(0, 1);
            //get rand num between 0 and 9 for row
            int randRow = randGen(1, 10);
            //get rand num between 0 and 9 for col
            int randCol = randGen(1, 10);
            //check if direction is 0
            if (randDir == 0){
                //set direction to VERTICAL
                ship.setDirection(VERTICAL);
            }
            else {
                //set direction to HORIZONTAL
                ship.setDirection(HORIZONTAL);
            }
            //While there is not an open spot 
            while(!openSpaceChecker(boardC, randRow, randCol, ship.getHitNum(), ship.getDirection())){
                //keep getting random numbers for randRow and randCol until they fit within the
                //space of the board    
                randRow = randGen(1, 10);
                randCol = randGen(1, 10);
            }
            //use new rand for row as startRow
            ship.Ship::setRow(randRow);
            //use new rand for col as startCol
            ship.Ship::setCol(randCol);
            //pass new row and new col through placeShip function
            placeShipHelper(boardC, randRow, randCol, ship.getHitNum(), ship.getDirection(), ship.getShipName());
        }

        /**
        * function that checks and makes sure that the place we want to put a ship is an okay place
        * to place the ship
        *
        * @param shipRow the row that the ship will be placed
        * @param shipCol the column that the ship will be placed
        * @param size the size of the ship to be placed
        * @param shipDir the direction the ship will be placed (horizontal, vertical)
        * @return true if ship can be placed, false otherwise
        */
        const bool openSpaceChecker(Board board[10][10], int shipRow, int shipCol, int size, ShipDirection shipDir){
            Board boardT[10][10];
            for (int row = 0; row < 10; row++){
                for (int col = 0; col < 10; col++){
                    boardT[row][col] = board[row][col];
                }
            }
            //checks if the direction is vertical
            if(shipDir == VERTICAL){
                //returns false if ship row + size is bigger than 9 (out of bounds, cannot place)
				if(shipRow + size > 9){
					return false;
				}
                //checks vertically for open spaces
				for(int row = shipRow; row < shipRow + size; row++){
					if(boardT[row][shipCol] !=0){
						return false;
					}
				}
			}
            //checks if the direction is horizontal
			else if(shipDir==HORIZONTAL){
                //returns false if ship col + size is bigger than 9 (out of bounds, cannot place)
                if(shipCol + size > 9){
                    return false;
				}
                //checks horizontally for open spaces
                for(int col = shipCol; col < shipCol + size; col++){
                    if(boardT[shipRow][col] !=0){
                        return false;
					}
				}
			}
            //returns true only if ship can be places directionally when there are enough open spaces
            return true;
        }

        /**
        * function that places ship on the board assuming it is an ok place to put ship
        *
        * @param shipRow the row that the ship will be placed
        * @param shipCol the column that the ship will be placed
        * @param size the size of the ship to be placed
        * @param shipDir the direction the ship will be placed (horizontal, vertical)
        * @param name the name of the ship that is going to be placed
        */
        void placeShipHelper(Board board[10][10], int shipRow, int shipCol, int size, ShipDirection shipDir, std::string name){
            Board boardS[10][10];
            for (int row = 0; row < 10; row++){
                for (int col = 0; col < 10; col++){
                    boardS[row][col] = board[row][col];
                }
            }
            //check if direction is vertical
            if(shipDir == VERTICAL){
                //for loop that will place ships vertically
				for(int row = shipRow; row < shipRow+size; row++){
                    //place 1s if ship is carrier
                    if (name == "Carrier"){
                        boardS[row][shipCol] = 1;
                    }
                    //place 2s if ship is battleship
					if (name == "Battleship"){
                        boardS[row][shipCol] = 2;
                    }
                    //place 3s if ship is submarine
                    if (name == "Submarine"){
                        boardS[row][shipCol] = 3;
                    }
                    //place 4s if ship is destroyer
                    if (name == "Destroyer"){
                        boardS[row][shipCol] = 4;
                    }
                    //place 5s if ship is patrol boat
                    if (name == "Patrol boat"){
                        boardS[row][shipCol] = 5;
                    }
				}
			}
            //check if ship is horizontal
			else if(shipDir==HORIZONTAL){
                //for loop that will place ships horizontally
                for(int col = shipCol; col < shipCol+size; col++){
                    //place 1s if ship is carrier
                    if (name == "Carrier"){
                        boardS[shipRow][col] = 1;
                    }
                    //place 2s if ship is battleship
					if (name == "Battleship"){
                        boardS[shipRow][col] = 2;
                    }
                    //place 3s if ship is submarine
                    if (name == "Submarine"){
                        boardS[shipRow][col] = 3;
                    }
                    //place 4s if ship is destroyer
                    if (name == "Destroyer"){
                        boardS[shipRow][col] = 4;
                    }
                    //place 5s if ship is patrol boat
                    if (name == "Patrol boat"){
                        boardS[shipRow][col] = 5;
                    }
                }
            }
         }
    
    /**
        * Function that takes in a board and two guesses (row, col) and checks
        * for a hit; for the player
        *
        * @param gBoard the board the guess is being checked against
        * @param rowGuess the row that is being guessed
        * @param colGuess the column that is being guessed
        * @return returns true if there was a hit, and false otherwise
        */
    bool makeGuess(int board[10][10], int rowGuess, int colGuess){
          int gBoard[10][10];
            for (int row = 0; row < 10; row++){
                for (int col = 0; col < 10; col++){
                    gBoard[row][col] = board[row][col];
                }
            }
        for(int row = 0; row < 10; row++){         
            for(int col = 0; col < 10; col++){
                if ((gBoard[row][col] == gBoard[rowGuess][colGuess])){
                    if ((board[row][col] == 1) || (gBoard[row][col] == 2) ||
                    (gBoard[row][col] == 3) || (gBoard[row][col] == 4) ||
                    (gBoard[row][col] == 5)){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    /**
        * Function that takes in a board and two guesses (row, col) and checks
        * for a hit; for the computer
        *
        * @param gBoard the board the guess is being checked against
        * @param rowGuess the row that is being guessed
        * @param colGuess the column that is being guessed
        * @return returns true if there was a hit, and false otherwise
        */
    bool computerGuess(int board[10][10], int compRow, int compCol){
        int gBoard[10][10];
            for (int row = 0; row < 10; row++){
                for (int col = 0; col < 10; col++){
                    gBoard[row][col] = board[row][col];
                }
            }
        for(int row = 0; row < 10; row++){         
            for(int col = 0; col < 10; col++){
                if ((gBoard[row][col] == gBoard[compRow][compCol])){
                    if ((gBoard[row][col] == 1) || (gBoard[row][col] == 2) ||
                    (gBoard[row][col] == 3) || (gBoard[row][col] == 4) ||
                    (gBoard[row][col] == 5)){
                        return true;
                    }
                }
            }
        }
    }

    private:
        int board[10][10]; //private instance variable of the 2d board array
    
};
