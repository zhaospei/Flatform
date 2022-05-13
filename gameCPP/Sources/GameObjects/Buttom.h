#pragma once
#include"Animation.h"
#include"../GameConfig.h"

class Buttom : public sf::RectangleShape {
public:
	Buttom(const sf::Vector2f& position);
	~Buttom();
	void Update();
	void Render(sf::RenderWindow* window);
	int checkCollider(Collider* other, const float& deltaTime);
	Collider* getCollider();
	bool getPressed();
	void setPressed(const bool& set);
private:
	Animation* animation = nullptr;
	Collider* collider = nullptr;
	bool pressed;
};

