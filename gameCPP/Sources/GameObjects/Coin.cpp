#include"Coin.h"

Coin::Coin(const sf::Vector2f& position) {
	animation = new Animation("Coin/coin1", sf::Vector2u(6, 1), 0.2f);
	setTexture(animation->getTexture());
	setSize(sf::Vector2f(27.0f, 27.0f));
	setOrigin(getSize() / 2.0f);
	setPosition(position);
	collider = new Collider(*this);
	eat_Coin = false;
	delete_Coin = false;
	pickcoin = *DATA->getSound("pickcoin");
}
Coin::~Coin() {
	if (animation != nullptr) {
		delete animation;
	}
	if (collider != nullptr) {
		delete collider;
	}
}
void Coin::Update(const float& deltaTime) {
	if (delete_Coin)
		return;
	if (eat_Coin == 1) {
		animation->setTexture("Coin/coin2");
		setTexture(animation->getTexture());
		eat_Coin++;
		animation->currentFrame.x = 0;
		animation->setSwichTime(0.1f);
		HS->pickCoin++;
		HS->coinReset++;
		if (DATA->getAllowSound()) {
			pickcoin.play();
		}
	}
	if (animation->update(deltaTime) && eat_Coin) {
		delete_Coin = true;
	}
	setTextureRect(*animation);
}
void Coin::Render(sf::RenderWindow* window) {
	window->draw(*this);
}
Collider* Coin::getCollider() {
	return collider;
}
