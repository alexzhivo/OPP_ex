#include "Mouse.h"

Mouse::Mouse(const sf::Vector2f position, const float size,
	sf::Texture* frontTexture, 
	sf::Texture* leftTexture, 
	sf::Texture* backTexture, 
	sf::Texture* rightTexture)
	: MovingObject(position, size, 
		frontTexture, leftTexture, backTexture, rightTexture), 
	m_lives(3) ,m_score(0), m_keys(0), m_startingPosition(position), m_collision(NoCollision),
	m_startingLives(m_lives), m_startingScore(m_score), m_startingKeys(m_keys)
{
	this->setSpeed(250.0f);
	m_sprite.scale(0.85f, 0.85f);	// for fiting through wall openings
}

int Mouse::getLives() const
{
	return m_lives;
}
int Mouse::getKeys() const
{
	return m_keys;
}
int Mouse::getScore() const
{
	return m_score;
}

void Mouse::reduceLifeCount()
{
	m_lives--;
	if (m_lives > 0) {
		m_sprite.setPosition(m_startingPosition);
	}
	else {
		this->eliminate();
	}
}
void Mouse::increaseScore(const int amount)
{
	m_score += amount;
}

void Mouse::increaseKeys()
{
	m_keys++;
}

void Mouse::increaseLife() {
	if (getLives() < 3) {
		m_lives++;
	}
}

bool Mouse::useKey()
{
	if (m_keys > 0) {
		m_keys--;
		return true;
	}
	return false;
}

void Mouse::reload(sf::Vector2f position, float size)
{
	m_startingPosition = position;
	m_sprite.setPosition(position);
	m_sprite.setScale(size, size);
	m_sprite.scale(0.85f, 0.85f);
	this->switchTexture(0);
}

void Mouse::setReset()
{
	m_startingLives = m_lives;
	m_startingKeys  = m_keys;
	m_startingScore = m_score;
}

void Mouse::reset()
{
	m_sprite.setPosition(m_startingPosition);
	m_lives = m_startingLives;
	m_keys  = m_startingKeys;
	m_score = m_startingScore;
}

CollisionType Mouse::getCollisionType()
{
	CollisionType temp = m_collision;
	m_collision = NoCollision;
	return temp;
}

void Mouse::handleCollision(GameObject& otherObject)
{
	otherObject.handleCollision(*this);
}

void Mouse::handleCollision(Wall&)
{
	this->setToLastPosition();
}

void Mouse::handleCollision(Cat&)
{
	if (m_lives > 0) {
		this->reduceLifeCount();
		m_collision = LoseLife;
	}
}

void Mouse::handleCollision(Key&)
{
	m_collision = PickUpKey;
}

void Mouse::handleCollision(Cheese&)
{
	m_collision = PickUpCheese;
}

void Mouse::handleCollision(LifeGift&)
{
	increaseLife();
	m_collision = PickUpLife;
}

void Mouse::handleCollision(TimeGift&)
{
	m_collision = PickUpTime;
}

void Mouse::handleCollision(FreezeGift&)
{
	m_collision = PickUpFreeze;
}

void Mouse::handleCollision(EnemyRemoveGift&)
{
	m_collision = PickUpEnemyRemove;
}

void Mouse::handleCollision(Door&)
{
	m_collision = OpenDoor;
}