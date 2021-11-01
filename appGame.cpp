#include <iostream>
#include <string>
#include <vector>
#include "board.hpp"
#include "ship.hpp"
#include "battleship.hpp"

using namespace std;


int main(int argc, char* argv[]){
    char guessRow; //used for player row guesses
	int guessCol; //used for player col guesses
    int shipDir; //used for determining vertical or horizontal placement

    Ship pcarrier = Ship(5, "Carrier"); //player carrier
    Ship pbattleship = Ship(4, "Battleship"); //player battleship
    Ship psubmarine = Ship(3, "Submarine"); //player submarine
    Ship pdestroyer = Ship(3, "Destroyer"); //player destroyer
    Ship ppatrolboat = Ship(2, "Patrol boat"); //player patrol boat
    Ship ccarrier = Ship(5, "Carrier"); //computer carrier
    Ship cbattleship = Ship(4, "Battleship"); //computer battleship
    Ship csubmarine = Ship(3, "Submarine"); //computer submarine
    Ship cdestroyer = Ship(3, "Destroyer"); //computer destroyer
    Ship cpatrolboat = Ship(2, "Patrol boat"); //computer patrol boat

    Board pBoard = Board(); //player board
    Board cBoard = Board(); //computer board

    pBoard.setBoard(); //player board creation
    cBoard.setBoard(); //computer board creation

    cBoard.placeShipComputer(ccarrier);  //computer carrier placement
    cBoard.placeShipComputer(cbattleship); //computer battleship placement
    cBoard.placeShipComputer(csubmarine); //computer submarine placement
    cBoard.placeShipComputer(cdestroyer); //computer destroyer placement
    cBoard.placeShipComputer(cpatrolboat); //computer patrol boat placement

    //start of the battleship game; player placement of ships
    std::cout << "\nWelcome to BattleShip!";
    std::cout << "\nEnter where you would like to place the " + carrier.getShipName() + " (Will appear as 1s on the board";
    std::cout << "\nEnter row (A-J): ";
    std::cin >> guessRow;
    guessRow = toupper(guessRow);
    int guessRowConversion = (int)guessRow - 47;
    std::cout << "Enter column (1-10): ";
    std::cin >> guessCol;
    std::cout << "Enter Direction (0 or 1)";
    std::cin >> shipDir
    pBoard.placeShipPlayer(pcarrier, guessRow, guessCol, shipDir);

    //player placement of ships
    std::cout << "\nEnter where you would like to place the " + battleship.getShipName()  + " (Will appear as 2s on the board";
    std::cout << \n"Enter row (A-J): ";
    std::cin >> guessRow;
    guessRow = toupper(guessRow);
    int guessRowConversion = (int)guessRow - 47;
    std::cout << "Enter column (1-10): ";
    std::cin >> guessCol;
    std::cout << "Enter Direction (0 or 1)";
    std::cin >> shipDir
    pBoard.placeShipPlayer(pbattleship, guessRow, guessCol, shipDir);

    //player placement of ships
    std::cout << "\nEnter where you would like to place the " + submarine.getShipName()  + " (Will appear as 3s on the board";
    std::cout << "\nEnter row (A-J): ";
    std::cin >> guessRow;
    guessRow = toupper(guessRow);
    int guessRowConversion = (int)guessRow - 47;
    std::cout << "Enter column (1-10): ";
    std::cin >> guessCol;
    std::cout << "Enter Direction (0 or 1)";
    std::cin >> shipDir
    pBoard.placeShipPlayer(psubmarine, guessRow, guessCol, shipDir);

    //player placement of ships
    std::cout << "\nEnter where you would like to place the " + destroyer.getShipName()  + " (Will appear as 4s on the board";
    std::cout << "\nEnter row (A-J): ";
    std::cin >> guessRow;
    guessRow = toupper(guessRow);
    int guessRowConversion = (int)guessRow - 47;
    std::cout << "Enter column (1-10): ";
    std::cin >> guessCol;
    std::cout << "Enter Direction (0 or 1)";
    std::cin >> shipDir
    pBoard.placeShipPlayer(pdestroyer, guessRow, guessCol, shipDir);

    //player placement of ships
    std::cout << "\nEnter where you would like to place the " + patrolboat.getShipName()  + " (Will appear as 5s on the board";
    std::cout << "\nEnter row (A-J): ";
    std::cin >> guessRow;
    guessRow = toupper(guessRow);
    int guessRowConversion = (int)guessRow - 47;
    std::cout << "Enter column (1-10): ";
    std::cin >> guessCol;
    std::cout << "Enter Direction (0 or 1)";
    std::cin >> shipDir
    pBoard.placeShipPlayer(ppatrolboat, guessRow, guessCol, shipDir);

    //do while that alternates turns between player and computer to make guesses and update board accordingly
    do {
        //player guess
        std::cout << "\n\nPlayer enter coordinates for guess: \n";
        std::cout << "Enter Guess for Row: ";
        std::cin >> guessRow;
        guessRow = toupper(guessRow);
        std::cout << "Enter Guess for Column";
        std::cin >> guessCol;
        int colConv = (int)guessCol - 47

        //check if player guess was a hit
        bool isHitPlayer = Board::makeGuess(cBoard, guessRow, colConv);
        if (isHitPlayer){
            if (cBoard[guessRow][colConv] == 1){
                ccarier.reduceHitNum();
                cBoard[guessRow][colConv] = 9
            }
            if (cBoard[guessRow][colConv] == 2){
                cbattleship.reduceHitNum();
                cBoard[guessRow][colConv] = 9
            }
            if (cBoard[guessRow][colConv] == 3){
                csubmarine.reduceHitNum();
                cBoard[guessRow][colConv] = 9
            }
            if (cBoard[guessRow][colConv] == 4){
                cdestroyer.reduceHitNum();
                cBoard[guessRow][colConv] = 9
            }
            if (cBoard[guessRow][colConv] == 5){
                cpatrolboat.reduceHitNum();
                cBoard[guessRow][colConv] = 9
            }
        }
        Battleship::checkGameState(cBoard, "Player");

        //computer guess/turn
        int compRow = Board::randGen(1, 10);
        int compCol = Board::randGen(1, 10);
        bool isHitComputer = Board::computerGuess(pBoard, compRow, compCol);
        //check if computer guess was a hit
        if (isHitComputer){
            if (pBoard[compRow][compCol] == 1){
                pcarier.reduceHitNum();
                pBoard[compRow][compCol] = 9
            }
            if (pBoard[compRow][compCol] == 2){
                pbattleship.reduceHitNum();
                pBoard[compRow][compCol] = 9
            }
            if (pBoard[compRow][compCol] == 3){
                psubmarine.reduceHitNum();
                pBoard[compRow][compCol] = 9
            }
            if (pBoard[compRow][compCol] == 4){
                pdestroyer.reduceHitNum();
                pBoard[compRow][compCol] = 9
            }
            if (pBoard[compRow][compCol] == 5){
                ppatrolboat.reduceHitNum();
                pBoard[compRow][compCol] = 9
            }
        }
        Battleship::checkGameState(pBoard, "Computer");
    }
    while ((Battleship::checkGameState(pBoard, "Computer") !=true)
        || (Battleship::checkGameState(cBoard, "player") != true)); //termination sequence of do while loop

    //winner message
    Battleship::getWinner();
}
