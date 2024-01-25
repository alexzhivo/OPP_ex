#include "Cats.h"
#include <ctime>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

// Constructor
Cats::Cats(std::vector<Location> positions) 
	: m_positions(positions) {}

// prints the cats on the board
void Cats::print(Board& board)
{
    for (const auto& cats : m_positions) 
    {
        Screen::setLocation(cats);
        std::cout << m_char;
        Screen::setLocation(Location(0, board.getBoardSize()));
        std::this_thread::sleep_for(50ms);
    }
}
// move function for the cats
bool Cats::move(Board& board, Mouse& mouse)
{
    srand((unsigned int)time(nullptr));

    for (size_t i = 0; i < m_positions.size(); ++i)
    {
        // Generate a random direction
        Location randomDirection = getRandomDirection();

        Location newLocation = calculateNewLocation(i, randomDirection);

        if (isValidMove(board, newLocation))
        {
            m_positions[i] = newLocation;

            if (board.isSamePosition(newLocation, mouse.getPosition()))
            {
                mouse.getEaten(board);
            }   
        }
        // If the move is not valid, the cat stays in its current position
    }
    return true;
}

Location Cats::calculateNewLocation(size_t catIndex, const Location& randomDirection)
{
    return Location(m_positions[catIndex].col + randomDirection.col,
        m_positions[catIndex].row + randomDirection.row);
}

// removes one cat from the cats position vector
bool Cats::killCat()
{
    if (!m_positions.empty()) {
        int index = getRandomNumber(0, (int)m_positions.size() - 1);
        m_positions.erase(m_positions.begin() + index);
    }
    return false;
}

// gives cat a random direction for moving
Location Cats::getRandomDirection() 
{
    // Generate a random direction (up, down, left, or right)
    int direction = getRandomNumber(0, 3);

    switch (direction) {
    case 0:
        return Location(0, 1);  // Move right
    case 1:
        return Location(0, -1); // Move left
    case 2:
        return Location(1, 0);  // Move down
    case 3:
        return Location(-1, 0); // Move up
    default:
        return Location(0, 0);  // No movement
    }
}

// function to generate a random number between min and max (inclusive)
int Cats::getRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// check if cat cat's move is valid
bool Cats::isValidMove(Board board, Location location)
{
    if (!board.newPositionIsValid(location))
    {
        return false;
    }

	char currentChar = board.getChar(location);

	if (currentChar != '#' && currentChar != 'D')
		return true;

	return false;
}
// returns the number of cats.
int Cats::getNumOfCats() const
{
    return (int)m_positions.size();
}

// returns a specific cat position
Location Cats::getCatPosition(const int num)
{
    return m_positions[num];
}

// sets positions for cats
void Cats::setPositions(std::vector<Location> newPositions)
{
    // Clear the existing positions
    m_positions.clear();

    // Fill the vector with new positions
    m_positions = newPositions;
}


