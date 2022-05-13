#include "MushRoom.h"

MushRoom::MushRoom(const sf::Vector2f& position)
{
	animation = new Animation("MushRoom/mushroom", sf::Vector2u(6, 1), 0.15f);
	setSize(sf::Vector2f(_SIZE_, _SIZE_));
	setOrigin(getSize() / 2.0f);
	setPosition(position);
	setTexture(animation->getTexture());
	collider = new Collider(*this);
}

MushRoom::~MushRoom()
{
	if (collider != nullptr) {
		delete collider;
	}
	if (animation != nullptr) {
		delete animation;
	}
}

void MushRoom::Update(const float& deltaTime)
{
	animation->update(deltaTime);
	setTextureRect(*animation);
}

void MushRoom::Render(sf::RenderWindow* window)
{
	window->draw(*this);
}

Collider* MushRoom::getCollider()
{
	return collider;
}
