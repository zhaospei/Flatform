#pragma once
#include"Animation.h"
#include"Collider.h"
#include"Player.h"

class Spikes : public sf::RectangleShape
{
public:
	Spikes(const sf::Vector2f& position, bool direction);
	~Spikes();
	void Update(const float& deltaTime);
	void Render(sf::RenderWindow* window);
	Collider* getCollider();
	bool checkPlayer(Player* player);
	sf::Vector2f velocity = sf::Vector2f(0.0f, 0.0f);
	bool can_Drop = false;
	bool touch_Gound = false;
private:
	bool direction; // 1 = top .  0 = down
	Animation* animtion = nullptr;
	Collider* collider = nullptr;
	bool checkTop(Player* player);
	bool checkDown(Player* player);
};

