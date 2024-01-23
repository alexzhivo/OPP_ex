#include "Cats.h"
#include "Location.h"
#include <ctime>
#include <iostream>
#include <thread>
#include <chrono>
using namespace std::chrono_literals;

Cats::Cats(std::vector<Location> positions) 
	: m_positions(positions) {}

void Cats::print(Board& board)
{
    for (const auto& cats : m_positions) 
    {
        Screen::setLocation(cats);
        
        std::cout << m_char;
        Screen::setLocation(Location(0, board.getBoardSize()));
        std::this_thread::sleep_for(200ms);
        
    }
}

bool Cats::move(Board& board)
{
    srand((unsigned int)time(nullptr));
    for (size_t i = 0; i < m_positions.size(); ++i)
    {
        // Generate a random direction
        Location randomDirection = getRandomDirection();

        // Calculate the new location
        Location newLocation(m_positions[i].col + randomDirection.col, m_positions[i].row + randomDirection.row);

        // Move the cat if the move is valid
        if (isValidMove(board, newLocation))
        {
            // Clear the current position on the board
            board.clearCell(m_positions[i]);

            // Update the cat position to the new location
            m_positions[i] = newLocation;
            
        }
        // If the move is not valid, the cat stays in its current position
    }

    return true;
}

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

// Function to generate a random number between min and max (inclusive)
int Cats::getRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}


bool Cats::isValidMove(Board board, Location location)
{
    if (!board.newPositionIsValid(location))
    {
        // for debugging : std::cout << "here";
        return false;
    }
	char currentChar = board.getChar(location);
	if (currentChar == ' ' || currentChar == '$' || currentChar == 'F')
		return true;

	return false;
}

int Cats::getNumOfCats()
{
    return (int)m_positions.size();
}

Location Cats::getCatPosition(const int num)
{
    return m_positions[num];
}