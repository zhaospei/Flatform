#pragma once
#include"Animation.h"
#include"../GameConfig.h"

class Enemies : public sf::RectangleShape
{	/* 
	1: worm
	2: slime
	3: mushroom
	*/
public:
	Enemies();
	Enemies(int type, const sf::Vector2f& start, const sf::Vector2f& end,const sf::Vector2f& position);
	~Enemies();
	void Update(const float& deltaTime);
	void Render(sf::RenderWindow* window);
	Collider* getCollider();
	int check_Die;
	bool delete_Bot;
protected:
	Animation* animation = nullptr;
	Collider* collider = nullptr;
	sf::Vector2f start, end;
	sf::Vector2u frameLimit = sf::Vector2u(0, 0);
public:
	float speed;
	bool faceRight;
	int _Move;
	int type;
};

