#include <iostream>
#include <string>
#include "ship.hpp"

using namespace std;

class Board {
    public:
        //initializes original state of the board
        void setBoard(){
            for (int row = 0; row < 10; row++){
                for (int col = 0; col < 10; col++){
                    board[row][col] = o;
                }
            }
        }

        //prints state of the board
        const Board getBoard(){
            //prints 0 - 9 vertically above board
            std::cout << "  0 1 2 3 4 5 6 7 8 9 10" << std::endl;
            // rowLabel starts at A and is incremented A - J as column indicators
			char rowLabel = 'A';
            //for loop with nested for loop that iterates and prints the board
			for(int row = 0; row < 10; row++){
				std::cout << rowLabel << " ";
				rowLabel++;
				for(int col = 0; col < 10; col++){
					std::cout << board[row][col] << " ";
				}
				std::cout << std::endl;
			}
        }
        
       //random number generator that pulls from even distribution
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

        //function that is used in the process of checking and placing a ship correctly
        void placeShipPlayer(Ship ship, int shipRow, int shipCol, int shipDir){
            if (randDir == 0){
                //set direction to VERTICAL
                ship.setDirection(VERTICAL);
            }
            else {
                //set direction to HORIZONTAL
                ship.setDirection(HORIZONTAL);
            }
            //Let player know if chosen row, column, and direction are not valid inputs
            if (!openSpaceChecker()){
                std::cout << "Selected row and column are not valid spots to place ship" << std::endl;
            }
            //place ship if chosen row and column and direction are all valid
            if (openSpaceChecker()){
                placeShipHelper(shipRow, shipCol, size, ship.getDirection(), ship.getShipName());
            }
            
        }

        //function that is used in the process of checking and placing a ship correctly
        void placeShipComputer(Ship ship){
            //get rand num between 0 and 1 for direction
            int randDir = randGen(0, 1);
            //get rand num between 0 and 9 for row
            int randRow = randGen(0, 9);
            //get rand num between 0 and 9 for col
            int randCol = randGen(0, 9);
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
            while(!openSpaceChecker(randRow, randCol, ship.getHitNum(), ship.getDirection()){
                //keep getting random numbers for randRow and randCol until they fit within the
                //space of the board    
                randRow = randGen(0, 9);
                randCol = randGen(0, 9);
            }
            //use new rand for row as startRow
            ship.setRow(randRow);
            //use new rand for col as startCol
            ship.setCol(randCol);
            //pass new row and new col through placeShip function
            placeShipHelper(shipRow, shipCol, size, shipDir, ship.getShipName());
        }

        //function that checks and makes sure that the place we want to put a ship is an okay place
        //to place the ship
        const bool openSpaceChecker(int shipRow, int shipCol, int size, ShipDirection shipDir){
            //checks if the direction is vertical
            if(shipDir == VERTICAL){
                //returns false if ship row + size is bigger than 9 (out of bounds, cannot place)
				if(shipRow + size > 9){
					return false;
				}
                //checks vertically for open spaces
				for(int row = shipRow; row < shipRow + size; row++){
					if(board[row][shipCol] !=0){
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
                    if(board[shipRow][col] !=0){
                        return false;
					}
				}
			}
            //returns true only if ship can be places directionally when there are enough open spaces
            return true;
        }

        //function that places ship on the board assuming it is an ok place to put ship
        void placeShipHelper(int shipRow, int shipCol, int size, ShipDirection shipDir, string name){
            //check if direction is vertical
            if(shipDir == VERTICAL){
                //for loop that will place ships vertically
				for(int row = shipRow; row < shipRow+size; row++){
                    //place 1s if ship is carrier
                    if (name == "Carrier"){
                        board[row][shipCol] = 1;
                    }
                    //place 2s if ship is battleship
					if (name == "Battleship"){
                        board[row][shipCol] = 2;
                    }
                    //place 3s if ship is submarine
                    if (name == "Submarine"){
                        board[row][shipCol] = 3;
                    }
                    //place 4s if ship is destroyer
                    if (name == "Destroyer"){
                        board[row][shipCol] = 4;
                    }
                    //place 5s if ship is patrol boat
                    if (name == "Patrol boat"){
                        board[row][shipCol] = 5;
                    }
				}
			}
            //check if ship is horizontal
			else if(shipDir==HORIZONTAL){
                //for loop that will place ships horizontally
                for(int col = shipCol; col < shipCol+size; col++){
                    //place 1s if ship is carrier
                    if (name == "Carrier"){
                        board[row][shipCol] = 1;
                    }
                    //place 2s if ship is battleship
					if (name == "Battleship"){
                        board[row][shipCol] = 2;
                    }
                    //place 3s if ship is submarine
                    if (name == "Submarine"){
                        board[row][shipCol] = 3;
                    }
                    //place 4s if ship is destroyer
                    if (name == "Destroyer"){
                        board[row][shipCol] = 4;
                    }
                    //place 5s if ship is patrol boat
                    if (name == "Patrol boat"){
                        board[row][shipCol] = 5;
                    }
                }
            }
         }

    private:
        int board[10][10]; //private instance variable of the 2d board array
    
}
