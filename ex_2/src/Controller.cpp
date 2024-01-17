#include "Controller.h"
#include "Io.h"
#include "Board.h"
#include <conio.h>

Controller::Controller()
    : m_level(1), m_mouse(getCharacterLocation(mouse)), m_board("Board1.txt")
{}

void Controller::play()
{
    resetScreen();
    //m_board.printCurrBoard();   //Print the board
    //m_mouse.setPosition(getCharacterLocation(mouse));
    while (true)
    {
        handleKey();
        resetScreen();
    }
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
void Controller::handleKey()
{
    const auto c = _getch();
    auto exit = false;
    switch (c)
    {
    case 0:
    case Keys::SPECIAL_KEY:
        handleSpecialKey();
        break;
    default:
        exit = handleRegularKey(c);
        break;
    }
}

bool Controller::handleRegularKey(int c)
{
    switch (c)
    {
    case 'A':
        std::cout << "A pressed\n";
        break;
    case 'a':
        std::cout << "a pressed\n";
        break;
    case Keys::ESCAPE:
        std::cout << "Escape pressed. Exiting...\n";
        return true;
    default:
        std::cout << "Unknown regular key pressed (code = " << c << ")\n";
        break;
    }

    return false;
}

void Controller::handleSpecialKey()
{
    const auto c = _getch();
    switch (c)
    {
    case SpecialKeys::UP:
        movePlayer(m_mouse, Location(0, -1));
        break;
    case SpecialKeys::DOWN:
        std::cout << "Arrow Down pressed\n";
        break;
    case SpecialKeys::LEFT:
        std::cout << "Arrow Left pressed\n";
        break;
    case SpecialKeys::RIGHT:
        std::cout << "Arrow Right pressed\n";
        break;
    default:
        std::cout << "Unknown special key pressed (code = " << c << ")\n";
        break;
    }
}

void Controller::movePlayer(auto& player, const Location& direction)
{
    Location newPosition(player.getPosition().col + direction.col, player.getPosition().row + direction.row);
    player.move(m_board, newPosition);
}
