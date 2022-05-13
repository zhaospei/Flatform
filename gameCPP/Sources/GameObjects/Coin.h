#pragma once
#include"Animation.h"
#include"../GameConfig.h"

class Coin : public sf::RectangleShape {
public:
	Coin(const sf::Vector2f& position);
	~Coin();
	void Update(const float& deltaTime);
	void Render(sf::RenderWindow* window);
	Collider* getCollider();
	bool delete_Coin;
	int eat_Coin;
private:
	Animation* animation = nullptr;
	Collider* collider = nullptr;
	sf::Sound pickcoin;
};

