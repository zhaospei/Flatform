#include"Animation.h"

Animation::Animation(const std::string& name, const sf::Vector2u& frameCount, const float& switchTime) 
{
	texture = DATA->getTexture(name);
	this->frameCount = frameCount;
	this->switchTime = switchTime;
	currentTime = 0.0f;
	currentFrame = sf::Vector2u(0, 0);
	width = texture->getSize().x / frameCount.x;
	height = texture->getSize().y / frameCount.y;
}

Animation::~Animation() 
{

}

bool Animation::update(const float& deltaTime,const sf::Vector2u& frammeLimit,const bool& faceRight)
{
	bool check = false;
	currentTime += deltaTime;
	if (currentTime >= switchTime) {
		currentTime -= switchTime;
		if (currentFrame.y != frammeLimit.y) {
			currentFrame = sf::Vector2u(0, frammeLimit.y);
		}
		else {
			currentFrame.x++;
			if (currentFrame.x >= frammeLimit.x ) {
				currentFrame.x = 0;
				check = true;
			}
		}
	}
	update(faceRight);
	return check;
}

bool Animation::update(const float& deltaTime, const bool& faceRight)
{
	return update(deltaTime, sf::Vector2u(frameCount.x, 0), faceRight);
}

bool Animation::update(const float& deltaTime, const sf::Vector2u frameLimit)
{
	return update(deltaTime, frameLimit, true);
}

bool Animation::update(const float& deltaTime)
{
	return update(deltaTime, true);
}

void Animation::update()
{
	update(true);
}

float Animation::getSwichTime()
{
	return switchTime;
}

void Animation::setSwichTime(const float& switchTime)
{
	this->switchTime = switchTime;
}

Texture* Animation::getTexture()
{
	return texture;
}

void Animation::setTexture(const string& name)
{
	texture = DATA->getTexture(name);
}

sf::Vector2u Animation::getFrameCount()
{
	return frameCount;
}

void Animation::update(const bool& faceRight)
{
	top = currentFrame.y * height;
	if (faceRight) {
		left = currentFrame.x * abs(width);
		width = abs(width);
	}
	else {
		left = (currentFrame.x + 1) * abs(width);
		width = -abs(width);
	}
}
