#pragma once
#include"../GameConfig.h"
#include"Animation.h"
#include<list>

class ManagerAnimation
{
public:
	void Add(Animation* animation, const sf::Vector2f& position, const sf::Vector2f& size);
	void Update(const float& deltaTime);
	void Render(sf::RenderWindow* window);
	ManagerAnimation();
	~ManagerAnimation();
private:
	list < pair<Animation*, sf::RectangleShape*>> arrAnimation;
	void updateSingle(pair<Animation*, sf::RectangleShape*>& animation, const float& deltaTime);
};

