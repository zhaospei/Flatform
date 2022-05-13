#pragma once
#include"../GameConfig.h"
#include"Animation.h"

struct Shadow : public RectangleShape {
	float timeDie = 0.4f;
	bool die = false;
	Shadow(const bool& input) {
		setTexture(DATA->getTexture("Hero/shadow" + to_string(input)));
		setSize(sf::Vector2f(_SIZE_, _SIZE_));
		setOrigin(getSize() / 2.0f);
	}
	void Update(const float& deltaTime) {
		timeDie -= deltaTime;
		if (timeDie < 0.0f)
			die = true;
	}
	void Render(sf::RenderWindow* window) {
		if (die == false) 
		{
			window->draw(*this);
		}
	}
};
struct Attack : public RectangleShape, public IntRect
{
	Collider* collider = nullptr;
	bool Check = false;
	Attack() {
		setSize(sf::Vector2f(_SIZE_, _SIZE_));
		setOrigin(getSize() / 2.0f);
		setTexture(DATA->getTexture("Hero/hero"));
		setTextureRect(*this);
		collider = new Collider(*this);
	}
	void Update(int currentFrame,bool faceRight) {
		if (faceRight) {
			left = currentFrame * abs(width);
			width = abs(width);
		}
		else {
			left = (currentFrame + 1) * abs(width);
			width = -abs(width);
		}
		setTextureRect(*this);
	}
	void Render(sf::RenderWindow* window) {
		window->draw(*this);
	}
};
class Player : public sf::RectangleShape {
public:
	Player(const sf::Vector2f& positionStart, const bool& faceRightStart);
	~Player();
	void Update(const float& deltaTime);
	void Render(sf::RenderWindow* window);
	Collider* getCollider();
	Collider* getColliderAttack();
	bool face_Right = false;
private:
	sf::RectangleShape body;
	Collider* collider = nullptr;
	Animation animation;
	float speed = 190.0f;
	float timeClickS = 0.0f;
	int moveQuick = 0; 
	sf::Vector2f oldPosition;
	list<Shadow*> shadow;
	sf::Vector2f positionStart;
	bool faceRightStart;
public:
	float jumpHeight = 180.0f;
	sf::Vector2f velocity = sf::Vector2f(0.0f, 0.0f);
	bool start = true; 
	bool end = false;
	bool deletePlayer = false;
	bool canJump = false; 
	bool wingame = false;
	bool pushStone = false;
	Attack _Attack;
private:
	void createrShadow();
	void updateShadow(const float& deltaTime);
	void updateAnimation(const float& deltaTime);
	bool updateMoveQuick(const float& deltaTime);
	bool updateStart(const float& deltaTime);
	bool updateEnd(const float& deltaTime);
	bool updateAttack(const float& deltaTime);
	bool updateWinGame(const float& deltaTime);
	bool updatePushStone(const float& deltaTime);
	void updateMove(const float& deltaTime);
	void limitPosition();
	void Reset();
	sf::Sound* soundJump = DATA->getSound("jump");
	sf::Sound* hit = DATA->getSound("hit");
};

