#include "Stone.h"

Stone::Stone(const sf::Vector2f& position) {
	texture = DATA->getTexture("Stone/stone");
	body.setSize(sf::Vector2f(_SIZE_,_SIZE_));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setTexture(texture);
	collider = new Collider(body);
	can_Drop = true;
}
Stone::~Stone() {
	if (collider != nullptr)
		delete collider;
	texture = nullptr;
}
void Stone::Render(sf::RenderWindow* window) {
	window->draw(body);
}
void Stone::Update(const float& deltaTime) {
	if (can_Drop) velocity.y += 10.0f * deltaTime;
	else velocity.y = 0;
	body.move(velocity);
	can_Drop = true;
	limitPosition();
}
Collider* Stone::getCollider() {
	return collider;
}
void Stone::limitPosition() {
	if (body.getPosition().x - body.getSize().x / 2 < 0) {
		body.setPosition(0 + body.getSize().x / 2, body.getPosition().y);
	}
	if (body.getPosition().x + body.getSize().x / 2 > screenWidth) {
		body.setPosition(screenWidth - body.getSize().x / 2, body.getPosition().y);
	}
}


