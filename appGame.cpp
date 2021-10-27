#include <iostream>
#include <string>
#include <vector>

using namespace std;

//enumeration used as the positioning (vertical or horizontal) of the ships
enum ShipDirection {VERTICAL, HORIZONTAL};

class Ship {
    public:
        //default ship construction initializing default private variables
        Ship(){
            shipType = "";
            dir = VERTICAL;
            startRow = 0;
            startCol = 0;
            numOfHits = 0;
        }


        //ship constructor that initializes the number of hits the instantiated ship can take,
        //and the name of the ship (CARRIER, BATTLESHIP, SUBMARINE etc.)
        Ship(int numHits, string name){
            shipType = name;
            dir = VERTICAL;
            startRow = 0;
            startCol = 0;
            numOfHits = numHits;
        }

        //setter for setting the initial column of the ship
        void setStartCol(int sc){
            startCol = sc;
        }

        //getter for the starting column of the ship
        const int getStartCol(){
            return startCol;
        }

        //setter for setting the initial column of the ship
        void setRow(int sr){
            startRow = sr;
        }

        //getter for the starting row of the ship
        const int getStartRow(){
            return startRow;
        }

        //setter that determines if the ship is positioned horizontal or vertical
        void setShipDirection(ShipDirection sd){
            dir = sd;
        }

        //getter for getting the number of hits left of the ship
        const int getNumHits(){
            return numOfHits;
        }

        //getter for getting the name of the ship
        const string getShipName(){
            return shipType;
        }

        //setter for setting the ship name
        void setShipName(string shipName){
            shipType = shipName;
        }

    private:
      int numOfHits; //private variable for determining how many hits a boat can take
      ShipDirection dir; //private variable determining horizontal or vertical positioning
      int startRow; // private variable for the starting row of the boat
      int startCol; // private variable for the starting column of the boat
      string shipType; //private variable for the ship name/type
}

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
            std::cout << "  0 1 2 3 4 5 6 7 8 9" << std::endl;
			char rowLabel = 'A';
			for(int row = 0; row < 10; row++){
				std::cout << rowLabel << " ";
				rowLabel++;
				for(int col = 0; col < 10; col++){
					std::cout << board[row][col] << " ";
				}
				std::cout << std::endl;
			}
        }
        
        //stream overload

    private:
        int board[10][10]; //private instance variable of the 2d board array
    
}

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

        //random number generator that pulls from even distribution
        void randGen(){

        }

        //function that is used in the process of checking and placing a ship correctly
        void placeShipHelper(Ship ship{
            //get rand num between 0 and 1 for direction
            //get rand num between 0 and 9 for row
            //get rand num between 0 and 9 for col

            //check if direction is 0
                //set direction to VERTICAL

            //else
                //set direction to HORIZONTAL

            //While there is not an open spot 
                //get new rand for row
                //get new rand for col
            
            //use new rand for row as startRow
            //use new rand for col as startCol
            //pass new row and new col through placeShip function
        }

        //function that checks and makes sure that the place we want to put a ship is an okay place
        //to place the ship
        bool openSpaceChecker(int startRow, int startCol, int size, ShipDirection shipDir){
            if(shipDir == VERTICAL){
				if(startRow + size > 9){
					return false;
				}
				for(int row = startRow; row < startRow+size; row++){
					if(board[row][startCol] !=0){
						return false;
					}
				}
			}
			else if(shipDir==HORIZONTAL){
					if(startCol + size > 9){
					    return false;
				}
					for(int col = startCol; col < startCol+size; col++){
					    if(board[startRow][col] !=0){
						    return false;
					}
				}
			}
			return true;
        }

        //function that places ship on the board assuming it is an ok place to put ship
        void placeShip(int startRow, int startCol, int size, ShipDirection shipDir){
            if(shipDir == VERTICAL){
				for(int row = startRow; row < startRow+size; row++){
					board[row][startCol] = 1;
				}
			}
			else if(shipDir==HORIZONTAL){
					for(int col = startCol; col < startCol+size; col++){
					    board[startRow][col] = 1;
					
				}
			}
        }

        //check if boat is sunk (NOT SURE IF NEEDED)
        bool checkIfSunk(Ship ship, int startRow, int startCol, int size, ShipDirection shipDir){

        }

        //function that checks if the game has been won yet
        const string checkGameState(){
            for(int row = 0; row < 10; row++){
				for(int col = 0; col < 10; col++){
					if(board[row][col] = 1){
					    return "Game is not yet won";
					}
                }
            }
			return "Game is won by" + //whoever won; 
        }

}

int main(int argc, char* argv[]){
    char guessRow;
	int guessCol;
	char playAgain();
	char keepPlaying;
	bool isGameWon;
	bool isHit;

    Ship carrier = Ship(5, "Carrier");
    Ship battleship = Ship(4, "Battleship");
    Ship submarine = Ship(3, "Submarine");
    Ship destroyer = Ship(3, "Destroyer");
    Ship patrolboat = Ship(2, "Patrol boat");

    Board board = Board();
}
