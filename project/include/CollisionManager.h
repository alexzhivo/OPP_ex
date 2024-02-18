#pragma once

#include "Board.h"
#include "Mouse.h"
#include "Wall.h"

class CollisionManager {
public:
	CollisionManager(Board& board);
	~CollisionManager() = default;

	bool checkMapEdgeCollision(Mouse& mouse);
private:
	Board* m_board;
};