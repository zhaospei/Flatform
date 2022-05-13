#pragma once
#include"../GameConfig.h"

class Stone {
public:
	Stone(const sf::Vector2f& position);
	~Stone();

	void Render(sf::RenderWindow* window);
	void Update(const float& deltaTime);

	Collider *getCollider();

	bool can_Drop;
	sf::RectangleShape body;
private:
	void limitPosition();
	sf::Vector2f velocity;
	sf::Texture* texture;
	Collider* collider = nullptr;
};

