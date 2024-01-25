#pragma once
#include "io.h"
class Board;
class Cats;

class Mouse {
public:
	Mouse(Location position);
	bool move(Board& board, Location newLocation, Cats& cats);
	bool isValidMove(Board &board, Location location);
	void setPosition(Location newPosition);	
	void print();
	void addKey();
	void getEaten(Board& board);
	void resetKeys();
	void setScore(int score);
	int getScore() const;
	int getKeys() const;
	int getLives() const;
	Location getPosition() const;

	void handleCheese(Board& board, const Location& location);
	void handleKey(Board& board, const Location& location);
	bool handleDoor(Board& board, const Location& location);
	void handlePresent(Board& board, const Location& location, Cats& cats);
	void handleCat(Board& board, const Location& newLocation, Cats& cats);
private:
	const char m_char = '%';
	Location m_position;
	int m_keys;
	int m_lives;
	int m_score;
};