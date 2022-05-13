#include"Player.h"

Player::Player(const sf::Vector2f& positionStart, const bool& faceRightStart)
	: animation("Hero/hero", sf::Vector2u(8,15), 0.1f) {
	this->positionStart = positionStart;
	this->faceRightStart = faceRightStart;
	setSize(sf::Vector2f(40.0f, _SIZE_));
	setOrigin(getSize() / 2.0f);
	setPosition(positionStart);
	collider = new Collider(*this);
	body.setTexture(animation.getTexture());
	body.setSize(sf::Vector2f(_SIZE_, _SIZE_));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(getPosition());
	animation.currentFrame = sf::Vector2u(7, 0);
	_Attack.width = animation.width;
	_Attack.height = animation.height;
	_Attack.top = 14 * animation.height;
	face_Right = faceRightStart;
}
Player::~Player() {
	if (collider != NULL) {
		delete collider;
	}
	if (_Attack.collider != nullptr) {
		delete _Attack.collider;
	}
	for (auto& _shadow : shadow) {
		delete _shadow;
	}
}
void Player::Update(const float& deltaTime) {
	oldPosition = getPosition();
	body.setPosition(getPosition());
	if (moveQuick > 0) {
		moveQuick--;
		move(20.0f * (face_Right ? 1 : -1), 0.0f);
		body.setPosition(getPosition());
		createrShadow();
	}
	if (canJump) velocity.y = 0;
	velocity.x = 0;
	if (moveQuick == false) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) )
			velocity.x += speed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) )
			velocity.x -= speed;
		if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && canJump) ) {
			velocity.y = -sqrt(2.0f * 981.0f * jumpHeight);
			canJump = false;
			if (DATA->getAllowSound() == true) {
				soundJump->play();
			}
		}
		if (_Attack.Check == false) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
				_Attack.Check = true;
				velocity = sf::Vector2f(0.0f, 0.0f);
				if (DATA->getAllowSound()) {
					hit->play();
				}
			}
		}
	}
	if (canJump == false && moveQuick == false)
		velocity.y += 981.0f * deltaTime;
	if (timeClickS >= 0.0f) {
		timeClickS -= deltaTime;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ) && timeClickS <= 0.0f && moveQuick == 0 && _Attack.Check == false) {
		moveQuick = 8;
		timeClickS = 1.0f;
		velocity = sf::Vector2f(0.0f, 0.0f);
		if (DATA->getAllowSound()) {
			hit->play();
		}
	}
	limitPosition();
	updateAnimation(deltaTime);
	updateShadow(deltaTime);
	canJump = false;
	pushStone = false;
	animation.update(0.0f, face_Right);
	body.setTextureRect(animation);
	if ( !start && !_Attack.Check && !moveQuick && !end ) {
		move(velocity * deltaTime);
		body.setPosition(getPosition());
	}
}
void Player::Render(sf::RenderWindow* window) {
	for (auto& _shadow : shadow) {
		_shadow->Render(window);
	}
	window->draw(body);
	if (_Attack.Check)
	{
		_Attack.Render(window);
	}
}
Collider* Player::getCollider() {
	return collider;
}
Collider* Player::getColliderAttack() {
	return _Attack.collider;
}
void Player::createrShadow() {
	if (moveQuick & 1) {
		Shadow* tmp = new Shadow(true);
		if (face_Right == false) tmp->scale(-1.0f, 1.0f);
		tmp->setPosition(oldPosition);
		shadow.push_back(tmp);
	}
	else {
		Shadow* tmp = new Shadow(false);
		if (face_Right == false) tmp->scale(-1.0f, 1.0f);
		tmp->setPosition(oldPosition - sf::Vector2f(10.0f, 0.0f));
		shadow.push_back(tmp);
	}
}
void Player::updateShadow(const float& deltaTime) {
	while (!shadow.empty() && shadow.front()->die == true) {
		delete shadow.front();
		shadow.pop_front();
	}
	for (auto& _shadow : shadow) {
		_shadow->Update(deltaTime);
	}
}
void Player::updateAnimation(const float& deltaTime) {
	if (updateStart(deltaTime)) {
		return;
	}
	if (updateEnd(deltaTime)) {
		return;
	}
	if (updateWinGame(deltaTime)) {
		return;
	}
	if (updatePushStone(deltaTime)) {
		return;
	}
	if (updateMoveQuick(deltaTime)) {
		return;
	}
	if (updateAttack(deltaTime)) {
		return;
	}
	updateMove(deltaTime);
}
bool Player::updateMoveQuick(const float& deltaTime) {
	if (moveQuick == false) {
		return false;
	}
	animation.currentFrame = sf::Vector2u(3, 8);
	if (velocity.x > 0) face_Right = true;
	if (velocity.x < 0) face_Right = false;
	animation.update(0.0f, face_Right);
	return moveQuick;
}
bool Player::updateStart(const float& deltaTime) {
	if (start == false) {
		return false;
	}
	animation.currentTime += deltaTime;
	if (animation.currentTime >= animation.getSwichTime()) {
		animation.currentTime -= animation.getSwichTime();
		if (animation.currentFrame.y != 0) {
			animation.currentFrame = sf::Vector2u(7, 0);
		}
		else {
			animation.currentFrame.x--;
			if (animation.currentFrame.x == 0) {
				start = false;
			}
		}
	}
	return start;
}
bool Player::updateEnd(const float& deltaTime) {
	if (end == false) {
		return false;
	}
	if (animation.update(deltaTime, Vector2u(7, 0), face_Right)) {
		deletePlayer = true;
	}

	if (deletePlayer == true && HS->heart > 0) {
		Reset();
	}
	return !deletePlayer;
}
bool Player::updateAttack(const float& deltaTime) {
	if (face_Right)
		_Attack.setPosition(getPosition() + sf::Vector2f(_SIZE_, 0.0f));
	else
		_Attack.setPosition(getPosition() - sf::Vector2f(_SIZE_, 0.0f));

	if (_Attack.Check == false) {
		return false;
	}
	if (animation.update(deltaTime, Vector2u(4, 3), face_Right)) {
		_Attack.Check = false;
	}
	_Attack.Update(animation.currentFrame.x, face_Right);
	return _Attack.Check;
}
bool Player::updateWinGame(const float& deltaTime) {
	if (wingame == false) {
		return false;
	}
	if (animation.update(deltaTime, Vector2u(7, 0), face_Right)) {
		deletePlayer = true;
	}
	return !deletePlayer;
}
void Player::updateMove(const float& deltaTime) {
	if (velocity.x == 0.0f) {
		if (canJump) {
			animation.update(deltaTime, Vector2u(4, 5), face_Right);
		}
		else {
			if (velocity.y < 0) {
				animation.update(deltaTime, Vector2u(3, 7), face_Right);
			}
			else {
				animation.update(deltaTime, Vector2u(3, 6), face_Right);
			}
		}
	}
	else {
		if (velocity.x > 0.0f) face_Right = true;
		else face_Right = false;

		if (canJump) {
			animation.update(deltaTime, Vector2u(6, 1), face_Right);
		}	
		else {
			if (velocity.y < 0) {
				animation.update(deltaTime, Vector2u(3, 7), face_Right);
			}
			else {
				animation.update(deltaTime, Vector2u(3, 6), face_Right);
			}	
		}	
	}
		
}
bool Player::updatePushStone(const float& deltaTime) {
	if (pushStone == true) {
		animation.update(deltaTime, sf::Vector2u(6, 2), face_Right);
	}
	return pushStone;
}
void Player::limitPosition() {
	if (getPosition().x - getSize().x / 2 < 0) {
		setPosition(0 + getSize().x / 2, getPosition().y);
	}
	if (getPosition().x + getSize().x / 2 > screenWidth) {
		setPosition(screenWidth - getSize().x / 2, getPosition().y);
	}
	if (getPosition().y > screenHeight + 100.0f) {
		end = true;
	}
}
void Player::Reset() {
	animation.currentFrame = sf::Vector2u(7, 0);
	start = true;
	end = false;
	deletePlayer = false;
	canJump = false;
	setPosition(positionStart);
	face_Right = faceRightStart;
	HS->heart--;
}
