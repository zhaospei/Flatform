#pragma once
#include"Animation.h"
#include<SFML/Graphics.hpp>

class Box : public RectangleShape
{
public:
	Animation* animation = nullptr;
	Collider* collider = nullptr;
	sf::Vector2u frameLimit;
	bool faceRight;
	int loot = 0;
	sf::Sound pickcoin;

	Box(sf::Vector2f position,bool faceRight) {
		animation = new Animation("Box/loot_box_anim_strip_12", sf::Vector2u(12, 1), 0.1f);
		setSize(sf::Vector2f(16 * 3.0f, 10 * 3.0f));
		setOrigin(getSize() / 2.0f);
		setTexture(animation->getTexture());
		setPosition(position);
		this->faceRight = faceRight;
		animation->currentFrame = sf::Vector2u(0, 0);
		collider = new Collider(*this);
		frameLimit = sf::Vector2u(12, 0);
		pickcoin = *DATA->getSound("pickcoin");
	}
	void Update(const float& deltaTime) {
		if (loot == 1) {
			loot++;
			setTexture(DATA->getTexture("Box/loot_box_open"));
			frameLimit = sf::Vector2u(1, 0);
			HS->pickCoin += 5;
			HS->coinReset += 5;
			if (DATA->getAllowSound()) {
				pickcoin.play();
			}
		}
		animation->update(deltaTime, frameLimit,faceRight);
		setTextureRect(*animation);
	}
	void Render(sf::RenderWindow* window) {
		window->draw(*this);
	}
	~Box() {
		if(animation != nullptr)
			delete animation;
		if( collider != nullptr)
			delete collider;
	}
};

