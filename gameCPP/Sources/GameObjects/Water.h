#pragma once
#include"Animation.h"
#include"Collider.h"

class Water : public sf::RectangleShape
{
public:
	Water(const sf::Vector2f& position) {
		texture = DATA->getTexture("BackGround/fg_0");
		setSize(sf::Vector2f(_SIZE_, _SIZE_));
		setOrigin(getSize() / 2.0f);
		setPosition(position);
		setTexture(texture);
		collider = new Collider(*this);
	}
	~Water() {
		if (collider != nullptr) {
			delete collider;
		}
		texture = nullptr;
	}
	void Render(sf::RenderWindow* window) {
		window->draw(*this);
	}
	Collider* getCollider() {
		return collider;
	}
private:
	Collider* collider = nullptr;
	sf::Texture* texture;
};

