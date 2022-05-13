#pragma once
#include"Animation.h"
#include"Collider.h"

class MushRoom : public sf::RectangleShape
{
public:
	MushRoom(const sf::Vector2f& position);
	~MushRoom();
	void Update(const float& deltaTime);
	void Render(sf::RenderWindow* window);
	Collider* getCollider();
private:
	Animation* animation = nullptr;
	Collider* collider = nullptr;
};

