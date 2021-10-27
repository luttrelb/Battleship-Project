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
