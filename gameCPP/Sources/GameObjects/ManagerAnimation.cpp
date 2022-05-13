#include"ManagerAnimation.h"

void ManagerAnimation::Add(Animation* animation, const sf::Vector2f& position, const sf::Vector2f& size) {
	sf::RectangleShape* rect = new sf::RectangleShape;
	rect->setSize(size);
	rect->setPosition(position);
	rect->setTexture(animation->getTexture());
	arrAnimation.push_back({ animation,rect });
}
void ManagerAnimation::Update(const float& deltaTime) {
	for (auto &i : arrAnimation) {
		updateSingle(i, deltaTime);
	}
}
void ManagerAnimation::Render(sf::RenderWindow* window) {
	for (auto& i : arrAnimation) {
		window->draw(*i.second);
	}
}
void ManagerAnimation::updateSingle(pair<Animation*, sf::RectangleShape*>& animation, const float& deltaTime) {
	animation.first->update(deltaTime);
	animation.second->setTextureRect(*animation.first);
}
ManagerAnimation::ManagerAnimation() {

}
ManagerAnimation::~ManagerAnimation() {
	while( !arrAnimation.empty() ) {
		delete arrAnimation.front().first;
		delete arrAnimation.front().second;
		arrAnimation.pop_front();
	}
}
