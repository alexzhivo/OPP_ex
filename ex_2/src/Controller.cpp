#include "Controller.h"
#include "Board.h"
#include "Io.h"
#include <conio.h>

// constructor
Controller::Controller()
    :   m_mouse(getMouseLocation()),
        m_whoseTurn(0),
        m_cats(getCatsLocations()),
        m_board("Board1.txt",1)
{}

// the main controller function
void Controller::play()
{
    resetScreen();
    while (true)
    {
        while (m_board.isCheeseLeft() && m_mouse.getLives() > 0)
        { 
            if (m_whoseTurn == 0) {
                handleKey();
            }
            else {
                moveCats(m_cats);
            }

            resetScreen();
        }
        handleEndOfGame();
    }
}

// resets the game screen
void Controller::resetScreen()
{
    // printing all the elements in game
    Screen::resetLocation();
    m_board.print();                // prints the board
    m_cats.print(m_board);          // prints the cats
    m_mouse.print();                // prints the mouse
    Screen::setLocation(Location(0, m_board.getBoardSize()));
    printGameData();                // prints the data
}

void Controller::printGameData()
{
    // printing the game data
    std::cout << "============================" << std::endl;
    std::cout << "          LEVEL: " << m_board.getLevel() << std::endl;
    std::cout << "          SCORE: " << m_mouse.getScore() << std::endl;
    std::cout << "          LIVES: " << m_mouse.getLives() << std::endl;
    std::cout << "           KEYS: " << m_mouse.getKeys() << std::endl;
    std::cout << "============================" << std::endl;
}

// prints the ending screen of the game
void Controller::printEndMessage(const char stat)
{
    system("cls");
    std::cout << "============================" << std::endl;
    if (stat == 'W')
        std::cout << "          YOU WIN!          " << std::endl;
    else 
        std::cout << "         YOU LOSE...        " << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "         SCORE: " << m_mouse.getScore() << std::endl;
    std::cout << "============================" << std::endl;
}

// increase player level
void Controller::increaseLevel()
{
    m_board.levelUp();
    m_mouse.resetKeys();
    int newScore = m_mouse.getScore();
    newScore += (5 * m_board.getCatsNumInLevel() + 25);
    m_mouse.setScore(newScore);
}

// get location for mouse
Location Controller::getMouseLocation() const
{
    return m_board.getMouseLocation();  
}

// get all cats location
std::vector<Location> Controller::getCatsLocations() 
{
    return m_board.getCatsLocations();
}

// get all cheese location
std::vector<Location> Controller::getCheeseLocations()
{
    return m_board.getCheeseLocations();
}

// handle key press
void Controller::handleKey()
{
    const auto key_pressed = _getch();
    switch (key_pressed)
    {
    case Keys::SPECIAL_KEY:
        handleSpecialKey();
        break;
    default:
        handleRegularKey(key_pressed);
        break;
    }
}

// handle regular keys
void Controller::handleRegularKey(const int key_pressed)
{
    switch (key_pressed)
    {
    case Keys::ESCAPE:
        system("cls");
        exit(EXIT_SUCCESS);
    case Keys::SPACE:
        movePlayer(m_mouse, Location(0, 0));
        break;
    default:
        break;
    }
}

// handle arrow keys
void Controller::handleSpecialKey()
{
    const auto key_pressed = _getch();
    switch (key_pressed)
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
        break;
    }
}

// move command for player (mouse)
void Controller::movePlayer(auto& player, const Location& direction)
{
    Location newPosition(player.getPosition().col + direction.col,
                         player.getPosition().row + direction.row);

    if (m_board.newPositionIsValid(newPosition) &&
        player.move(m_board, newPosition, m_cats))
    {
        
        m_whoseTurn = 1 - m_whoseTurn;
    }
}
// function to move that cats
void Controller::moveCats(auto& player)
{
    player.move(m_board, m_mouse);
 
    m_whoseTurn = 1 - m_whoseTurn;
}

void Controller::setupNextLevel()
{
    m_board = Board("Board" + std::to_string(m_board.getLevel()) + ".txt", m_board.getLevel());

    if (m_board.getLevel() == 0)
    {
        printEndMessage('W');
        exit(EXIT_SUCCESS);
    }

    m_mouse.setPosition(getMouseLocation());
    m_cats.setPositions(getCatsLocations());
}

void Controller::handleEndOfGame()
{
    system("cls"); // clear screen

    if (m_mouse.getLives() == 0)
    {
        printEndMessage('L');
        exit(EXIT_SUCCESS);
    }

    increaseLevel();
    setupNextLevel();
    resetScreen();
}


