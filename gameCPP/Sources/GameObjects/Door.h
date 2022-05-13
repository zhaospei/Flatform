#pragma once
#include"Animation.h"
#include"Collider.h"

class Door : public sf::RectangleShape
{
public:
	Door(const sf::Vector2f &position);
	~Door();
	void Update(const float &deltaTime);
	void Render(sf::RenderWindow *window);
	Collider* getCollider();
	bool checkOpen();
	void setOpen(const bool& set);
private:
	Animation* animation = nullptr;
	Collider* collider = nullptr;
	bool open;
};

