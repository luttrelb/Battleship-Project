#include <iostream>
#include <string>

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
        void setCol(int sc){
            startCol = sc;
        }

        //getter for the starting column of the ship
        const int getCol(){
            return startCol;
        }

        //setter for setting the initial column of the ship
        void setRow(int sr){
            startRow = sr;
        }

        //getter for the starting row of the ship
        const int getRow(){
            return startRow;
        }

        //setter that determines if the ship is positioned horizontal or vertical
        void setDirection(ShipDirection sd){
            dir = sd;
        }

        const ShipDirection getDirection(){
            return dir;
        }

        //getter for getting the number of hits left of the ship
        const int getHitNum(){
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
