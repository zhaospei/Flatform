#pragma once
#include"Player.h"
#include"Spikes.h"

class Ground : public sf::RectangleShape {
public:
	Ground();
	~Ground();
	void Render(sf::RenderWindow *window);
	void setGround(const string& image, const float& x, const float& y, const int& data);
	Collider* getCollider();
private:
	int data = 0;
	Collider* collider = nullptr;
	sf::Texture* texture = nullptr;
};
