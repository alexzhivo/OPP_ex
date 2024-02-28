#pragma once

#include "GameObject.h"

class StaticObject : public GameObject {
public:
	StaticObject(const sf::Vector2f position, const float size, sf::Texture* texture);
	virtual ~StaticObject() = default;

	bool isExisting() const;
	void remove();

	virtual void handleCollision(GameObject&) {};
	//virtual void handleCollision(Mouse& otherObject) = 0;
	//virtual void handleCollision(Cat& otherObject) = 0;
	virtual void handleCollision(Cheese&) {};
	virtual void handleCollision(Wall&) {};
	virtual void handleCollision(Key&) {};
	virtual void handleCollision(Door&) {};
	virtual void handleCollision(Gift&) {};
	virtual void handleCollision(LifeGift&) {};
	virtual void handleCollision(TimeGift&) {};
	virtual void handleCollision(FreezeGift&) {};
	virtual void handleCollision(EnemyRemoveGift&) {};
private:
	bool m_exists;
};