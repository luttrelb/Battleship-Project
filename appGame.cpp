#include <iostream>
#include <string>
#include <vector>
#include "board.hpp"
#include "ship.hpp"
#include "battleship.hpp"

using namespace std;

int main(int argc, char* argv[]){
    char guessRow;
    int guessCol;
    int shipDir;
    char playAgain();
    char keepPlaying;
    bool isGameWon;
    bool isHit;

    Ship carrier = Ship(5, "Carrier");
    Ship battleship = Ship(4, "Battleship");
    Ship submarine = Ship(3, "Submarine");
    Ship destroyer = Ship(3, "Destroyer");
    Ship patrolboat = Ship(2, "Patrol boat");

    Board pBoard = Board();
    Board cBoard = Board();

    pBoard.setBoard();
    cBoard.setBoard();

    cBoard.placeShipComputer(carrier);
    cBoard.placeShipComputer(battleship);
    cBoard.placeShipComputer(submarine);
    cBoard.placeShipComputer(destroyer);
    cBoard.placeShipComputer(patrolboat);
    
    std::cout << "\nWelcome to BattleShip!";
    std::cout << "\nEnter where you would like to place the " + carrier.getShipName();
    std::cout << "Enter row (A-J): ";
    std::cin >> guessRow;
    int guessRowConversion = (int)guessRow - 47;
    std::cout << "Enter column (1-10): ";
    std::cin >> guessCol;
    std::cout << "Enter Direction (0 or 1)";
    std::cin >> shipDir
    pBoard.placeShipPlayer(carrier, guessRow, guessCol, shipDir);

    std::cout << "\nEnter where you would like to place the " + battleship.getShipName();
    std::cout << "Enter row (A-J): ";
    std::cin >> guessRow;
    int guessRowConversion = (int)guessRow - 47;
    std::cout << "Enter column (1-10): ";
    std::cin >> guessCol;
    std::cout << "Enter Direction (0 or 1)";
    std::cin >> shipDir
    pBoard.placeShipPlayer(battleship, guessRow, guessCol, shipDir);

    std::cout << "\nEnter where you would like to place the " + submarine.getShipName();
    std::cout << "Enter row (A-J): ";
    std::cin >> guessRow;
    int guessRowConversion = (int)guessRow - 47;
    std::cout << "Enter column (1-10): ";
    std::cin >> guessCol;
    std::cout << "Enter Direction (0 or 1)";
    std::cin >> shipDir
    pBoard.placeShipPlayer(submarine, guessRow, guessCol, shipDir);

    std::cout << "\nEnter where you would like to place the " + destroyer.getShipName();
    std::cout << "Enter row (A-J): ";
    std::cin >> guessRow;
    int guessRowConversion = (int)guessRow - 47;
    std::cout << "Enter column (1-10): ";
    std::cin >> guessCol;
    std::cout << "Enter Direction (0 or 1)";
    std::cin >> shipDir
    pBoard.placeShipPlayer(destroyer, guessRow, guessCol, shipDir);

    std::cout << "\nEnter where you would like to place the " + patrolboat.getShipName();
    std::cout << "Enter row (A-J): ";
    std::cin >> guessRow;
    int guessRowConversion = (int)guessRow - 47;
    std::cout << "Enter column (1-10): ";
    std::cin >> guessCol;
    std::cout << "Enter Direction (0 or 1)";
    std::cin >> shipDir
    pBoard.placeShipPlayer(patrolboat, guessRow, guessCol, shipDir);
}
