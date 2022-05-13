#include "Door.h"

Door::Door(const sf::Vector2f &position)
{
	animation = new Animation("Door/strange_door", sf::Vector2u(14, 2), 0.15f);
	setTexture(animation->getTexture());
	setSize(sf::Vector2f(_SIZE_, _SIZE_ * 3));
	setOrigin(getSize() / 2.0f);
	setPosition(position);
	collider = new Collider(*this);
	open = false;
}

Door::~Door() 
{
	if (collider != nullptr) 
		delete collider;
	if (animation != nullptr) 
		delete animation;
}

void Door::Update(const float &deltaTime)
{
	animation->currentTime += deltaTime;
	if (animation->currentTime >= animation->getSwichTime()) {
		animation->currentTime -= animation->getSwichTime();
		if (open == true) {
			if (animation->currentFrame.y == 1) {
				if (animation->currentFrame.x < animation->getFrameCount().x)
					animation->currentFrame.x++;
			}
			else {
				animation->currentFrame = sf::Vector2u(0, 1);
			}
		}
		else {
			if (animation->currentFrame.y == 1) {
				if (animation->currentFrame.x >= 1)
					animation->currentFrame.x--;
				if (animation->currentFrame.x == 0) {
					animation->currentFrame.y = 0;
				}
			}
			else {
				animation->currentFrame.x++;
				if (animation->currentFrame.x >= 10)
					animation->currentFrame.x = 0;
			}
		}
	}
	animation->update(0.0f);
	setTextureRect(*animation);
}

void Door::Render(sf::RenderWindow* window)
{
	window->draw(*this);
}

Collider* Door::getCollider()
{
    return collider;
}

bool Door::checkOpen()
{
	return open;
}

void Door::setOpen(const bool& set)
{
	open = set;
}

