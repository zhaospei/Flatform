#include "ExitDoor.h"

ExitDoor::ExitDoor(const sf::Vector2f& position) {
	texture = DATA->getTexture("ExitDoor/door");
	setSize(sf::Vector2f(_SIZE_ * 1.5, _SIZE_ * 1.5));
	setOrigin(getSize() / 2.0f);
	setPosition(position);
	setTexture(texture);
	collider = new Collider(*this);
}
ExitDoor::~ExitDoor() {
	if (collider != nullptr)
		delete collider;
}
void ExitDoor::Render(sf::RenderWindow* window) {
	window->draw(*this);
}
Collider* ExitDoor::getCollider() {
	return collider;
}
