#include "Controller.h"
#include "Io.h"
#include "Board.h"
#include <conio.h>

Controller::Controller()
    : m_level(1),
      m_mouse(getMouseLocation()),
      m_whoseTurn(0), 
      m_cats(getCatsLocations()), 
      m_board("Board1.txt"), 
      m_gameOver(false)
{}

void Controller::play()
{
    resetScreen();
    printData();

    // m_board.printCurrBoard();   //Print the board
    // m_mouse.setPosition(getCharacterLocation(mouse));
    
    while (!m_gameOver)
    {
        while (m_board.isCheeseLeft())
        {
            handleKey();
            resetScreen();
            printData();
        }
        system("cls");          // clear screen
        m_level++;
        m_mouse.levelUP();
        if (m_level > 2)
            endGame();

        m_board = Board("Board" + std::to_string(m_level) + ".txt");
        m_mouse.setPosition(getMouseLocation());

        resetScreen();
        printData();
    }
}

void Controller::endGame()
{
    m_gameOver = true;
}

void Controller::printData()
{
    std::cout << "============================" << std::endl;
    std::cout << "         LEVEL: " << m_level << std::endl;
    std::cout << "         SCORE: " << m_mouse.getScore() << std::endl;
    std::cout << "         LIVES: " << m_mouse.getLives() << std::endl;
    std::cout << "          KEYS: " << m_mouse.getKeys() << std::endl;
    std::cout << "============================" << std::endl;
}

void Controller::resetScreen()
{
    Screen::resetLocation();
    m_board.printCurrBoard();   // prints the board
    m_mouse.print();
    m_cats.print();
    Screen::setLocation(Location(0, m_board.getBoardSize()));
}

Location Controller::getMouseLocation()
{
    return m_board.getMouseLocation();  
}

std::vector<Location> Controller::getCatsLocations()
{
    return m_board.getCatsLocations();
}

std::vector<Location> Controller::getCheeseLocations()
{
    return m_board.getCheeseLocations();
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
        movePlayer(m_mouse, Location(0, 1));
        break;
    case SpecialKeys::LEFT:
        movePlayer(m_mouse, Location(-1, 0));
        break;
    case SpecialKeys::RIGHT:
        movePlayer(m_mouse, Location(1, 0));
        break;
    default:
        std::cout << "Unknown special key pressed (code = " << c << ")\n";
        break;
    }
}

void Controller::movePlayer(auto& player, const Location& direction)
{
    Location newPosition(player.getPosition().col + direction.col,
                         player.getPosition().row + direction.row);
    if (m_board.newPositionIsValid(newPosition) &&
        player.move(m_board, newPosition))
    {
        m_whoseTurn = 1 - m_whoseTurn;
    }
}