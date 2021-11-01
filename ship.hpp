#include <iostream>
#include <string>

enum ShipDirection {VERTICAL, HORIZONTAL};

class Ship {
    public:
        /**
        * Constructor for creating default ship
        *
        * @param numHits the number of hits the ship can take
        * @param name the name of the ship
        */
        Ship(int numHits, string name){
            shipType = name; //default ship name
            dir = VERTICAL; //default ship direction
            startRow = 0; //default ship row
            startCol = 0; //default ship column
            numOfHits = numHits; //default number of hits
        }

        /**
        * setter for setting the initial column of the ship
        *
        * @param sc the column to be set
        */
        void setCol(int sc){
            startCol = sc;
        }

        /** 
        * getter for getting the ship column
        * @return starting column
        */
        const int getCol(){
            return startCol;
        }

        /**
        * setter for setting the initial row of the ship
        *
        * @param sr the row to be set
        */
        void setRow(int sr){
            startRow = sr;
        }

        /** 
        * getter for getting the ship row
        * @return starting row
        */
        const int getRow(){
            return startRow;
        }

        /**
        * setter that determines if the ship is positioned horizontal or vertical
        *
        * @param sd the direction of the boat
        */
        void setDirection(ShipDirection sd){
            dir = sd;
        }

        /** 
        * getter for getting the ship direction
        * @return starting direction
        */
        const ShipDirection getDirection(){
            return dir;
        }

        /**
        * function for reducing number of hits left by 1
        *
        */
        void reduceHitNum(){
            numOfHits = numOfHits - 1;
        }

        /**
        * getter for getting the number of hits the ship has left
        * @return number of hits
        */
        const int getHitNum(){
            return numOfHits;
        }

        /**
        * getter for getting the name of the ship
        * @returns ship type (name)
        */
        const string getShipName(){
            return shipType;
        }

        /**
        * setter for setting the ship name
        *
        * @param shipName the name of the boat
        */
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
