#include "Enemies.h"

Enemies::Enemies() {
	animation = nullptr;
	collider = nullptr;
	speed = 0;
	faceRight = 0;
	_Move = 0;
	check_Die = 0;
	delete_Bot = 0;
	type = 0;
}
Enemies::Enemies(int type, const sf::Vector2f& start, const sf::Vector2f& end,const sf::Vector2f& position) {
	collider = new Collider(*this);
	this->type = type;
	_Move = 0;
	faceRight = true;
	delete_Bot = false;
	check_Die = 0;
	speed = 50.0f;
	if (type == 1) {
		animation = new Animation("Enemies/worm", sf::Vector2u(6, 2), 0.13f);
		setSize(sf::Vector2f(_SIZE_, _SIZE_ * 0.5f));
		setOrigin(getSize() / 2.0f);
		setPosition(position);
		frameLimit = sf::Vector2u(6, 0);
	}
	else if (type == 2) {
		animation = new Animation("Enemies/slime_spritesheet", sf::Vector2u(15, 5), 0.13f);
		setSize(sf::Vector2f(50.0f, 50.0f));
		setOrigin(getSize() / 2.0f);
		setPosition(position);
		frameLimit = sf::Vector2u(15, 1);
	}
	else if (type == 3) {
		animation = new Animation("Enemies/mushroom_spritesheet", sf::Vector2u(8, 4), 0.13f);
		setSize(sf::Vector2f(50.0f, 50.0f));
		setOrigin(getSize() / 2.0f);
		setPosition(position);
		frameLimit = sf::Vector2u(8, 0);
	}
	setTexture(animation->getTexture());
	this->start = start;
	this->end = end;
	if (start.x < end.x) _Move = 1;
	else {
		_Move = -1;
		swap(this->start, this->end);
	}
}
Enemies::~Enemies() {
	if (collider != nullptr) {
		delete collider;
	}
	if (animation != nullptr) {
		delete animation;
	}
}
void Enemies::Update(const float& deltaTime) {
	if (delete_Bot) {
		return;
	}
	if (check_Die == 1) {
		check_Die++;
		if (type == 1) {
			frameLimit = sf::Vector2u(6, 1);
			animation->currentFrame = sf::Vector2u(0, 1);
		}
		else if (type == 2) {
			frameLimit = sf::Vector2u(6, 2);
			animation->currentFrame = sf::Vector2u(0, 2);
		}
		else if (type == 3) {
			frameLimit = sf::Vector2u(8, 2);
			animation->currentFrame = sf::Vector2u(0, 2);
		}
	}
	if (_Move == 1) {
		if (type == 2) faceRight = false;
		else faceRight = true;
	}
	else {
		if (type == 2)faceRight = true;
		else faceRight = false;
	}
	if (_Move == 1) {
		if (getPosition().x > end.x) {
			setPosition(end.x, getPosition().y);
			_Move = -1;
		}
	}
	else {
		if (getPosition().x < start.x) {
			setPosition(start.x, getPosition().y);
			_Move = 1;
		}
	}
	if (animation->update(deltaTime, frameLimit, faceRight) && check_Die) {
		delete_Bot = true;
	}
	setTextureRect(*animation);
	move(_Move * speed * deltaTime, 0.0f);
}
void Enemies::Render(sf::RenderWindow* window) {
	window->draw(*this);
}
Collider* Enemies::getCollider() {
	return collider;
}
