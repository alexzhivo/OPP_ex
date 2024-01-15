#include "Controller.h"
#include "Io.h"
#include "Board.h"

Controller::Controller()
    : m_level(1), m_mouse(getCharacterLocation(mouse)), m_board("Board1.txt")
{}

void Controller::play()
{
    resetScreen();
    //m_board.printCurrBoard();   //Print the board
    //m_mouse.setPosition(getCharacterLocation(mouse));
   
}

void Controller::resetScreen()
{
    Screen::resetLocation();
    m_board.printCurrBoard();   //Print the board
    m_mouse.print();
    Screen::setLocation(Location(0, m_board.getBoardSize()));
}

Location Controller::getCharacterLocation(Characters requestedCharacter)
{
    switch (requestedCharacter)
    {
    case mouse:
        return m_board.getLocations(mouse);
    }
}

