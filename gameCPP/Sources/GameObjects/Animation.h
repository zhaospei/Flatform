#pragma once
#include"../GameConfig.h"

class Animation : public sf::IntRect {
public:
	Animation(const std::string& name, const sf::Vector2u& frameCount, const float& swichTime);
	~Animation();
	bool update(const float& deltaTime, const sf::Vector2u& frammeLimit, const bool& faceRight);
	bool update(const float& deltaTime, const bool& faceRight);
	bool update(const float& deltaTime, const sf::Vector2u frameLimit);
	bool update(const float& deltaTime);
	void update();

	float getSwichTime();
	void setSwichTime(const float& switchTime);

	Texture* getTexture();
	void setTexture(const string& name);

	sf::Vector2u getFrameCount();
	sf::Vector2u currentFrame;
	float currentTime;
private:
	void update(const bool& faceRight);
	sf::Texture* texture;
	sf::Vector2u frameCount;
	float switchTime;
};

