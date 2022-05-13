#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

enum collider {
	top = 8, right = 6, left = 4, down = 2,
	_top = -8, _right = -6, _left = -4, _down = -2, // push = 1.0f 
};
class Collider {
public:
	Collider(sf::RectangleShape& body);
	Collider(sf::RectangleShape* body);
	~Collider() {
		// body is not allowed to delete because it belongs to another class 
	}
	void Move(const float& x, const float& y);
	int checkCollision(Collider* other, float push);
	int checkCollision(Collider* other);
	sf::Vector2f getPosition();
	sf::Vector2f getHaftSize();
public:
	sf::RectangleShape *body;
};

