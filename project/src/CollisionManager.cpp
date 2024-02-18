#include "CollisionManager.h"

CollisionManager::CollisionManager(Board& board)
	: m_board(&board)
{}

bool CollisionManager::checkMapEdgeCollision(Mouse& mouse)
{
	auto playerBounds = mouse.getObjectBounds();
	auto boardBounds = m_board->getBoardBounds();

	return !(playerBounds.left >= boardBounds.left &&
		playerBounds.top >= boardBounds.top &&
		playerBounds.left + playerBounds.width <= boardBounds.left + boardBounds.width &&
		playerBounds.top + playerBounds.height <= boardBounds.top + boardBounds.height);
}