#include "Controller.h"
#include "Board.h"
#include "Io.h"
#include <conio.h>

Controller::Controller()
    :   m_level(1),
        m_mouse(getMouseLocation()),
        m_whoseTurn(0),
        m_cats(getCatsLocations()),
        m_board("Board1.txt"),
        m_score(0)
{}

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
        system("cls");          // clear screen
        if (m_mouse.getLives() == 0) {
            printEndMessage('L');
            break;
        }
        increaseLevel();
        if (m_level > 2) {
            printEndMessage('W');
            break;
        }

        m_board = Board("Board" + std::to_string(m_level) + ".txt");
        m_mouse.setPosition(getMouseLocation());
        m_cats.setPositions(getCatsLocations());

        resetScreen();
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
    // printing the game data
    std::cout << "============================" << std::endl;
    std::cout << "          LEVEL: " << m_level << std::endl;
    std::cout << "          SCORE: " << getScore() << std::endl;
    std::cout << "          LIVES: " << m_mouse.getLives() << std::endl;
    std::cout << "           KEYS: " << m_mouse.getKeys() << std::endl;
    std::cout << "============================" << std::endl;
}
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
    std::cout << "          SCORE: " << getScore() << std::endl;
    std::cout << "============================" << std::endl;
}

// increase player level
void Controller::increaseLevel()
{
    m_level++;
    m_mouse.resetKeys();
    m_score += (5 * m_board.getCatsNumInLevel());
    m_score += 25;
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
    case Keys::ESCAPE:
        std::cout << "Escape pressed. Exiting...\n";
        return true;
    case Keys::SPACE:
        movePlayer(m_mouse, Location(0, 0));
        break;
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
        player.move(m_board,newPosition))
    {
        char theChar = m_board.getChar(newPosition);

        // if mouse steps on cheese block
        if (theChar == '*') {
            m_board.clearItem(newPosition,'*');
            m_score += 10;
        }
        // if mouse steps on key block
        if (theChar == 'F') {
            m_board.clearItem(newPosition,'F');
            m_mouse.addKey();	// adds a key
        }
        // if mouse steps on a Door with key
        if (theChar == 'D') {
            m_board.clearCell(newPosition);
            m_score += 2;
        }
        // if mouse steps on a Present
        if (theChar == '$') {
            m_board.clearItem(newPosition,'$');
            m_cats.killCat();
            m_score += 5;
        }
        // if mouse steps on a Cat
        if (theChar == '^') {
            m_mouse.getEaten(m_board);
        }

        if (isCatAndMouseSamePos()) {
            m_mouse.getEaten(m_board);
        }

        m_whoseTurn = 1 - m_whoseTurn;
    }
}

void Controller::moveCats(auto& player)
{
    player.move(m_board, m_mouse);
 
    m_whoseTurn = 1 - m_whoseTurn;
}

int Controller::getScore()
{
    return m_score;
}
