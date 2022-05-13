#include "Buttom.h"

Buttom::Buttom(const sf::Vector2f &position) {
	animation = new Animation("Buttom/buttom_pressed", sf::Vector2u(2, 1), 0.1f);
	setTexture(animation->getTexture());
	setSize(sf::Vector2f(50.0f, 12.5f));
	setOrigin(getSize() / 2.0f);
	setPosition(position);
	collider = new Collider(*this);
	pressed = false;
}
Buttom::~Buttom() {
	if (collider != nullptr)
		delete collider;
	if (animation != nullptr)
		delete animation;
}
void Buttom::Update() {
	if ( pressed ) animation->currentFrame.x = 1;
	else animation->currentFrame.x = 0;
	animation->update();
	setTextureRect(*animation);
}
void Buttom::Render(sf::RenderWindow* window) {
	window->draw(*this);
}
int Buttom::checkCollider(Collider* other,const float& deltaTime) {
	int Check = collider->checkCollision(other, 1.0f);
	if (Check != 0 ) {
		pressed = true;
	}
	if ( Check == collider::_left || Check == collider::_right ) {
		other->Move(1.0f * deltaTime, 0.0f);
		other->body->setPosition(sf::Vector2f(other->getPosition().x, getPosition().y - getSize().y / 2 - other->getHaftSize().y));
	}
	return Check;
}
Collider* Buttom::getCollider() {
	return collider;
}
bool Buttom::getPressed() {
	return pressed;
}
void Buttom::setPressed(const bool& set) {
	pressed = set;
}


