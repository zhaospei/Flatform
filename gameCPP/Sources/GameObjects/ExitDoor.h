#pragma once
#include"../GameConfig.h"

class ExitDoor : public sf::RectangleShape
{
public:
	ExitDoor(const sf::Vector2f& position);
	~ExitDoor();
	void Render(sf::RenderWindow* window);
	Collider* getCollider();
private:
	sf::Texture* texture = nullptr;
	Collider* collider = nullptr;
};

