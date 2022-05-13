#include"Ground.h"

Ground::Ground() {
	collider = nullptr;
	texture = nullptr;
}
void Ground::setGround(const string& name, const float& x, const float& y, const int& data) {
	texture = DATA->getTexture(name);
	setSize(sf::Vector2f(_SIZE_, _SIZE_));
	setOrigin(getSize() / 2.0f);
	setPosition(sf::Vector2f(x, y) + getSize() / 2.0f);
	setTexture(texture);
	this->data = data;
	if (data > 0) {
		collider = new Collider(*this);
	}
}
Collider* Ground::getCollider() {
	return collider;
}
Ground::~Ground() {
	if (collider != nullptr)
		delete collider;
	texture = nullptr;
}
void Ground::Render(sf::RenderWindow *window) {
	window->draw(*this);
}
