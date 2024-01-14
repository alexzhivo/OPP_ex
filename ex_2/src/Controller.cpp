#include "Controller.h"
#include "Io.h"
#include "Board.h"

Controller::Controller()
    : m_level(1), m_board("Board1.txt")
{}

void Controller::play()
{

    m_board.printCurrBoard();   //Print the board

}

void Controller::resetScreen()
{
    Screen::resetLocation();
    m_board.printCurrBoard();   //Print the board
    Screen::setLocation(Location(0, m_board.getBoardSize()));
}