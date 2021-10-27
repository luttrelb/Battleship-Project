#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum ShipDirection {VERTICAL, HORIZONTAL};

class Ship {
    public:
        Ship(){
            shipType = "";
            dir = VERTICAL;
            startRow = 0;
            startCol = 0;
            numOfHits = 0;
        }

        Ship(int numHits, string name){
            shipType = name;
            dir = VERTICAL;
            startRow = 0;
            startCol = 0;
            numOfHits = numHits;
        }

        void setStartCol(int sc){
            startCol = sc;
        }

        const int getStartCol(){
            return startCol;
        }

         void setRow(int sr){
            startRow = sr;
        }

        const int getStartRow(){
            return startRow;
        }

         void setShipDirection(ShipDirection sd){
            dir = sd;
        }

        const int getNumHits(){
            return numOfHits;
        }

        const string getShipName(){
            return shipType;
        }

        void setShipName(string shipName){
            shipType = shipName;
        }

    private:
      int numOfHits;
      ShipDirection dir;
      int startRow;
      int startCol;
      string shipType;
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
				std::cout << Std::endl;
			}
        }
        
        //stream overload

    private:
        int board[10][10];
    
}

class Battleship {
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


        const string checkGameState(){
            for(int row = 0; row < 10; row++){
				for(int col = 0; col < 10; col++){
					if(board[row][col] = 1){
					    return "Game is not yet one";
					}
                }
            }
			return "Game is won by" + //whoever one; 
        }

    private:
        string player;
        string computer;

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